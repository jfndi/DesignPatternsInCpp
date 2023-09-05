#include <iostream>
#include <vector>
#include <regex>
/*
 * Chain of Responsibility in C++: Chain of Responsibility is behavioral design 
 * pattern that allows passing request along the chain of potential handlers until
 * one of them handles request. The pattern allows multiple objects to handle the 
 * request without coupling sender class to the concrete classes of the receivers. 
 */
using namespace std;

class StringValidator
{
public:
	virtual StringValidator* setNext(StringValidator* nextValidator) = 0;
	virtual ~StringValidator() {};
	virtual string validate(string) = 0;
};

class BaseValidator : public StringValidator
{
protected:
	StringValidator* next{};

public:
	~BaseValidator() { delete next; };

	StringValidator* setNext(StringValidator* nextValidator) override
	{
		next = nextValidator;
		return nextValidator;
	}

	virtual string validate(string testString) override
	{
		if (this->next)
			return this->next->validate(testString);
		return "Success";
	}
};

class NotEmptyValidator : public BaseValidator
{
	string validate(string testString) override
	{
		cout << "Checking if empty...\n";

		if (testString.empty())
			return "Please enter a value!\n";

		return BaseValidator::validate(testString);
	}
};

class LengthValidator : public BaseValidator
{
	int minLength{};

public:
	LengthValidator(int minLength) : minLength(minLength) {};

	string validate(string testString) override
	{
		cout << "Checking if length is at least: " << minLength << " char long...\n";

		if (testString.size() < minLength)
			return "Please enter a value longer that " + to_string(minLength) + "\n";

		return BaseValidator::validate(testString);
	}
};

class RegexValidator : public BaseValidator
{
	string patternName{};
	string regexString{};

public:
	RegexValidator(string patternName, string regexString) :
		patternName(patternName), regexString(regexString) {};

	string Validate(string testString)
	{
		cout << "Checking if string is valid " << patternName << " ...\n";

		if (!regex_match(testString, regex(regexString)))
			return "The entered string does not match " + patternName + "\n";

		return BaseValidator::validate(testString);
	}
};

bool in_vector(const string& value, const vector<string>& v)
{
	return find(v.begin(), v.end(), value) != v.end();
}

class HistoryValidator : BaseValidator
{
	vector<string> historyItems;

public:
	HistoryValidator(vector<string> historyItems) : historyItems(historyItems) {};

	string validate(string testString) override
	{
		cout << "Checking if the string is in history...\n";

		if (in_vector(testString, historyItems))
			return "Please enter a string that you haven't entered before\n";

		return BaseValidator::validate(testString);
	}
};

int main()
{
	vector<string> oldPasswords{ "abc123", "123456", "hello" };

	BaseValidator* emailValidator = new BaseValidator;

	emailValidator->setNext(new NotEmptyValidator)
		->setNext(new RegexValidator("email address", "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

	cout << "Checking Emails ------------\n";
	cout << "Input: \n" << emailValidator->validate("") << "\n\n";
	cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
	cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n\n";

	delete emailValidator;
}