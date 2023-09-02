#include <iostream>
/*
 * The factory design pattern is used when we have a superclass with multiple
 * sub-classes and based on input, we need to return one of the sub-class. This 
 * pattern takes out the responsibility of the instantiation of a class from the
 * client program to the factory class.
 */
using namespace std;

//
// Product from which the concrete products wil inherit from.
//
class Coffee
{
protected:
	char _type[15]{};

public:
	Coffee() {};

	const char* getType() const
	{
		return _type;
	}
};

//
// First concrete class.
//
class Expresso : public Coffee
{
public:
	Expresso() : Coffee()
	{
		strncpy_s(_type, "Expresso", sizeof(_type));

		cout << endl << "Making a cup of expresso." << endl;
		cout << "Grind and brew on scoop of expresso beans." << endl;
	}
};

//
// Second concrete class.
//
class Cappuccino : public Coffee
{
public:
	Cappuccino() : Coffee()
	{
		strncpy_s(_type, "Cappuccino", sizeof(_type));

		cout << endl << "Making a cup of cappuccino" << endl;
		cout << "Grind and brew one scoop of expresso beans." << endl;
		cout << "Heat and foam milk." << endl;
	}
};

//
// Coffee factory class.
//
class CoffeeMakerFactory
{
private:
	Coffee* _coffee{};

public:

	Coffee* getCoffee() const
	{
		int choice{};

		cout << "Select type of coffee to make: " << endl;
		cout << "1: Expresso" << endl;
		cout << "2: Cappuccino" << endl;
		cout << "Selection: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			return new Expresso;
		case 2:
			return new Cappuccino;
		default:
			cout << "Invalid Selection" << endl;
			return NULL;
		}
	}
};

int main()
{
	CoffeeMakerFactory coffeeMachine;

	Coffee* cup;

	cup = coffeeMachine.getCoffee();

	cout << endl << "You had asked for a(n): " << cup->getType() << endl;
}