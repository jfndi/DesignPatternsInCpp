#include <iostream>

/*
 * Singleton design pattern is a software design principle that is used to
 * restrict the instantiation of a class to one object. This is useful when
 * exactly one object is needed to coordinate actions across the system.
 */
using namespace std;
/*
 * BIG FAT NOTE: No considerations have been put in multi-threading issues.
 * I might come back to this particular aspect in the future.
 */

class Singleton
{
private:
	static Singleton* _instance;
	int _value{};

public:
	Singleton(Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	Singleton() {};

	bool hasInstance()
	{
		return _instance != nullptr;
	}

	Singleton* getInstance()
	{
		if (!hasInstance())
			_instance = new Singleton();

		return _instance;
	}

	void setValue(const int val)
	{
		_value = val;
	}

	int getValue() const
	{
		return _value;
	}
};

Singleton* Singleton::_instance{};

int main()
{
	Singleton* s1{};

	s1 = s1->getInstance();
	s1->setValue(42);

	cout << "Instance 1 address: 0x" << s1 << " value: " << s1->getValue() << endl;

	Singleton* s2{};
	s2 = s2->getInstance();
	cout << "Instance 2 address: 0x" << s2 << " value: " << s2->getValue() << endl;
}