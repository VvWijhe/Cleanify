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

        virtual void handle(std::shared_ptr<Context> context, event_t event) = 0;
    };

    class Context : public std::enable_shared_from_this<Context> {
    public:
        Context() {}

        void handleState(event_t event) {
            currentState_->handle(shared_from_this(), event);
        }

        void setState(std::shared_ptr<State> nextState) { currentState_ = nextState; }

        std::shared_ptr<State> getState() const { return currentState_; }

    private:
        event_t event_;
        std::shared_ptr<State> currentState_;
    };
}

#endif //ROCKET_STATEMACHINE_HPP
