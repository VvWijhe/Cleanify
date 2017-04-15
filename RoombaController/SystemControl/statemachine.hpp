//
// Created by jamie on 4/10/17.
//

#ifndef ROCKET_STATEMACHINE_HPP
#define ROCKET_STATEMACHINE_HPP

#include <memory>

namespace statemachine {
    class Context;

    using event_t = unsigned int;

    class State {
    public:
        virtual ~State() = default;

        virtual void handle(const std::shared_ptr<Context> &context) = 0;
    };

    class Context : public std::enable_shared_from_this<Context> {
    public:
        Context() : event_(0), currentState_(nullptr) {}

        int handleState(event_t event) {
            if(currentState_ == nullptr) return -1;

            currentState_->handle(shared_from_this());
            return 1;
        }

        void runAll() {
            while(handleState(event_) > 0);
        }

        void setState(const std::shared_ptr<State> &nextState) { currentState_ = nextState; }

        std::shared_ptr<State> getState() const { return currentState_; }

        void setEvent(event_t event) { event_ = event; }

        event_t getEvent() const { return event_; }

    private:
        std::shared_ptr<State> currentState_;
        event_t event_;
    };
}

#endif //ROCKET_STATEMACHINE_HPP
