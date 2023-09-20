#include <iostream>
#include <string>
/*
 * The interpreter pattern is a design pattern that specifies how to evaluate 
 * sentences in a language. The basic idea is to have a class for each symbol 
 * (terminal or nonterminal) in a specialized computer language. The syntax tree 
 * of a sentence in the language is an instance of the composite pattern and is 
 * used to evaluate (interpret) the sentence for a client. 
 */

using namespace std;

class Expression
{
public:
	virtual int evaluate() = 0;
};

class OperationExpression : public Expression
{
	string operatorSymbol{};
	Expression* leftHandSide{};
	Expression* rightHandSide{};

public:
	OperationExpression(const string& operatorSymbol, Expression* lhs, Expression* rhs) :
		operatorSymbol(operatorSymbol), leftHandSide(lhs), rightHandSide(rhs) {}

	int evaluate() override
	{
		if (operatorSymbol == "plus")
			return leftHandSide->evaluate() + rightHandSide->evaluate();
		else if (operatorSymbol == "minus")
			return leftHandSide->evaluate() - rightHandSide->evaluate();
		else
		{
			cout << "Unrecognized operator: " << operatorSymbol << endl;
			return 0;
		}
	}
};

class NumberExpression : public Expression
{
	string numberString{};

public:
	NumberExpression(const string& numberString) : numberString(numberString) {}

	int evaluate() override
	{
		return stoi(numberString);
	}
};

int main(int argc, char* argv[])
{
	NumberExpression* five = new NumberExpression("5");
	NumberExpression* seven = new NumberExpression("7");
	OperationExpression* fivePlusSeven = new OperationExpression("plus", five, seven);

	NumberExpression* thirteen = new NumberExpression("13");
	OperationExpression* complexOp = new OperationExpression("minus", thirteen, fivePlusSeven);

	cout << "Five plus seven is: " << fivePlusSeven->evaluate() << endl;
	cout << "13 - (5 + 7) = " << complexOp->evaluate() << endl;

	delete five;
	delete seven;
	delete fivePlusSeven;
	delete thirteen;
	delete complexOp;

	return 0;
}