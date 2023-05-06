#pragma once
#include "Humidifier.h"

class State;
class Context;
class Flipper;
class Ventelatiom;


class State
{
public:
    State() {}

    virtual bool execute(Context*) = 0;
};

class Context
{
private:
    State* state;
public:
    Context(State* state)
        : state(state) {}

    bool execute()
    {
        cout << "execute in <Context>" << endl;
        state->execute(this);
        return true;
    }

    void SetState(State* s)
    {
        delete state;
        state = s;
    }
    State* GetState()
    {
        return state;
    }

    ~Context()
    {
        delete state;
    }
};


class Flipper : public State
{
public:
    Flipper() : State() {}
    virtual bool execute(Context* state);
};
class Ventilation : public State
{
public:
    Ventilation() : State() {}
    virtual bool execute(Context* state);
};

bool Flipper::execute(Context* state)
{
    state->SetState(new Ventilation());
    return true;
}

bool Ventilation::execute(Context* state)
{
    state->SetState(new Flipper());
    return true;
}