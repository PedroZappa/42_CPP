# C++ - Module 00

> Namespaces

> Classes

> Member Functions

> stdio streams

> Initialization Lists

> Static

> Const

> & Other Basic Stuff

## What Is the Orthodox Canonical Form? (OCF)

It's a set of conventions ruling the definition of classes in C++.

Generally, the OCF implementation of a class includes the following special member functions:
- The **default constructor**;
- The **destructor**;
- The **copy constructor**;
- The **copy assignment**;

These special member functions will be called, if accessible, and if they are not user-defined, they are implicitly defined by the compiler.
___
0. Default Constructor
- [Default Constructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/default_constructor)

A default constructor is a constructor which can be called with no arguments.
```c++
// Declaration of a default constructor inside of class definition
class-name (parameter-list (optional));
// Definition of a default constructor inside of class definition.
class-name (parameter-list (optional)) function-body
// Definition of a default constructor outside of class definition (the class must contain a declaration
class-name::class-name (parameter-list (optional)) function-body	
```
___
1. Destructor
- [Destructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/destructor)

A destructor is a special member function that is called when the lifetime of an object ends. The purpose of the destructor is to free the resources that the object may have acquired during its lifetime.

```c++
class-name-with-tilde ( parameter-list (optional) ) except (optional(C++11)) attr (optional(C++11))		
```
Special **member function** to be called when the **lifetime of an object** ends.

___
2. Copy Constructor
- [Copy Constructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/copy_constructor)

A copy constructor is a constructor which can be called with an argument of the same class type and copies the content of the argument without mutating the argument.
```c++
// Declaration of a copy constructor inside of class definition
class-name (parameter-list );
// Definition of a copy constructor inside of class definition.
class-name (parameter-list) function-body
// Definition of a copy constructor outside of class definition
class-name::class-name (parameter-list) function-body
```

___
3. Copy Assignment
- [Copy Assignment - cppreferece.com](https://en.cppreference.com/w/cpp/language/copy_assignment)

A copy assignment operator is a non-template non-static member function with the name **operator=** that can be called with an argument of the same class type and copies the content of the argument without mutating the argument.
```c++
// Declaration of a copy assignment operator inside of class definition
return-type operator=(parameter-list);
// Definition of a copy assignment operator inside of class definition
return-type operator=(parameter-list) function-body
// Definition of a copy assignment operator outside of class definition
return-type class-name::operator=(parameter-list) function-body	
```

___
## Lifetime

### What Is Lifetime?

In C++ every object/reference has a **lifetime**, the length of time between its creation and its destruction.
The **lifetime of an object** starts when:

- Properly aligned memory is **allocated*;
- And its **initialization** is successfully completed;

The **lifetime of an object** ends when:

- The **destructor** is called;
- The **deallocated** memory is released, or is reused by an another object that is not nested in it.

The **lifetime** of an object is equal to or is nested within the lifetime of its storage.

### What is **RAII**? (Resource Acquisition Is Initialization)
- [RAII - cppreferece.com](https://en.cppreference.com/w/cpp/language/raii) 

Is a C++ programming technique which **binds the life cycle** of a resource that must be acquired before use to the **lifetime** of an object.
- Guarantees that the resource is available to any function that may access the object;
- Ensures that all resources are released when the lifetime of their controlling objects is over, in reverse order of acquisition.
- In case resource acquisition fails, all resources acquired by every fully-constructed member and base subobjects are released. in reverse order of initialization.

RAII takes advantage of core C++ features (such as: **object lifetime** , **scope exit**, **order of initialization** and **stack unwinding**), to eliminate resource leaks and guarantee **exception safety**.

RAII encapsulates each resource into a class where:
- the **constructor** acquires the resource and establishes all class variants or throws an exception if that cannot be done;
- the **destructor** releases the resource, never throwing exceptions;

RAII uses the resource via an instance of a RAII-class that either:
- has automatic storage duration, or temporary life itself, or,
- has lifetime that is bhounded by the lifetime of an automatic or temporary object;

RAII is also known as SBRM : **Scope-Bound Resource Management**, after the basic use case where the lifetime of an RAII object end due to scope exit.

___

## Exercise 00: BraiiiiiiinnnzzzZ


