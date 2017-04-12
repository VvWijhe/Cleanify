//
// Created by jamie on 4/11/17.
//

#include "main_process.h"

using namespace std;

void systemControl::WaitForCmd::handle(shared_ptr<statemachine::Context> context, statemachine::event_t event) {
    context->setState(make_shared<Clean>());
}

void systemControl::Clean::handle(shared_ptr<statemachine::Context> context, statemachine::event_t event) {

}
