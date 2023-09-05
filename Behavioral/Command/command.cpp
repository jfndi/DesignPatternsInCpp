#include <iostream>
#include <vector>
/*
 * In command pattern, the request is send to the invoker and invoker pass it to 
 * the encapsulated command object. Command object passes the request to the 
 * appropriate method of Receiver to perform the specific action. The client 
 * program create the receiver object and then attach it to the Command.
 */
using namespace std;

class Command
{
public:
	virtual ~Command() {};
	virtual void execute() = 0;
};

class Canvas
{
	vector<string> shapes{};

public:
	void addShape(const string& newShape)
	{
		shapes.push_back(newShape);
	}

	void clearAll()
	{
		shapes.clear();
	}

	vector<string> getShapes() const
	{
		return shapes;
	}
};

class AddShapeCommand : public Command
{
	string shapeName{};
	Canvas* canvas{};

public:
	AddShapeCommand(string shapeName, Canvas* canvas) :
		shapeName(shapeName) , canvas(canvas) {};

	void execute() override
	{
		canvas->addShape(shapeName);
	}
};

class ClearCommand : public Command
{
	Canvas* canvas{};

public:
	ClearCommand(Canvas* canvas) : canvas(canvas) {};

	void execute() override
	{
		canvas->clearAll();
	}
};

class Button
{
	Command* command{};

public:
	Button(Command* command) : command(command) {};

	~Button()
	{
		delete command;
	}

	virtual void click()
	{
		command->execute();
	}
};

string vectorToString(vector<string> v)
{
	string result{};

	for (auto& s : v)
	{
		if (result.size())
			result.append(", ");
		result.append(s);
	}
	return result;
}

int main()
{
	Canvas* canvas = new Canvas;

	Button* addTriangleButton = new Button(new AddShapeCommand("Triangle", canvas));
	Button* addSquareButton = new Button(new AddShapeCommand("Square", canvas));
	Button* clearButton = new Button(new ClearCommand(canvas));

	addTriangleButton->click();
	cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << endl;
	addSquareButton->click();
	addSquareButton->click();
	addTriangleButton->click();
	cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << endl;
	clearButton->click();
	cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << endl;
}