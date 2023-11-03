#include <iostream>

/*
 * The builder pattern is a design pattern designed to provide a flexible solution
 * to various object creation problems in object-oriented programming. The intent
 * of the builder design pattern is to separate the construction of a complex 
 * object from its representation. 
 */

using namespace std;

#pragma region Entrees

//
// Base Entree class.
//
class Entree
{
protected:
	char _entree[10]{};

public:
	const char* getEntree() const
	{
		return _entree;
	}
};

//
// Derived Burger class.
//
class Burger : public Entree
{
public:
	Burger()
	{
		cout << "\n Grill burger patty, add tomatoes and place them in a bun.";
		strncpy_s(_entree, "Hamburger", sizeof(_entree));
	}
};

//
// Derived Hotdog class.
//
class Hotdog : public Entree
{
public:
	Hotdog()
	{
		cout << "\n Coook sausage and place it in a bun.";
		strncpy_s(_entree, "Hotdog", sizeof(_entree));
	}
};

#pragma endregion Entrees

#pragma region Sides

//
// Base Side class.
//
class Side
{
protected:
	char _side[10]{};

public:
	const char* getSide() const
	{
		return _side;
	}
};

//
// Derived Fries class.
//
class Fries : public Side
{
public:
	Fries()
	{
		cout << "\n Fry and season potatoes.";
		strncpy_s(_side, "Fries", sizeof(_side));
	}
};

//
// Derived Salad class.
//
class Salad : public Side
{
public:
	Salad()
	{
		cout << "\n Toss greens and dressing together.";
		strncpy_s(_side, "Salad", sizeof(_side));
	}
};

#pragma endregion Sides

class Drink
{
protected:
	char _drink[10]{};

public:
	Drink()
	{
		cout << "\n Fill cup with soda." << endl;
		strncpy_s(_drink, "Soda", sizeof(_drink));
	}

	const char* getDrink() const
	{
		return _drink;
	}
};

//
// Complex MealCombo that contains an Entree, a SIde an a Drink object.
//
class MealCombo
{
private:
	Entree* entree{};
	Side* side{};
	Drink* drink{};
	char _bag[100]{};

public:
	MealCombo(const char* type)
	{
		snprintf(_bag, sizeof(_bag), type);
	}

	void setEntry(Entree* e)
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
		snprintf(_bag, sizeof(_bag), "%s: %s, %s, %s", _bag, entree->getEntree(),
			side->getSide(), drink->getDrink());

		return _bag;
	}
};

#pragma region Builders

//
// Base Builder class.
//
class MealBuilder
{
protected:
	MealCombo* _meal{};

public:
	virtual void cookEntree() {};
	virtual void cookSide() {};
	virtual void fillDrink() {};

	MealCombo* getMeal() const
	{
		return _meal;
	}
};

//
// Concrete Builder for a burger meal which has burger fries and a drink.
//
class BurgerMeal : public MealBuilder
{
public:
	BurgerMeal()
	{
		_meal = new MealCombo("Burger");
	}

	void cookEntree()
	{
		Burger* burger = new Burger;
		_meal->setEntry(burger);
	}

	void cookSide()
	{
		Fries* fries = new Fries;
		_meal->setSide(fries);
	}

	void fillDrink()
	{
		Drink* drink = new Drink;
		_meal->setDrink(drink);
	}
};

//
// Concrete builder fo a Hotdog meal witha hotdog, salad and a drink.
//
class HotdogMeal : public MealBuilder
{
public:
	HotdogMeal()
	{
		_meal = new MealCombo("Hotdog");
	}

	void cookEntree()
	{
		Hotdog* hotdog = new Hotdog;
		_meal->setEntry(hotdog);
	}

	void cookSide()
	{
		Salad* salad = new Salad;
		_meal->setSide(salad);
	}

	void fillDrink()
	{
		Drink* drink = new Drink;
		_meal->setDrink(drink);
	}
};

#pragma endregion Builders

int main()
{
	MealBuilder* cook{};
	MealCombo* meal{};
	int choice{};

	cout << "Select a meal: " << endl;
	cout << "1: Hamburger Meal" << endl;
	cout << "2: Hotdog Meal" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		cook = new BurgerMeal;
		break;
	case 2:
		cook = new HotdogMeal;
		break;
	default:
		cout << "Invalid Selection" << endl;
		cook = NULL;
		return 0;
		break;
	}

	cout << "Making selected meal" << endl;

	cook->cookEntree();
	cook->cookSide();
	cook->fillDrink();
	meal = cook->getMeal();
	cout << meal->openMealBag() << endl;
}