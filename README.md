# C++ - Module 00

> Memory Allocation
> Pointers to members
> References
> Switch Statement

## C++ - Orthodox Canonical Form
 
- What Is the Orthodox Canonical Form? (OCF)

Is a set of conventions ruling the definition of classes in C++.

Generally, the OCF implementation of a class includes the following special member functions:

0. Default Constructor
- [Default Constructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/default_constructor)

A default constructor is a constructor which can be called with no arguments.

Syntax
```c++
// Declaration of a default constructor inside of class definition
class-name (parameter-list (optional));
// Definition of a default constructor inside of class definition.
class-name (parameter-list (optional)) function-body
// Definition of a default constructor outside of class definition (the class must contain a declaration
class-name ::class-name (parameter-list (optional)) function-body	
```

1. Destructor

Syntax
```c++
class-name-with-tilde ( parameter-list (optional) ) except (optional(C++11)) attr (optional(C++11))		
```
Special **member function** to be called when the **lifetime of an object** ends.

2. Copy Constructor

3. Copy Assignment


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

RAII is also known as SBRM : **Scope-Bound Resource Management**, after the basic use case where the lifetime of an RAII object end due to scope exit.

___

## ex00/
