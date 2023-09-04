#include <iostream>
#include <deque>
#include <map>
/*
 * The multiton pattern is a design pattern which generalizes the singleton
 * pattern. Whereas the singleton allows only one instance of a class to be
 * created, the multiton pattern allows for the controlled creation of multiple
 * instances, which it manages through the use of a map.
 */
using namespace std;

enum class Priority { CRITICAL, IMPORTANT, NORMAL };

using Queue = deque<string>;

template <typename T, typename Key>
struct Multiton
{
private:
	static map<Key, shared_ptr<T>> _instances;

public:
	static shared_ptr<T> get(const Key key)
	{
		auto it = _instances.find(key);
		if (it != _instances.end())
			return it->second;

		return _instances[key] = make_shared<T>();
	}
};

template <typename T, typename Key>
map<Key, shared_ptr<T>> Multiton<T, Key>::_instances;

struct MessageQueue : Queue
{
	MessageQueue()
	{
		cout << "Total instances of message queues so far: " << ++instance_count << endl;
	}

private:
	static int instance_count;
};

int MessageQueue::instance_count = 0;

int main()
{
	using mt = Multiton<MessageQueue, Priority>;

	auto prio1Queue{ mt::get(Priority::CRITICAL) };
	prio1Queue->push_back("High priority message.");

	auto prio3Queue{ mt::get(Priority::NORMAL) };
	prio3Queue->push_back("Low priority message");

	cout << "Prio1 message: " << prio1Queue->front() << endl;
	cout << "Prio3 message: " << prio3Queue->front() << endl;

	auto prio1Queue2{ mt::get(Priority::CRITICAL) };
	cout << "Prio1 message (second \"instance\"): " << prio1Queue2->front() << endl;
}