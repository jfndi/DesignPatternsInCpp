#include <iostream>
/*
 * Mediator is a behavioral design pattern that lets you reduce chaotic 
 * dependencies between objects. The pattern restricts direct communications 
 * between the objects and forces them to collaborate only via a mediator object. 
 */
using namespace std;

class Mediator
{
public:
	virtual void mediate(const string& event) = 0;
};

class InterfaceElement
{
protected:
	Mediator* mediator{};
	string name{};
	bool isVisible{ true };

public:
	InterfaceElement(const string& name, bool isVisible, Mediator* mediator) : 
		name{ name }, isVisible{ isVisible }, mediator(mediator) {}
	void setVisibility(bool isVisible)
	{
		this->isVisible = isVisible;
	}

	string getDescription()
	{
		return isVisible ? name + " is visible"
			: name + " is NOT visible";
	}
};

class ButtonElement : public InterfaceElement
{
public:
	ButtonElement(const string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {}
	virtual ~ButtonElement() {}
	virtual void click()
	{
		mediator->mediate(name + " clicked");
	}
};

class TextBox : public InterfaceElement
{
	string textValue{};
public:
	TextBox(const string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {}
	virtual ~TextBox() {}
	virtual void changeText(const string& newValue)
	{
		textValue = newValue;

		if (newValue.empty())
			mediator->mediate(name + " empty");
		else
			mediator->mediate(name + " not empty");
	}
};

class CheckBox : public InterfaceElement
{
	bool isChecked{ false };
public:
	CheckBox(const string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {}
	virtual ~CheckBox() {}
	virtual void setIsChecked(bool isChecked)
	{
		this->isChecked = isChecked;

		if (isChecked)
			mediator->mediate(name + " is checked");
		else
			mediator->mediate(name + " is unchecked");
	}
};

class UserInterface : public Mediator
{
	TextBox* nameTextBox{};
	CheckBox* isMarriedCheckBox{};
	TextBox* spousesNameTextBox{};
	ButtonElement* submitButton{};
public:
	UserInterface()
	{
		nameTextBox = new TextBox("Name textbox", true, this);
		isMarriedCheckBox = new CheckBox("Is married checkbox", true, this);
		spousesNameTextBox = new TextBox("Spouse's name textbox", false, this);
		submitButton = new ButtonElement("Submit button", false, this);
	}

	~UserInterface()
	{
		delete nameTextBox;
		delete isMarriedCheckBox;
		delete spousesNameTextBox;
		delete submitButton;
	}

	void mediate(const string& event) override
	{
		if (event == "Name textbox is empty")
			submitButton->setVisibility(false);
		else if (event == "Name textbox not empty")
			submitButton->setVisibility(true);
		else if (event == "Is married checkbox is checked")
			spousesNameTextBox->setVisibility(true);
		else if (event == "Is married checkbox is unchecked")
			spousesNameTextBox->setVisibility(false);
		else if (event == "Submit button clicked")
			cout << "Submitted!\n";
		else
			cout << "Unrecognized event!\n";
	}

	TextBox* getNameTextBox() const
	{
		return nameTextBox;
	}

	CheckBox* getIsMarriedCheckBox() const
	{
		return isMarriedCheckBox;
	}

	TextBox* getSpousesNameTextBox() const
	{
		return spousesNameTextBox;
	}

	ButtonElement* getSubmitButton() const
	{
		return submitButton;
	}
};

int main(void)
{
	UserInterface* ui = new UserInterface;

	InterfaceElement* elements[] =
	{
		ui->getNameTextBox(),
		ui->getIsMarriedCheckBox(),
		ui->getSpousesNameTextBox(),
		ui->getSubmitButton()
	};

	for (auto element : elements)
		cout << element->getDescription() << endl;

	ui->getIsMarriedCheckBox()->setIsChecked(true);

	for (auto element : elements)
		cout << element->getDescription() << endl;

	delete ui;

	return 0;
}