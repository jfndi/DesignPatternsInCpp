#include <iostream>
/*
 * Visitor pattern is used when we have to perform an operation on a group of 
 * similar kind of Objects. With the help of visitor pattern, we can move the 
 * operational logic from the objects to another class. 
 */
using namespace std;

class Visitor
{
public:
	virtual void handlePerson(const string& name, int age) = 0;
	virtual void handleLandmark(const string& name, const string& cityName) = 0;
	virtual void handleCar(const string& make, const string& model) = 0;
};

class DatabaseVisitor : public Visitor
{
public:
	void handlePerson(const string& name, int age) override
	{
		cout << "Writing person to database: " << name << ", " << age << "\n";
	}

	void handleLandmark(const string& name, const string& cityName) override
	{
		cout << "Writing landmark to database: " << name << ", " << cityName << "\n";
	}

	void handleCar(const string& make, const string& model) override
	{
		cout << "Writing car to database: " << make << ", " << model << "\n";
	}
};

class TextFileVisitor : public Visitor
{
public:
	void handlePerson(const string& name, int age) override
	{
		cout << "Writing person to file: " << name << ", " << age << "\n";
	}

	void handleLandmark(const string& name, const string& cityName) override
	{
		cout << "Writing landmark to file: " << name << ", " << cityName << "\n";
	}

	void handleCar(const string& make, const string& model) override
	{
		cout << "Writing car to file: " << make << ", " << model << "\n";
	}
};

class Person
{
	string name;
	int age;
public:
	Person(const string& name, int age) : name(name), age(age) {}
	void accept(Visitor* v)
	{
		v->handlePerson(name, age);
	}
};

class LandMark
{
	string name;
	string cityName;
public:
	LandMark(const string& name, const string& cityName) : name(name), cityName(cityName) {}
	void accept(Visitor* v)
	{
		v->handleLandmark(name, cityName);
	}
};

class Car
{
	string make;
	string model;
public:
	Car(const string& make, const string& model) : make(make), model(model) {}
	void accept(Visitor* v)
	{
		v->handleCar(make, model);
	}
};

auto newline = [] { cout << "\n"; };

int main(void)
{
	Person person("John", 40);
	LandMark landmark("Eiffel Tower", "Paris");
	Car car("Chevrolet", "Camaro");

	DatabaseVisitor* dbv = new DatabaseVisitor;
	TextFileVisitor* tfv = new TextFileVisitor;

	person.accept(dbv);
	landmark.accept(dbv);
	car.accept(dbv);

	newline();

	person.accept(tfv);
	landmark.accept(tfv);
	car.accept(tfv);

	delete tfv;
	delete dbv;

	return 0;
}