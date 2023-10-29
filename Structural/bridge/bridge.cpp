#include <iostream>

/*
 * Bridge is a structural design pattern that divides business logic or huge class
 * into separate class hierarchies that can be developed independently. One of 
 * these hierarchies (often called the Abstraction) will get a reference to an 
 * object of the second hierarchy (Implementation).
 */

using namespace std;

class Implementor
{
public:
	virtual void implementation() const = 0;
	virtual ~Implementor() = default;
};

class ImplementorA : public Implementor
{
public:
	ImplementorA() = default;

	virtual void implementation() const override
	{
		cout << "ImplementorA::implementation." << endl;
	}
};

class ImplementorB : public Implementor
{
public:
	ImplementorB() = default;

	virtual void implementation() const override
	{
		cout << "ImplementorB::implementation." << endl;
	}
};

class Abstraction
{
public:
	virtual void function() const = 0;
	virtual ~Abstraction() = default;
};

class RefinedAbstraction : public Abstraction
{
	Implementor& _implementor;
public:
	RefinedAbstraction(Implementor& impl) : _implementor(impl) {};

	virtual void function() const override
	{
		cout << "RefinedAbstraction::function." << endl;
		_implementor.implementation();
	}
};

int main()
{
	ImplementorA implementorA;
	ImplementorB implementorB;

	RefinedAbstraction refinedAbstractionA(implementorA);
	RefinedAbstraction refinedAbstractionB(implementorB);

	auto execute = [](Abstraction* a)
		{
			a->function();
		};

	execute(&refinedAbstractionA);
	execute(&refinedAbstractionB);

	return 0;

}