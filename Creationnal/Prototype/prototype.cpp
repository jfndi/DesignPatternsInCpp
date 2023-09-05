#include <iostream>
/*
 * Prototype is a creational design pattern that allows cloning objects, even 
 * complex ones, without coupling to their specific classes. All prototype classes
 * should have a common interface that makes it possible to copy objects even if 
 * their concrete classes are unknown. 
 */
using namespace std;

//
//  ABstract Animal class.
//
class Animal
{
protected:
	char _hairColor[10];
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubbornness, _aggressiveness;

public:
	virtual Animal* clone() = 0;

	void setHairLength(int length)
	{
		_hairLength = length;
	}

	void setHairColor(const char* color)
	{
		strncpy_s(_hairColor, color, _countof(_hairColor));
	}

	void setTail(int length)
	{
		_tail = length;
	}

	void setWeight(int kg)
	{
		_weight = kg;
	}

	void setHeight(int m)
	{
		_height = m;
	}

	void setAge(int age)
	{
		_age = age;
	}
};

//
// Derived Sheep class.
//
class Sheep : public Animal
{
public:
	Sheep()
	{
		_hairLength = 5;
		_stubbornness = 3;
		_aggressiveness = 2;
		_intelligence = 7;
	}

	Animal* clone()
	{
		return new Sheep(*this);
	}

	void shearing()
	{
		_hairLength -= 2;
	}
};

//
// Derived Cow class.
//
class Cow : public Animal
{
public:
	Cow()
	{
		_stubbornness = 6;
		_aggressiveness = 5;
		_intelligence = 8;
	}

	Cow* clone()
	{
		return new Cow(*this);
	}
};

int main()
{
	//
	// Create initial instance of a Sheep.
	//
	Sheep* sheep0 = new Sheep;
	sheep0->setHairColor("white");
	sheep0->setTail(5);
	sheep0->setWeight(90);
	sheep0->setHeight(1);
	sheep0->setAge(5);

	//
	// Create initial instance of a Cow.
	Cow* cow0 = new Cow;
	cow0->setHairColor("brown");
	cow0->setTail(20);
	cow0->setWeight(790);
	cow0->setHeight(2);
	cow0->setAge(8);

	Animal* farm[3]{};

	//
	// Use cloning to populate the farm.
	//
	farm[0] = sheep0->clone();
	farm[1] = cow0->clone();

	//
	// Change a cow property.
	//
	farm[1]->setWeight(1000);

	//
	// Shear a Sheep and clone it.
	//
	sheep0->shearing();
	farm[2] = sheep0->clone();
}