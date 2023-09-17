#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
 * A use case of combined patterns:
 * - The observer pattern.
 * - The chain of responsibility pattern.
 */

class Subscriber
{
public:
	virtual void notify(const string& publisherName, const string& message) const = 0;
	virtual string getName() const = 0;
};

class ChatUser : public Subscriber
{
	string userName{};
public:
	ChatUser(const string& userName) : userName(userName) {}
	void notify(const string& publisherName, const string& message) const override
	{
		cout << userName << " receive new message from " << publisherName
			<< ": " << message << endl;
	}

	string getName() const override
	{
		return userName;
	}
};

class Publisher
{
public:
	virtual void subscribe(Subscriber* subscriber) = 0;
	virtual void unsubscribe(Subscriber* subscriber) = 0;
	virtual void publish(const string& message) = 0;
};

class ChatGroup : public Publisher
{
	string groupName{};
	vector<Subscriber*> subscribers{};
public:
	ChatGroup(const string& groupName) : groupName(groupName) {}
	void subscribe(Subscriber* subscriber)
	{
		subscribers.push_back(subscriber);
	}

	void unsubscribe(Subscriber* subscriber)
	{
		subscribers.erase(remove_if(subscribers.begin(),
			subscribers.end(), [subscriber](Subscriber* s)
			{
				return subscriber->getName() == s->getName();
			}));
	}

	void publish(const string& message)
	{
		for (auto subscriber : subscribers)
			subscriber->notify(groupName, message);
	}
};

class Handler
{
public:
	virtual Handler* setNext(Handler* nextValidator) = 0;
	virtual ~Handler() {}
	virtual string handle(ChatGroup* group, const string& message) = 0;
};

class BaseHandler : public Handler
{
protected:
	Handler* next;

public:
	~BaseHandler()
	{
		delete next;
	}

	Handler* setNext(Handler* nextValidator) override
	{
		next = nextValidator;
		return nextValidator;
	}

	virtual string handle(ChatGroup* group, const string& message) override
	{
		if (next)
			return next->handle(group, message);

		return "Success!";
	}
};

class NotEmptyValidator : public BaseHandler
{
public:
	string handle(ChatGroup* group, const string& message)
	{
		cout << "Checking if empty...\n";

		if (message.empty())
			return "Please enter a value\n";

		return BaseHandler::handle(group, message);
	}
};

class LengthValidator : public BaseHandler
{
	int minLength;

public:
	LengthValidator(int minLength) : minLength(minLength) {}

	string handle(ChatGroup* group, const string& message)
	{
		cout << "Checking if length equels: " << minLength << endl;

		if (message.size() < minLength)
			return "Please enter a message longer than " + to_string(minLength) + "\n";

		return BaseHandler::handle(group, message);
	}
};

class PostMessageHandler : public BaseHandler
{
public:
	string handle(ChatGroup* group, const string& message)
	{
		group->publish(message);
		return "Message sent!\n";
	}
};

int main(int argc, const char* argv[])
{
	ChatUser* user1 = new ChatUser("Jim");
	ChatUser* user2 = new ChatUser("Barb");
	ChatUser* user3 = new ChatUser("Hannah");

	ChatGroup* group1 = new ChatGroup("Gardening Group");
	ChatGroup* group2 = new ChatGroup("Dog-lovers Group");

	group1->subscribe(user1);
	group1->subscribe(user2);

	group2->subscribe(user2);
	group2->subscribe(user3);

	Handler* sendMessageChain = new BaseHandler;

	sendMessageChain
		->setNext(new NotEmptyValidator)
		->setNext(new LengthValidator(2))
		->setNext(new PostMessageHandler);

	std::cout << "Sending empty message:\n" << sendMessageChain->handle(group1, "") << "\n\n";
	std::cout << "Sending short message:\n" << sendMessageChain->handle(group1, "H") << "\n\n";
	std::cout << "Sending message to group 1:\n" << sendMessageChain->handle(group1, "Hello everyone in group 1!") << "\n\n";
	std::cout << "Sending message to group 2:\n" << sendMessageChain->handle(group2, "Hello everyone in group 2!") << "\n\n";

	delete user1;
	delete user2;
	delete user3;
	delete group1;
	delete group2;
	delete sendMessageChain;
}

