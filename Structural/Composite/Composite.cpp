#include <iostream>
#include <map>
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

class MealItem
{
public:
	virtual const char* get_item() const = 0;
	~MealItem() {};
};

//
// Class Entree.
//
class Entree : public MealItem
{
protected:
	char _entree[10];

public:
	Entree() = delete;

	Entree(const char* e)
	{
		snprintf(_entree, sizeof(_entree), e);
	}

	virtual const char* get_item() const
	{
		return _entree;
	}
};

//
// Class Side.
//
class Side : public MealItem
{
protected:
	char _side[10];

public:
	Side() = delete;

	Side(const char* s)
	{
		snprintf(_side, sizeof(_side), s);
	}

	virtual const char* get_item() const
	{
		return _side;
	}
};

//
// Class Drink.
//
class Drink : public MealItem
{
protected:
	char _drink[10];

public:
	Drink() = delete;

	Drink(const char* d)
	{
		snprintf(_drink, sizeof(_drink), d);
	}

	virtual const char* get_item() const
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
	map<const char*, MealItem*> _meal{};
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

	void addMealItem(const char* what, MealItem* item)
	{
		_meal.insert(make_pair(what, item));
	}

	string openMealBag()
	{

		string s = string(_bag) + ": \n";
		for (auto entry : _meal)
			s += "\t" + string(entry.first) + " " +
			string(entry.second->get_item()) + "\n";


		return s;
	}
};

int main()
{
	MealCombo* mc = new MealCombo("My dinner");

	MealItem* entree = new Entree("Soup");
	MealItem* side = new Side("Crackers");
	MealItem* drink = new Drink("Coca");

	mc->addMealItem("Entree", entree);
	mc->addMealItem("Side", side);
	mc->addMealItem("Drink", drink);

	cout << mc->openMealBag();
}