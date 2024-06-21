# Design Patterns
This repository contains some basic explanation and source codes for the most common design patterns.
Common design patterns can be classified in 3 main groups, which also have some subgroups:

## 1. Creational Design Patterns
Creational design patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.
### 1.1 Abstract Factory
This design pattern has the following elements:
- Abstract Product Interface: This interface defines the structure and behaviour of the product objects which are created by the factories. Each product family has it's set of abstract product interfaces. In our example, abstract product interface is Widget class.
- Abstract Factory Interface: This interface defines a set of methods for creating various abstract product types. Each method in the interface corresponds to a different product family. In our example, abstract factory interface is Widget Factory class.
- Concrete Products: Concrete product classes implement the abstract product interfaces. These classes represent the actual objects that the client code will use. In our example, concrete products are Windows Button, Linux Button, Mac Button, Windows Menu, Linux Menu, Mac Menu, Windows Combo Box, Linux Combo Box, Mac Combo Box, Windows Scroll Bar, Linux Scroll Bar, Mac Scroll Bar.
- Concrete Factories: Concrete factory classes implement the abstract factory interface. Each concrete factory is responsible for creating a specific family of related products. In our example, concrete factories are Windows Factory, Linux Factory and Mac Factory.
- Client: Client code works with the abstract factory and abstract product interfaces. It doesn't need to know the concrete classes of the products it uses, it relies on the factory to create compatible objects.

An example of abstract factory design pattern can be found under creational/abstract-factory directory. 
### 1.2 Singleton
Singleton pattern is a design pattern that ensures only one instance of the class can exist in the entire program, which means it will provide a global point of access to that specific instance. Implementation of this class can be done by the following points.
- Constructor and destructor must be private, which ensures that class can only be instantiated and destroyed from within the class itself.
- There must be a static GetInstance method, which provides access to the single instance of the Singleton class. This uses lazy initialization, meaning it creates the instance only once when this method is called for the first time.
- Copy constructor and assignment operator must be deleted to prevent copying of the instance, ensuring there is only one instance.

An example of singleton design pattern can be found under creational/singleton directory. Logger is a good example for a singleton design pattern.
### 1.3 Object Pool
Object pool pattern is used to manage a pool/a collection of pre-initialized and reusable object. The main idea behind it is to avoid the overhead of creating and destroying objercts frequently by reusing them whenever needed. This can lead to performance improvements in scenarios where object creation and destruction are expensive operations. Object pool can be used for cases like database connection management, thread pool or network connections. 

An example of object pool design pattern can be found under creational/object-pool directory.
## 2. Structural Design Patterns
### 2.1 Adapter
Adapter pattern is used to make two incompatible interfaces work seamlessly. It acts as a bridge between two different interfaces, allowing them to collaborate without modifying their own source code. This pattern is useful when integrating legacy code or third party libraries. 

An example of adapter design pattern can be found under structural/adapter directory.
## 3. Behavioral Design Patterns
### 3.1 Observer
Observer pattern is a behavioral design pattern that defines a one-to-many dependency between objects, meaning that when one object changes its state, all its observers are notified and updated automatically. This pattern is used to build distributed event handling systems and it is a crucial part of many software architectures.
- Subject is the object that is being observed. It maintains a list of observers and notifies them of state changes.
- Observers are objects that are interested in the state changes of the subject. They register with the subhect to receive updates.

An example of observer design pattern can be found under behavioral/observer directory.
### 3.3 State
