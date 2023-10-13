#include <iostream>
#include <vector>

/*
 * The iterator pattern is a design pattern in which an iterator is used to 
 * traverse a container and access the container's elements. The iterator pattern 
 * decouples algorithms from containers; in some cases, algorithms are necessarily
 * container-specific and thus cannot be decoupled.
 */

using namespace std;

class NumberIterator
{
public:
	virtual ~NumberIterator() {}
	virtual int next() = 0;
	virtual bool isFinished() = 0;
};

class ForwardsIterator : public NumberIterator
{
	int currentPosition{};
	vector<int>& numbers;
public:
	ForwardsIterator(vector<int>& numbers) : currentPosition(0), numbers(numbers) {}

	int next() override
	{
		int current = numbers.at(currentPosition);
		currentPosition++;

		return current;
	}

	bool isFinished() override
	{
		return currentPosition >= numbers.size();
	}
};

class BackwardsIterator : public NumberIterator
{
	int currentPosition{};
	vector<int>& numbers;
public:
	BackwardsIterator(vector<int>& numbers) : currentPosition(0), numbers(numbers) {}

	int next() override
	{
		int current = numbers.at(numbers.size() - 1 - currentPosition);
		currentPosition++;

		return current;
	}

	bool isFinished() override
	{
		return currentPosition >= numbers.size();
	}
};

class NumberCollection
{
	vector<int> numbers;
public:
	NumberCollection(const vector<int>& numbers) : numbers(numbers) {}

	NumberIterator* getForwardsIterator()
	{
		return new ForwardsIterator(numbers);
	}

	NumberIterator* getBackwardsIterator()
	{
		return new BackwardsIterator(numbers);
	}
};

auto newline = []
	{
		cout << endl;
	};

int main()
{
	vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
	NumberCollection nc(numbers);

	NumberIterator* fi = nc.getForwardsIterator();
	NumberIterator* bi = nc.getBackwardsIterator();

	cout << "Iterating through the numbers forwards:\n";
	while (!fi->isFinished())
		cout << fi->next() << " ";
	newline();

	cout << "Iterating through the numbers backwars:\n";
	while (!bi->isFinished())
		cout << bi->next() << " ";
	newline();

	delete bi;
	delete fi;
}