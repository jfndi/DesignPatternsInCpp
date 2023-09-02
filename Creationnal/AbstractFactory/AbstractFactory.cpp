#include <iostream>

/*
 * The abstract factory pattern in software engineering is a design that provides
 * a way to create families of related objects without imposing their concrete 
 * classes, by encapsulating a group of individual factories that have a common
 * theme without specifying their concrete classes. 
 */

using namespace std;

//
// Door abstract class.
//
class Door
{
public:
	Door() {}

	virtual void open() = 0;
};

//
// First concrete Door class.
//
class GasCarDoor : public Door
{
public:
	GasCarDoor()
	{
		cout << "Making a door for a gas car." << endl;
	}

	void open()
	{
		cout << "Click!" << endl;
	}
};

//
// Second concrete Door class.
//
class ElectricCarDoor : public Door
{
public:
	ElectricCarDoor()
	{
		cout << "Making a door for an electric car." << endl;
	}

	void open()
	{
		cout << "Shhhh!" << endl;
	}
};

//
// Engine abstract class.
//
class Engine
{
protected:
	char _sound[15]{};

public:
	Engine() {}

	virtual void run() = 0;
};

//
// First concrete Engine class.
//
class GasEngine : public Engine
{
public:
	GasEngine()
	{
		strncpy_s(_sound, "Vroom!", sizeof(_sound));
		cout << "Making a gas engine." << endl;
	}

	void run()
	{
		cout << _sound << endl;
	}
};

//
// Second concrete class.
//
class ElectricEngine : public Engine
{
public:
	ElectricEngine()
	{
		strncpy_s(_sound, "SHHHH!", sizeof(_sound));
		cout << "Making an electical engine" << endl;
	}

	void run()
	{
		cout << _sound << endl;
	}
};

//
// Finally the abstract CarFactory.
//
class CarFactory
{
public:
	virtual Door* buildDoor() = 0;
	virtual Engine* buildEngine() = 0;
};

//
// First concrete CarFactory.
//
class GasCarFactory : public CarFactory
{
public:
	Door* buildDoor()
	{
		return new GasCarDoor();
	}

	Engine* buildEngine()
	{
		return new GasEngine();
	}
};

//
// Second concrete CarFactory.
//
class ElectricCarFactory : public CarFactory
{
	Door* buildDoor()
	{
		return new ElectricCarDoor();
	}

	Engine* buildEngine()
	{
		return new ElectricEngine();
	}
};

int main()
{
	int choice{};
	CarFactory* CarPlant{};

	cout << "Select a car type: " << endl;
	cout << "1: Gasoline" << endl;
	cout << "2: Electric" << endl;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		CarPlant = new GasCarFactory;
		break;
	case 2:
		CarPlant = new ElectricCarFactory;
		break;
	default:
		cout << "Invalid selection" << endl;
	}

	if (CarPlant != nullptr)
	{
		Door* myDoor = CarPlant->buildDoor();
		Engine* myEngine = CarPlant->buildEngine();

		myDoor->open();
		myEngine->run();
	}
}