#include <iostream>
#include <stdio.h>

/**
 * In Null Object pattern, a null object replaces check of NULL object instance. 
 * Instead of putting if check for a null value, Null Object reflects a do nothing
 * relationship. Such Null object can also be used to provide default behaviour in
 * case data is not available.
 */

using namespace std;

class Logger
{
public:
	virtual ~Logger() {};
	virtual void log(const string& message) = 0;
};

class ConsoleLogger : public Logger
{
public:
	void log(const string& message) override
	{
		cout << message << "\n";
	}
};

class FileLogger : public Logger
{
	string filePath{};
public:
	FileLogger(const string& filePath) : filePath(filePath) {}

	void log(const string& message) override
	{
		cout << "Printing message to file " << filePath << "\n";
	}
};

class ApiLogger : public Logger
{
	string url{};
public:
	ApiLogger(const string& url) : url(url) {}

	void log(const string& message) override
	{
		cout << "Sending message to api " << url << "\n";
	}
};

class NullLogger : public Logger
{
public:
	void log(const string& message) override {}
};

class SomeTask
{
	Logger* logger{};
public:
	SomeTask()
	{
		logger = new NullLogger;
	}

	SomeTask(Logger* logger) : logger(logger) {}
	
	~SomeTask()
	{
		delete logger;
	}

	void execute()
	{
		/*
		 * Do some stuff. 
		 */
		logger->log("Did some stuff.");

		/*
		 * Do some more stuff. 
		 */
		logger->log("Did some other stuff.");

		/*
		 * One last thing.
		 */
		logger->log("Task complete");
	}
};

int main(int argc, const char* argv[])
{
	SomeTask task1(new ConsoleLogger);
	SomeTask task2(new FileLogger("logs.txt"));
	SomeTask task3(new ApiLogger("loggingsite.com/api/logs"));
	SomeTask task4;

	task1.execute();
	task2.execute();
	task3.execute();
	task4.execute();

	return 0;
}