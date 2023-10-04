#include <iostream>

/*
 * Template Method is a behavioral design pattern that defines the skeleton of an
 * algorithm in the superclass but lets subclasses override specific steps of the
 * algorithm without changing its structure. 
 */

using namespace std;

class GreetingCardTemplate
{
protected:
	virtual string intro(const string& to)
	{
		return "Dear " + to + ",\n";
	}

	virtual string occasion()
	{
		return "Just writing to say hi! Hope all is well with you.\n";
	}

	virtual string closing(const string& from)
	{
		return "Sincerly,\n" + from + "\n";
	}

public:
	string generate(const string& to, const string& from)
	{
		return intro(to) + occasion() + closing(from);
	}
};

class BirthdayCardTemplate : public GreetingCardTemplate
{
protected:
	string occasion() override
	{
		return "Happy birthday!! Hope you have a wonderful day and lots of cake.\n";
	}
};

class NewYearCardTemplate : public GreetingCardTemplate
{
protected:
	string intro(const string& to) override
	{
		return to + "!!!\n";
	}

	string occasion() override
	{
		return "Happy New Year!!! See you at the gym tomorrow!!!\n";
	}
};

int main(int argc, const char* argv[])
{
	GreetingCardTemplate gct;
	BirthdayCardTemplate bct;
	NewYearCardTemplate nyct;

	std::cout << "Here's a regular greeting card:\n\n" << gct.generate("Bob", "Jane") << "\n";
	std::cout << "Here's a birthday card:\n\n" << bct.generate("Bob", "Jane") << "\n";
	std::cout << "Here's a new year's card:\n\n" << nyct.generate("Bob", "Jane") << "\n";

	return 0;
}