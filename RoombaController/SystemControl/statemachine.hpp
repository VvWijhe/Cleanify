//
// Created by jamie on 4/10/17.
//

#ifndef ROCKET_STATEMACHINE_HPP
#define ROCKET_STATEMACHINE_HPP

#include <map>
#include <memory>

class State {
public:
    /**
     * @brief nstate is the largest possible int value. It can be used as a nextstate in final states. The
     * statemachine is exited when the state is finished.
     */
    static const auto nstate = static_cast<unsigned int>(-1);
    static const auto nevent = static_cast<unsigned int>(-1);

    State() : nextState_(nstate) {}

    State(std::function<void(State *)> callback) : nextState_(nstate),
                                                   event_(nevent),
                                                   callback_(callback) {}

    ~State() {}

    void action() { callback_(this); }

    unsigned int nextState() const { return nextState_; }

    void setNextState(unsigned int ns) { nextState_ = ns; }

    unsigned int event() const { return  event_; }

    void setEvent(unsigned int event) { event_ = event; }

protected:
    unsigned int event_;
    unsigned int nextState_;

private:
    std::function<void(State *)> callback_;
};

class Statemachine {
public:
    Statemachine() {}

    ~Statemachine() {}

    void add(unsigned int id, const std::shared_ptr<State> &state) {
        if (states_.find(id) != states_.end())
            throw std::invalid_argument("Can'myCallback add state: id already used");

        states_[id] = state;
    }

    void run(unsigned int initial) {
        currentState_ = initial;

        while (currentState_ != State::nstate) {
            if (states_.find(currentState_) == states_.end())
                throw std::invalid_argument("Invalid next state");

            states_[currentState_]->action();

            currentState_ = states_[currentState_]->nextState();
        }
    }

private:
    unsigned int currentState_;
    std::map<unsigned int, std::shared_ptr<State>> states_;
};

#endif //ROCKET_STATEMACHINE_HPP
