# C++ Modules
<!-- mtoc-start -->

* [C++ - Module 00](#c---module-00)
  * [Strings](#strings)
  * [Namespaces](#namespaces)
  * [Classes](#classes)
  * [Encapsulation](#encapsulation)
  * [Member Functions](#member-functions)
    * [Special Member Functions](#special-member-functions)
    * [Static Member Functions](#static-member-functions)
    * [Const Member Functions](#const-member-functions)
    * [Overloaded Functions](#overloaded-functions)
    * [Virtual functions](#virtual-functions)
    * [Friend Functions](#friend-functions)
    * [Inline Functions](#inline-functions)
    * [Operator Overloading](#operator-overloading)
  * [stdio streams](#stdio-streams)
  * [Initialization Lists](#initialization-lists)
  * [Static](#static)
  * [Const](#const)
  * [What Is the Orthodox Canonical Form? (OCF)](#what-is-the-orthodox-canonical-form-ocf)
  * [Lifetime](#lifetime)
    * [What Is Lifetime?](#what-is-lifetime)
    * [What is **RAII**? (Resource Acquisition Is Initialization)](#what-is-raii-resource-acquisition-is-initialization)
* [Module_01](#module_01)
* [Module_02](#module_02)
* [Module_03](#module_03)
* [Module_04](#module_04)
* [Module_05](#module_05)
* [Module_06](#module_06)
* [Module_07](#module_07)
* [Module_08](#module_08)
* [Module_09](#module_09)

<!-- mtoc-end -->
___
# C++ - Module 00
- Namespaces, classes, member functions, stdio streams, initialization lists, static, const, & other basic stuff

___
## Strings

- [Strings - cppreferece.com](https://en.cppreference.com/w/cpp/string)
- [Null-terminted byte strings - cppreferece.com](https://en.cppreference.com/w/cpp/string/byte)

___
## Namespaces

> A namespace is a declarative region that provides a scope to the identifiers (such as variables, functions, classes) it contains.
>
> It helps group logically related entities and prevents clashes when different parts of a program define identifiers with the same name.
>
> Using namespaces ensures cleaner and more maintainable code, especially in complex projects.

___
## Classes

> Classes are blueprints for creating objects, encapsulating data (`attributes`) and behaviors (`methods`) into a single unit.

* A class defines a type by bundling `data` and `functions` together.

* An `object` is an instance of a class, created using the class blueprint.

___
## Encapsulation

> Classes control access to data using access specifiers:

* `public`: Accessible from outside the class.
* `private`: Accessible only within the class.
* `protected`: Accessible within the class and its derived classes.

___
## Member Functions

* Can directly access and modify `private` or `protected` attributes of the class.

___
### Special Member Functions

0. Default Constructor
- [Default Constructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/default_constructor)

A default constructor is a constructor which can be called with no arguments.

Automatically called when an object is created; used to initialize data.

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

> A destructor is a special member function that is called when the lifetime of an object ends.
>
> The purpose of the destructor is to free the resources that the object may have acquired during its lifetime.

```c++
class-name-with-tilde ( parameter-list (optional) ) except (optional(C++11)) attr (optional(C++11))
```
Special **member function** to be called when the **lifetime of an object** ends.

Automatically called when an object is destroyed; used for cleanup.

___
2. Copy Constructor
- [Copy Constructor - cppreferece.com](https://en.cppreference.com/w/cpp/language/copy_constructor)

A copy constructor is a constructor which can be called with an argument of the same class type and copies the content of the argument without mutating the argument

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

4. Move Constructor

...

5. Move Assignment

...

___
### Static Member Functions
> Operate independently of specific objects and access only static members

* `Static member functions` belong to the class rather than any specific instance of the class. This means they can be called without creating an object of the class and operate on static data members or perform actions independent of class instances.

```c++
static void displayCount();
```

> `Class-Level Scope`
>
> Static functions are associated with the class, not with individual objects. 
>
> They do not have access to non-static members of the class because they do not operate on an object.

* Can be called using the class name or an object.

```c++
MyClass::staticFunction();
MyClass obj;
obj.staticFunction(); // Works but is less common
```

* Since static functions are not tied to any object, they do not have a `this` pointer.

* Can directly access and modify static data members of the class.

```c++
class MyClass {
private:
    static int staticVar;

public:
    static void modifyStaticVar(int value) {
        staticVar = value; // Access static member
    }
};
```

* They cannot directly access non-static attributes or call non-static member functions, as those require an instance of the class.

> `Common Use Cases`
>
> Utility or helper functions related to the class but not specific to any object.
>
> Managing shared resources across all instances (e.g., counting objects, managing shared states).

* Useful for operations that do not depend on instance-specific data.

* Encapsulate utility functions within the class for logical grouping.

___
### Const Member Functions

* Ensure the function does not modify the object.

```c++
int getValue() const;
```
___
### Overloaded Functions

* Enable multiple functions with the same name but different parameters.

```c++
void print(int x);
void print(double y);
```
___
### Virtual functions

* Support polymorphism, allowing derived classes to override base class methods.

```c++
virtual void print();
```
___
### Friend Functions

* Can grant external functions access to private/protected members while maintaining encapsulation.

```c++
friend void print();
```
___
### Inline Functions

* Define short functions within the class definition for performance optimization.

```c++
inline void print();
```
___
### Operator Overloading

* Extend operator behavior for user-defined types.

```c++
MyClass operator+(const MyClass& other);
```
___
## stdio streams

___
## Initialization Lists

___
## Static

___
## Const


___
## What Is the Orthodox Canonical Form? (OCF)

It's a set of conventions ruling the definition of classes in C++.

Generally, the OCF implementation of a class includes the following special member functions:
- The **default constructor**;
- The **destructor**;
- The **copy constructor**;
- The **copy assignment**;

These special member functions will be called, if accessible, and if they are not user-defined, they are implicitly defined by the compiler.

___
## Lifetime

### What Is Lifetime?

In C++ every object/reference has a **lifetime**, the length of time between its creation and its destruction.
The **lifetime of an object** starts when:

- Properly aligned memory is **allocated**;
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

# Module_01
- Memory allocation, pointers to members, references, switch statement


___

# Module_02
- Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

___

# Module_03
- Inheritance

___

# Module_04
- Subtype Polymorphism, abstract classes, interfaces

___

# Module_05
- Repetition and Exceptions

___

# Module_06
- C++ cast

___

# Module_07
- C++ Templates

___

# Module_08
- Templated containers, iterators, algorithms

___

# Module_09
- STL

