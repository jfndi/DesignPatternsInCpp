/*
 * The state pattern is a behavioral software design pattern that allows an object
 * to alter its behavior when its internal state changes. This pattern is close to 
 * the concept of finite-state machines. The state pattern can be interpreted as a
 * strategy pattern, which is able to switch a strategy through invocations of 
 * methods defined in the pattern's interface.
 * The state pattern is used in computer programming to encapsulate varying 
 * behavior for the same object, based on its internal state. This can be a 
 * cleaner way for an object to change its behavior at runtime without resorting
 * to conditional statements and thus improve maintainability. 
 */
#include <iostream>

using namespace std;

class State
{
public:
	virtual string getDescription() = 0;
	virtual State* getNextState() const = 0;
};

class PurchasedState : public State
{
	State* nextState{};
public:
	PurchasedState(State* nextState) : nextState(nextState) {}

	string getDescription() override
	{
		return "Current State: PURCHASED - Will be shipping soon.\n";
	}

	State* getNextState() const override
	{
		return nextState;
	}
};

class InTransitState : public State
{
	State* nextState{};
public:
	InTransitState(State* nextState) : nextState(nextState) {}

	string getDescription() override
	{
		return "Current State: IN TRANSIT - Your item is on its way.\n";
	}

	State* getNextState() const override
	{
		return nextState;
	}
};

class DeliveredState : public State
{
	State* nextState{};
public:
	DeliveredState(State* nextState) : nextState(nextState) {}

	string getDescription() override
	{
		return "Current State: DELIVERED - Your item has arrived.\n";
	}

	State* getNextState() const override
	{
		return nextState;
	}
};

class Purchase
{
	string productName;
	State* currentState;
public:
	Purchase(const string& productName, State* initialState) :
		productName(productName), currentState(initialState) {}

	string getDescription() const
	{
		string result;

		if (currentState)
			result = currentState->getDescription();
		else
			result = "No more states!\n";

		return result;
	}

	void goToNextState()
	{
		currentState = currentState->getNextState();
	}
};

int main()
{
	DeliveredState* deliveredState = new DeliveredState(nullptr);
	InTransitState* inTransitState = new InTransitState(deliveredState);
	PurchasedState* purchasedState = new PurchasedState(inTransitState);

	Purchase* purchase = new Purchase("Shoes", purchasedState);
	cout << purchase->getDescription();

	purchase->goToNextState();
	cout << purchase->getDescription();

	purchase->goToNextState();
	cout << purchase->getDescription();

	purchase->goToNextState();
	cout << purchase->getDescription();

	delete purchasedState;
	delete inTransitState;
	delete deliveredState;

	return 0;
}