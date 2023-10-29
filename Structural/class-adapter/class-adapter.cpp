#include <iostream>
#include <memory>

using namespace std;

class ModernInterface
{
public:
	virtual void executeTask() = 0;
	virtual ~ModernInterface() = default;
};

class ModernInterfaceUserA : public ModernInterface
{
public:
	virtual void executeTask() override
	{
		cout << "Executing task for ModernInterfaceUserA" << endl;
	}
};

class ModernInterfaceUserB : public ModernInterface
{
public:
	virtual void executeTask() override
	{
		cout << "Executing task for ModernInterfaceUserB." << endl;
	}
};

class LegacyClass
{
public:
	void do_it()
	{
		cout << "Executing the task from legacy object." << endl;
	}
};

class Adapter : LegacyClass, public ModernInterface
{
public:
	Adapter() = default;

	virtual void executeTask() override
	{
		cout << "Calling adapter executeTask" << endl;
		do_it();
	}
};

int main()
{
	const unique_ptr<ModernInterface> users[] =
	{
		make_unique<ModernInterfaceUserA>(),
		make_unique<ModernInterfaceUserB>(),
		make_unique<Adapter>()
	};

	for (auto& user : users)
		user->executeTask();

	cout << "Done!!!" << endl;
}