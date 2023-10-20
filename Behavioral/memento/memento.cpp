#include <iostream>
#include <vector>

/**
 * The memento pattern is a software design pattern that exposes the private 
 * internal state of an object. One example of how this can be used is to restore 
 * an object to its previous state (undo via rollback), another is versioning, 
 * another is custom serialization.
 */

using namespace std;

class Canvas;

class CanvasMemento
{
	friend class Canvas;
	const vector<string> shapes;
public:
	CanvasMemento(vector<string> shapes) : shapes(shapes) {}
};

class Canvas
{
	vector<string> shapes;
	vector<CanvasMemento*> oldStates;
public:
	~Canvas()
	{
		for (auto p : oldStates)
			delete p;

		oldStates.clear();
	}

	void addShape(const string& newShape)
	{
		oldStates.push_back(new CanvasMemento(shapes));
		shapes.push_back(newShape);
	}

	void undo()
	{
		CanvasMemento* previousState = oldStates.back();
		oldStates.pop_back();
		shapes = previousState->shapes;
		delete previousState;
	}

	void clearAll()
	{
		shapes.clear();
	}

	vector<string> getShapes()
	{
		return shapes;
	}
};

int main(int argc, const char* argv[]) 
{
    Canvas* canvas = new Canvas;

    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");

    for (auto& shape : canvas->getShapes())
        cout << shape << ", ";

    cout << "\n";

    canvas->undo();

    for (auto& shape : canvas->getShapes()) 
        cout << shape << ", ";

    cout << "\n";

    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    canvas->undo();

    for (auto& shape : canvas->getShapes())
        cout << shape << ", ";

    cout << "\n";

    delete canvas;

    return 0;
}