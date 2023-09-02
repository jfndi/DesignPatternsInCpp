#include <iostream>
/*
 * The composite design pattern:
 * -----------------------------
 * 
 * Composite pattern is a partitioning design pattern and describes a group of 
 * objects that is treated the same way as a single instance of the same type of 
 * object. The intent of a composite is to “compose” objects into tree structures
 * to represent part-whole hierarchies.
 *
 */
using namespace std;

//
// Base classe Entree.
//
class Entree
{
protected:
	char _entree[10];

public:
	Entree() = delete;

	Entree(const char* e)
	{
		snprintf(_entree, sizeof(_entree), e);
	}

	const char* getEntree() const
	{
		return _entree;
	}
};

//
// Base classe Side.
//
class Side
{
protected:
	char _side[10];

public:
	Side() = delete;

	Side(const char* s)
	{
		snprintf(_side, sizeof(_side), s);
	}

	const char* getSide() const
	{
		return _side;
	}
};

//
// Base class Drink.
//
class Drink
{
protected:
	char _drink[10];

public:
	Drink() = delete;

	Drink(const char* d)
	{
		snprintf(_drink, sizeof(_drink), d);
	}

	const char* getDrink() const
	{
		return _drink;
	}
};

//
// Class MealCombo.
//
class MealCombo
{
private:
	Entree* entree{};
	Side* side{};
	Drink* drink{};
	char _bag[100]{};

public:
	MealCombo() = delete;
	MealCombo(MealCombo&) = delete;
	MealCombo& operator=(const MealCombo&) = delete;
	MealCombo(MealCombo&&) = delete;
	MealCombo& operator=(const MealCombo&&) = delete;

	MealCombo(const char* type)
	{
		snprintf(_bag, sizeof(_bag), "\n%s meal combo: ", type);
	}

	void setEntree(Entree* e)
	{
		entree = e;
	}

	void setSide(Side* s)
	{
		side = s;
	}

	void setDrink(Drink* d)
	{
		drink = d;
	}

	const char* openMealBag()
	{
		snprintf(_bag, sizeof(_bag), "%s: %s, %s, %s\n", _bag,
			entree->getEntree(), side->getSide(), drink->getDrink());

		return _bag;
	}
};

int main()
{
	MealCombo* mc = new MealCombo("My dinner bag");

	Entree entree("Soup");
	Side side("Steack");
	Drink drink("Coca");

	mc->setEntree(&entree);
	mc->setSide(&side);
	mc->setDrink(&drink);

	cout << mc->openMealBag();
}