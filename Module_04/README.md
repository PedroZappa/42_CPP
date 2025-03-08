# Module_04
> Subtype Polymorphism, abstract classes, interfaces

## Subtype Polymorphism

Subtype polymorphism, often referred to simply as polymorphism, allows objects of different derived classes to be treated as objects of a common base class. This is achieved through inheritance and the use of virtual functions.

* **Enables extensibility**: You can introduce new derived classes without modifying existing code.
* **Simplifies interface design**: Base classes define the interface, and derived classes implement it.

### Virtual Functions

* Functions in the base class that can be `overridden` by derived classes.
* Declared with the `virtual` keyword in the base class.
* Enables `runtime dispatch` (dynamic binding).

```c++
class Base {
public:
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Optional in C++98, implicit in C++11+
        std::cout << "Derived class display" << std::endl;
    }
};
```

### Pointers and References:

* A `base class pointer or reference` can refer to objects of the derived class.
* At runtime, the correct derived class function is called (if the function is virtual).

```c++
Base* obj = new Derived();
obj->display();  // Calls Derived::display() due to polymorphism.
```

### Dynamic Dispatch:

* The `vtable` (virtual table) mechanism determines the correct function to invoke at runtime, based on the actual type of the object.
* Each class with virtual functions maintains a vtable.

> Polymorphism only works with pointers and references, not with objects directly.
>
> Base class destructors should be declared as virtual to ensure proper cleanup in derived classes.

## Abstract Classes

An `abstract class` in C++ is a class that is designed to act as a base class and cannot be instantiated directly. It is primarily used to define a common interface for its derived classes.

### Pure Virtual Functions:

* A class becomes `abstract` if it has at least one pure virtual function.
* A `pure virtual function` is declared with `= 0` in the base class.

```c++
class AbstractClass {
public:
    virtual void display() = 0;  // Pure virtual function
};
```
### Inheritance:

* Abstract classes are meant to be inherited, and derived classes must implement the pure virtual functions.
* If a derived class does not implement all pure virtual functions, it also becomes an abstract class.

### Cannot Instantiate:

* You cannot create objects of an abstract class.
* You can, however, use pointers or references to an abstract class to work with derived class objects.

## Interfaces

In C++, an `interface` is not a distinct language construct but is typically implemented using `abstract classes` that contain only pure virtual functions. An interface provides a way to define a contract for classes, ensuring they implement specific methods.
 
### Pure Virtual Functions:

An interface consists solely of pure virtual functions (`= 0`), which means no function in an interface has an implementation.

```cpp
Copy code
class Interface {
public:
    virtual void method1() = 0;
    virtual void method2() = 0;
};
```

### No Data Members:

* An interface **should not have data members** to align with the design principle of defining behavior only.
* This keeps the interface lightweight and focused on the contract it enforces.

### Cannot Be Instantiated:

* Like abstract classes, interfaces cannot be instantiated directly. They must be implemented by derived classes.

### Interface Inheritance:

* A class implements an interface by inheriting from it and providing definitions for all its pure virtual functions.
* C++ allows multiple inheritance, enabling a class to implement multiple interfaces.

### Interface Polymorphism:

* Interfaces allow for `runtime polymorphism`. A base class pointer or reference (representing the interface) can be used to interact with derived class objects that implement the interface.

```c++
class Interface {
public:
    virtual void function1() = 0;  // Pure virtual function
    virtual void function2() = 0;  // Pure virtual function

    virtual ~Interface() {}  // Virtual destructor
};

class Implementation : public Interface {
public:
    void function1() override {
        std::cout << "Implementation of function1" << std::endl;
    }

    void function2() override {
        std::cout << "Implementation of function2" << std::endl;
    }
};
```

### Advantages of Interfaces

* `Decoupling`: Encourages dependency on abstractions rather than concrete implementations.
* `Extensibility`: New classes can be added easily as long as they conform to the interface.
* `Polymorphism`: Enables runtime behavior based on the actual type of the object implementing the interface.

| **Aspect**        | **Interface**                           | **Abstract Class**                          |
|--------------------|-----------------------------------------|---------------------------------------------|
| **Content**        | Only pure `virtual functions`.           | Can have both `pure virtual` and `concrete functions`. |
| **Inheritance**    | Typically used for `multiple inheritance`. | Supports `single` and `multiple inheritance`.   |
| **Data Members**   | No data members allowed.               | Can have data members.                      |
| **Usage**          | Defines a `strict contract` for derived classes. | Provides `partial implementation` to be shared. |

___


