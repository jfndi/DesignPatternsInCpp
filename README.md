# DesignPatternsInCpp
This repository contains simple use case examples of design patterns.
The examples show are simplistic on purpose. This allows to focus on
the pattern concepts without being distracted by details having 
nothing to do with those concepts.

Creational patterns:

Creational design patterns abstract the instantiation process. They help make
a system independent of how its objects are created, composed, and 
represented. A class creational pattern uses inheritance to vary the class 
that’s instantiated, whereas an object creational pattern will delegate 
instantiation to another object.

	* Factory:
	The factory design pattern is used when we have a superclass with multiple
	sub-classes and based on input, we need to return one of the sub-class. This 
	pattern takes out the responsibility of the instantiation of a class from the
	client program to the factory class.

	* Abstract factory:
	The abstract factory pattern in software engineering is a design that provides
	a way to create families of related objects without imposing their concrete 
	classes, by encapsulating a group of individual factories that have a common
	theme without specifying their concrete classes.

	* Builder:
	The builder pattern is a design pattern designed to provide a flexible solution
	to various object creation problems in object-oriented programming. The intent
	of the builder design pattern is to separate the construction of a complex 
	object from its representation.

	* Singleton: 
	The singleton design pattern is a software design principle that is used to
	restrict the instantiation of a class to one object. This is useful when
	exactly one object is needed to coordinate actions across the system.

	* Multiton:
	The multiton pattern is a design pattern which generalizes the singleton
	pattern. Whereas the singleton allows only one instance of a class to be
	created, the multiton pattern allows for the controlled creation of multiple
	instances, which it manages through the use of a map.

	* Prototype:
	Prototype is a creational design pattern that allows cloning objects, even 
	complex ones, without coupling to their specific classes. All prototype classes
	should have a common interface that makes it possible to copy objects even if 
	their concrete classes are unknown.

Structural patterns:

	* Composite:
	Composite pattern is a partitioning design pattern and describes a group of 
	objects that is treated the same way as a single instance of the same type of 
	object. The intent of a composite is to “compose” objects into tree structures
	to represent part-whole hierarchies.

Behavioral patterns:

	* Chain of responsability:
	Chain of Responsibility is behavioral design pattern that allows passing 
	request along the chain of potential handlers untilone of them handles request.
	The pattern allows multiple objects to handle the request without coupling 
	sender class to the concrete classes of the receivers.

	* Command:
	In command pattern, the request is send to the invoker and invoker pass it to 
	the encapsulated command object. Command object passes the request to the 
	appropriate method of Receiver to perform the specific action. The client 
	program create the receiver object and then attach it to the Command.

	* Mediator:
	Mediator is a behavioral design pattern that lets you reduce chaotic 
	dependencies between objects. The pattern restricts direct communications 
	between the objects and forces them to collaborate only via a mediator object.

	* Observer:
	In software design and engineering, the observer pattern is a software design 
	pattern in which an object, named the subject, maintains a list of its 
	dependents, called observers, and notifies them automatically of any state 
	changes, usually by calling one of their methods.

	* Interpreter:
	The interpreter pattern is a design pattern that specifies how to evaluate 
	sentences in a language. The basic idea is to have a class for each symbol 
	(terminal or nonterminal) in a specialized computer language. The syntax tree 
	of a sentence in the language is an instance of the composite pattern and is 
	used to evaluate (interpret) the sentence for a client.

 	* State:
  	The state pattern is a behavioral software design pattern that allows an object
	to alter its behavior when its internal state changes. This pattern is close to 
	the concept of finite-state machines. The state pattern can be interpreted as a
	strategy pattern, which is able to switch a strategy through invocations of 
	methods defined in the pattern's interface.
	The state pattern is used in computer programming to encapsulate varying 
	behavior for the same object, based on its internal state. This can be a 
	cleaner way for an object to change its behavior at runtime without resorting
	to conditional statements and thus improve maintainability.
	
	* Strategy:
	The strategy pattern (also known as the policy pattern) is a behavioral 
	software design pattern that enables selecting an algorithm at runtime. Instead
	of implementing a single algorithm directly, code receives run-time 
	instructions as to which in a family of algorithms to use.
	Strategy lets the algorithm vary independently from clients that use it
	
	* Template method:
	Template Method is a behavioral design pattern that defines the skeleton of an
	algorithm in the superclass but lets subclasses override specific steps of the
	algorithm without changing its structure.

	* Visitor:
	Visitor pattern is used when we have to perform an operation on a group of 
	similar kind of Objects. With the help of visitor pattern, we can move the 
	operational logic from the objects to another class. 
	
	* Iterator:
	The iterator pattern is a design pattern in which an iterator is used to 
	traverse a container and access the container's elements. The iterator pattern 
	decouples algorithms from containers; in some cases, algorithms are necessarily
	container-specific and thus cannot be decoupled.
	
	* Memento:
	The memento pattern is a software design pattern that exposes the private 
	internal state of an object. One example of how this can be used is to restore 
	an object to its previous state (undo via rollback), another is versioning, 
	another is custom serialization.
	
	* Null object
	In Null Object pattern, a null object replaces check of NULL object instance. 
	Instead of putting if check for a null value, Null Object reflects a do nothing
	relationship. Such Null object can also be used to provide default behaviour in
	case data is not available.
