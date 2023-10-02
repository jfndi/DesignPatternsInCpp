#include <iostream>

/*
 * The strategy pattern (also known as the policy pattern) is a behavioral 
 * software design pattern that enables selecting an algorithm at runtime. Instead
 * of implementing a single algorithm directly, code receives run-time 
 * instructions as to which in a family of algorithms to use.
 * Strategy lets the algorithm vary independently from clients that use it
 */

using namespace std;

class GreetingStrategy
{
public:
	virtual ~GreetingStrategy() {}
	virtual void greet(const string& name) = 0;
};

class FormalGreetingStrategy : public GreetingStrategy
{
	void greet(const string& name) override
	{
		cout << "Good morning " << name << ", how do you do?\n";
	}
};

class NormalGreetingStrategy : public GreetingStrategy
{
	void greet(const string& name) override
	{
		cout << "Hi, " << name << ", how are you?\n";
	}
};

class InformalGreetingStrategy : public GreetingStrategy
{
	void greet(const string& name) override
	{
		cout << "Hey, " << name << ", what's up?\n";
	}
};

class Person
{
	GreetingStrategy* greetingStrategy{};
public:
	Person(GreetingStrategy* greetingStrategy) : greetingStrategy(greetingStrategy) {}
	~Person() { delete greetingStrategy; }

	void greet(const string& name)
	{
		greetingStrategy->greet(name);
	}
};

int main(void)
{
	Person businessPerson(new FormalGreetingStrategy());
	Person normalPerson(new NormalGreetingStrategy());
	Person coolPerson(new InformalGreetingStrategy());
	Person politician(new FormalGreetingStrategy());

	std::cout << "The businessperson says: ";
	businessPerson.greet("Shaun");

	std::cout << "The normal person says: ";
	normalPerson.greet("Shaun");

	std::cout << "The cool person says: ";
	coolPerson.greet("Shaun");

	std::cout << "The politician says: ";
	politician.greet("Shaun");

	return 0;
}