#include <iostream>
#include <vector>
#include <algorithm>
/*
 * In software design and engineering, the observer pattern is a software design 
 * pattern in which an object, named the subject, maintains a list of its 
 * dependents, called observers, and notifies them automatically of any state 
 * changes, usually by calling one of their methods. 
 */

using namespace std;

class Subscriber
{
public:
	virtual void notify(const string& publisherName, const string& message) = 0;
	virtual string getName() const = 0;
};

class Publisher
{
public:
	virtual void subscribe(Subscriber* subscriber) = 0;
	virtual void unsubscribe(Subscriber* subscriber) = 0;
	virtual void publish(const string& message) = 0;
};

/*
 * The observer. 
 */
class ChatGroup : public Publisher
{
	string groupName{};
	vector<Subscriber*> subscribers{};
public:
	ChatGroup(const string& name) : groupName(name) {}
	void subscribe(Subscriber* subscriber) override
	{
		this->subscribers.push_back(subscriber);
	}

	void unsubscribe(Subscriber* subscriber) override
	{
		this->subscribers.erase(remove_if(subscribers.begin(),
			subscribers.end(), [subscriber](Subscriber* s)
			{
				return s->getName() == subscriber->getName();
			}),
			subscribers.end());
	}

	void publish(const string& message) override
	{
		for (auto subscriber : subscribers)
			subscriber->notify(groupName, message);
	}
};

class ChatUser : public Subscriber
{
	string userName;
public:
	ChatUser(const string& userName) : userName(userName) {}
	void notify(const string& publisherName, const string& message) override
	{
		cout << userName << " received a new message from " << publisherName << endl;
	}

	string getName() const override
	{
		return userName;
	}
};

int main(int argc, const char* argv[])
{
	ChatUser* user1 = new ChatUser("Jim");
	ChatUser* user2 = new ChatUser("Barb");
	ChatUser* user3 = new ChatUser("Hannah");

	ChatGroup* group1 = new ChatGroup("Gardening group");
	ChatGroup* group2 = new ChatGroup("Dog-lovers group");

	group1->subscribe(user1);
	group1->subscribe(user2);

	group2->subscribe(user2);
	group2->subscribe(user3);

	group1->publish("Special sale on gardening supplies!");
	group2->publish("It's national dog day everyone!");

	delete user1;
	delete user2;
	delete user3;
	delete group1;
	delete group2;

	return 0;
}