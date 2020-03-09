#include "StateMachine.hpp"

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
    log << "Add state function called";

    this->_isAdding = true;
    this->_isReplacing = isReplacing;

    this->_newState = std::move(newState);
}

void StateMachine::RemoveState()
{
    this->_isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
    if (this->_isRemoving && !this->_states.empty())
    {
        this->_states.pop();

        if (!this->_states.empty())
        {
            this->_states.top()->Resume();
        }

        this->_isRemoving = false;
    }

    if (this->_isAdding)
    {
        if (!this->_states.empty())
        {
            if (this->_isReplacing)
            {
                this->_states.pop();
                log << "State was added to the stack";
            }
            else
            {
                this->_states.top()->Pause();
            }
        }
        this->_states.push(std::move(this->_newState));
        this->_states.top()->Init();
        this->_isAdding = false;
    }
}

StateRef& StateMachine::GetActiveState()
{
    if (!this->_states.empty())
    {
        return this->_states.top();
    }
    else
    {
        return this->_states.top();
        log << "Stack is empty";
    }
}