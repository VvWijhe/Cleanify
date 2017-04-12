//
// Created by jamie on 4/10/17.
//

#ifndef ROCKET_STATEMACHINE_HPP
#define ROCKET_STATEMACHINE_HPP

#include <memory>

namespace statemachine {
    class Context;

    using event_t = unsigned int;
    static const auto nevent = static_cast<unsigned int>(-1);

    class State {
    public:
        virtual ~State() = default;

        virtual void handle(std::shared_ptr<Context> context) = 0;
    };

    class Context : public std::enable_shared_from_this<Context> {
    public:
        Context() {}

        int handleState(event_t event) {
            if(currentState_ == nullptr) return -1;

            currentState_->handle(shared_from_this());
            return 1;
        }

        void runAll() {
            while(handleState(event_) > 0);
        }

        void setNextState(std::shared_ptr<State> nextState) { currentState_ = nextState; }

        std::shared_ptr<State> getState() const { return currentState_; }

        void setEvent(event_t event) { event_ = event; }

        event_t getEvent() const { return event_; }

    private:
        event_t event_;
        std::shared_ptr<State> currentState_;
    };
}

#endif //ROCKET_STATEMACHINE_HPP
