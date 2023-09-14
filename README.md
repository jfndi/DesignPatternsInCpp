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