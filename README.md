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
### 1.2 Singleton
### 1.3 Object Pool

## 2. Structural Design Patterns
### 2.1 Adapter

## 3. Behavioral Design Patterns
### 3.1 Command
### 3.2 Observer
### 3.3 State
