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
    * [Virtual functions](#virtual-functions)
      * [Virtual Table (vtable)](#virtual-table-vtable)
      * [Pure virtual functions](#pure-virtual-functions)
    * [Friend Functions](#friend-functions)
    * [Inline Functions](#inline-functions)
    * [Operator Overloading](#operator-overloading)
  * [C++98 I/O Streams](#c98-io-streams)
  * [Initialization Lists](#initialization-lists)
  * [What Is the Orthodox Canonical Form? (OCF)](#what-is-the-orthodox-canonical-form-ocf)
  * [Lifetime](#lifetime)
    * [What Is Lifetime?](#what-is-lifetime)
    * [What is **RAII**? (Resource Acquisition Is Initialization)](#what-is-raii-resource-acquisition-is-initialization)
* [Module_01](#module_01)
  * [Memory Allocation](#memory-allocation)
    * [Static Momory Allocation](#static-momory-allocation)
    * [Dynamic Memory Allocation](#dynamic-memory-allocation)
    * [Memory Regions in C++](#memory-regions-in-c)
  * [Pointers to Member Variables](#pointers-to-member-variables)
    * [Accessing via Object](#accessing-via-object)
    * [Accessing via Pointer to Object](#accessing-via-pointer-to-object)
  * [Pointers to Member Functions](#pointers-to-member-functions)
    * [Calling a Member Function via Object](#calling-a-member-function-via-object)
    * [Calling a Member Function via Pointer to Object](#calling-a-member-function-via-pointer-to-object)
  * [References](#references)
    * [Types of References](#types-of-references)
    * [Pointers vs References](#pointers-vs-references)
* [Module_02](#module_02)
  * [Ad-hoc Polymorphism](#ad-hoc-polymorphism)
    * [Function Overloading](#function-overloading)
      * [Advantages of Function Overloading:](#advantages-of-function-overloading)
  * [Orthodox Canonical Form](#orthodox-canonical-form)
    * [Default Constructor](#default-constructor)
    * [Destructor](#destructor)
    * [Copy Constructor](#copy-constructor)
    * [Copy Assignment Operator](#copy-assignment-operator)
    * [Move Constructor (C++11)](#move-constructor-c11)
    * [Move Assignment Operator (C++11)](#move-assignment-operator-c11)
* [Module_03](#module_03)
  * [Basics of Inheritance](#basics-of-inheritance)
  * [Types of Inheritance](#types-of-inheritance)
    * [Single Inheritance](#single-inheritance)
    * [Multiple Inheritance](#multiple-inheritance)
    * [Multilevel Inheritance](#multilevel-inheritance)
    * [Hierarchical Inheritance](#hierarchical-inheritance)
    * [Hybrid Inheritance: ](#hybrid-inheritance-)
    * [Access Control in Inheritance](#access-control-in-inheritance)
  * [Overriding and Polymorphism](#overriding-and-polymorphism)
    * [Function Overriding ](#function-overriding-)
    * [Virtual Functions and Polymorphism](#virtual-functions-and-polymorphism)
    * [Constructors and Destructors in Inheritance](#constructors-and-destructors-in-inheritance)
      * [Base Class Constructor](#base-class-constructor)
    * [Destructor](#destructor-1)
  * [Scope Resolution](#scope-resolution)
  * [Ambiguity in Multiple Inheritance](#ambiguity-in-multiple-inheritance)
  * [Virtual Inheritance](#virtual-inheritance)
* [Module_04](#module_04)
  * [Subtype Polymorphism](#subtype-polymorphism)
    * [Virtual Functions](#virtual-functions-1)
    * [Pointers and References:](#pointers-and-references)
    * [Dynamic Dispatch:](#dynamic-dispatch)
  * [Abstract Classes](#abstract-classes)
    * [Pure Virtual Functions:](#pure-virtual-functions-1)
    * [Inheritance:](#inheritance)
    * [Cannot Instantiate:](#cannot-instantiate)
  * [Interfaces](#interfaces)
    * [Pure Virtual Functions:](#pure-virtual-functions-2)
    * [No Data Members:](#no-data-members)
    * [Cannot Be Instantiated:](#cannot-be-instantiated)
    * [Interface Inheritance:](#interface-inheritance)
    * [Interface Polymorphism:](#interface-polymorphism)
    * [Advantages of Interfaces](#advantages-of-interfaces)
* [Module_05](#module_05)
  * [Throwing Exceptions](#throwing-exceptions)
    * [Catching Exceptions](#catching-exceptions)
    * [Exception Class Hierarchy](#exception-class-hierarchy)
    * [Re-throwing Exceptions:](#re-throwing-exceptions)
    * [Stack Unwinding:](#stack-unwinding)
    * [Important Considerations](#important-considerations)
* [Module_06](#module_06)
  * [Static Cast](#static-cast)
  * [Dynamic Cast](#dynamic-cast)
  * [Const Cast](#const-cast)
  * [Reinterpret Cast](#reinterpret-cast)
  * [Summary](#summary)
* [Module_07](#module_07)
  * [Templates ](#templates-)
    * [Function Templates](#function-templates)
    * [Class Templates](#class-templates)
    * [Template Parameters](#template-parameters)
      * [Non-Type Template Parameters;](#non-type-template-parameters)
      * [Template Instantiation](#template-instantiation)
      * [Template Specialization](#template-specialization)
        * [Full Specialization](#full-specialization)
      * [Partial Specialization](#partial-specialization)
  * [SFINAE (Substitution Failure Is Not An Error)](#sfinae-substitution-failure-is-not-an-error)
* [Module_08](#module_08)
* [Module_09](#module_09)

<!-- mtoc-end -->
___
# C++ - Module 00
> Namespaces, classes, member functions, stdio streams, initialization lists, static, const, & other basic stuff

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

* Ensure the function does not modify the object. They are crucial for maintaining the integrity of objects when they are accessed in a read-only context.

```c++
int getValue() const;
```

* The `const` keyword indicates that the function will not alter the object's state (i.e., it won't modify non-static member variables or call non-const member functions).

* Enforces `Const Correctness`, ensuring that the function can be called on const objects, guaranteeing read-only access to the object's data.

___
### Virtual functions

* Virtual functions enable runtime polymorphism, allowing derived classes to override base class methods. They enable dynamic method dispatch.

* A member function in a base class is declared `virtual` to allow overriding in derived classes.

```c++
class Base {
public:
    virtual void display() {
        cout << "Base class display" << endl;
    }
};
```
* A derived class can provide its own implementation of the virtual function.

```c++
class Derived : public Base {
public:
    void display() override { // Optional: `override` clarifies intent
        cout << "Derived class display" << endl;
    }
};
```
> Using override is optional but improves clarity and catches errors if no base class function exists to override.

* When a base class pointer or reference points to a derived object, the derived class's implementation is called at runtime.

```c++
Base* obj = new Derived();
obj->display(); // Calls Derived's display
```
#### Virtual Table (vtable)

* Virtual functions rely on a mechanism called the `vtable`, a table of pointers to virtual functions.

* Each class with virtual functions has its own `vtable`, and objects maintain a pointer to the `vtable`.

* Unlike non-virtual functions (statically bound at compile time), virtual functions are resolved at runtime based on the actual type of the object.

* A base class with virtual functions should also declare its destructor as virtual to ensure proper cleanup of derived objects.

```c++
virtual ~Base() {}
```

#### Pure virtual functions

* A virtual function can be made `pure` by assigning `= 0`. This makes the class abstract, meaning it cannot be instantiated.

```c++
class AbstractClass {
public:
    virtual void func() = 0; // Pure virtual function
};
```
* Virtual functions are fundamental for achieving polymorphism, where derived classes can replace base class functionality at runtime.
    * `Runtime Flexibility`: Allows behavior to depend on the actual object type at runtime.
    * `Code Reusability`: Base class pointers/references can work with multiple derived types.
    * `Cleaner Design`: Encapsulates logic for specific behavior within derived classes.

* Pure virtual functions are used to enforce abstract classes and provide runtime polymorphism.
___
### Friend Functions

* Can grant external functions access to private/protected members while maintaining encapsulation.

```c++
friend void print();
```

- Is a function that is not a member of a class but has access to its `private` and `protected` members. Declaring a function as a friend is done using the `friend` keyword inside the class.

___
### Inline Functions

* Define short functions within the class definition for performance optimization.

```c++
inline void print();
```

* The function's code is directly substituted at its call site, avoiding the overhead of a function call. This substitution happens during compilation.
    - **Improves performance** by eliminating function call overhead for small, frequently-used functions.
    - Modern compilers **automatically inline functions** they deem suitable, even without the inline keyword.

> :NOTE: The inline keyword is a hint, not a command; the compiler decides whether to inline or not.

___
### Operator Overloading

* Extend operator behavior for user-defined types.

```c++
MyClass operator+(const MyClass& other);
```

- Is the process of redefining the behavior of operators (e.g., `+`, `-`, `==`) for user-defined types, enabling them to work with objects in a custom way while maintaining intuitive syntax.

___
## C++98 I/O Streams

> C++98 divides I/O streams into several categories based on their purpose:

1. **Console I/O**:

> Handled via standard streams:
* `std::cin`: Standard input (console input).
```c++
int a;
std::cin >> a; // Read an integer from console
```

* `std::cout`: Standard output (console output).
```c++
std::cout << "Hello, World!" << std::endl; // Print a string with newline
```

* `std::cerr`: Standard error stream (unbuffered).
```c++
std::cerr << "Error!" << std::endl;
```

* `std::clog`: Standard log stream (buffered).
```c++
std::clog << "Log message" << std::endl;
```

2. **File I/O**

> Handled by file stream classes:
* `std::ifstream`: Input file stream (for reading from files).
* `std::ofstream`: Output file stream (for writing to files).
```cpp
std::ofstream outFile("output.txt");
outFile << "Hello, File!" << std::endl; // Write to file
outFile.close();

std::ifstream inFile("output.txt");
std::string content;
inFile >> content; // Read from file
std::cout << content << std::endl;
inFile.close();
```
* `std::fstream`: File stream for both input and output.

3. **String Streams**:

Used for string-based I/O:
* `std::istringstream`: Input stream from a string.
* `std::ostringstream`: Output stream to a string.
* `std::stringstream`: Bidirectional string stream.
```c++
std::ostringstream oss;
oss << "Number: " << 42;
std::string result = oss.str(); // Output: "Number: 42"

std::istringstream iss("123 456");
int x, y;
iss >> x >> y; // Parse integers from string
```

4. **Stream Buffers**:

Classes that handle low-level buffering:

* `std::streambuf`: Base class for all stream buffers.
```c++
std::ofstream logFile("log.txt");
std::streambuf* originalBuf = std::cout.rdbuf(); // Save original buffer
std::cout.rdbuf(logFile.rdbuf()); // Redirect std::cout to logFile

std::cout << "Logging to file now!" << std::endl;

std::cout.rdbuf(originalBuf); // Restore original buffer
```

* Derived classes (e.g., `std::filebuf`) support specific sources like files.

5. **Error States**:

Streams have error handling built-in:
* `eof()`: Check if the end-of-file is reached.
* `fail()`: Check if a logical error occurred.
* `bad()`: Check if a serious error occurred.
* `clear()`: Reset error flags.

> Checking stream state:
```c++
std::ifstream file("nonexistent.txt");
if (!file) {
    std::cerr << "Error opening file!" << std::endl;
}
```

> Clear error state:
```c++
file.clear(); // Reset error flags
```

6. **Manipulators**:

Format and manipulate I/O:
* Standard manipulators (e.g., `std::endl`, `std::setw`, `std::setprecision`).
```c++
std::cout << std::hex << 255 << std::endl; // Output: "ff" (hexadecimal)
std::cout << std::setw(5) << std::setfill('0') << 42 << std::endl; // Output: "00042"

std::cout << std::fixed << std::setprecision(2) << 3.14159 << std::endl; // Output: 3.14
```
* User-defined manipulators for custom behavior.

___

## Initialization Lists

- Is used to initialize class member variables directly **at the time of object creation**, before the constructor body is executed. 

- It is used in the constructor declaration and is efficient for initializing members.

```c++
ClassName(parameters) : member1(value1), member2(value2) {
    // Constructor body
}
```
* Initializes members directly, avoiding default construction followed by reassignment.
* Initializes `const` or `reference` (`&`) members (which must be initialized at creation).
* Initializes base classes in derived classes.
* Providing better performance for complex objects.
* Members are initialized in the order of their declaration in the class, not the order in the initialization list.

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
> Memory allocation, pointers to members, references, switch statement

## Memory Allocation

### Static Momory Allocation

* Memory allocated at compile time.
* The memory is fixed and bound to the variable for its lifetime, typically the program's `lifetime` (for global/static variables) or the scope of the function (for local variables).

> * Memory size is known beforehand.
> * Cannot be resized during runtime.
> * Faster access as it is allocated and deallocated automatically by the compiler. 

### Dynamic Memory Allocation

* Memory allocated at runtime using the `heap`.
* Useful when the size of the data structure isn't known at compile time or needs to change dynamically.

> * `new`: Allocates memory for an object or an array.
> * `delete`: Deallocates memory for an object.
> * `delete[]`: Deallocates memory for an array.

### Memory Regions in C++

1. Code Segment (Text Segment):

> Stores executable instructions of the program.
> Read-only to prevent accidental modifications.

2. Stack:

> Stores local variables and function call information.
> Operates in a `LIFO` (Last In, First Out) manner.
> Grows and shrinks automatically with function calls and returns.
> Size is limited; excessive recursion can cause a stack overflow.

3. Heap:

> Stores dynamically allocated memory.
> Managed manually by the programmer using new and delete.
> Offers flexibility but requires careful management.

4. Global/Static Segment:

> Stores global and static variables.
> Lifetime lasts the entire program's execution.

## Pointers to Member Variables

Unlike regular pointers, pointers to members are specialized to work with class members (functions or variables) and need to be handled slightly differently.

* `Pointers to Data Members`: point to non-static data members of a class.
* `Pointers to Member Functions`: point to non-static member functions of a class.

Declaring a pointer to a `member variable`:
```c++
Type ClassName::*pointerName;
```
To access the member through the pointer, you need an object and use the .* (dot-star) operator for non-pointer objects, or ->* for pointers to objects.

### Accessing via Object

```c++
MyClass obj;
obj.x = 10;
std::cout << obj.*ptr;  // Access the 'x' member through the pointer
```

### Accessing via Pointer to Object

```c++
MyClass* pObj = &obj;
std::cout << pObj->*ptr;  // Access the 'x' member through the pointer
```

## Pointers to Member Functions

To declare a pointer to a member function, the syntax is:
```c++
ReturnType (ClassName::*pointerName)(Args...);
```

### Calling a Member Function via Object

```c++
MyClass obj;
(obj.*ptr)();  // Call 'printHello' through the pointer
```

### Calling a Member Function via Pointer to Object

```c++
MyClass* pObj = &obj;
(pObj->*ptr)();  // Call 'printHello' through the pointer
```

## References

* `Cannot Be Null`

A reference must always refer to an object or variable; it cannot be null. If a reference is initialized, it must refer to a valid memory location.* Must Be Initialized

```c++
int& ref = someVariable;  // Always valid
```

* `Must Be Initialized`

References must be initialized when they are declared. Unlike pointers, you cannot declare a reference without assigning it to an object.

```c++
int x = 5;
int& ref = x;  // ref is initialized and must always refer to 'x'
```

* `No Rebinding`

Once a reference is initialized, it cannot be made to refer to another variable. A reference is bound to the variable it was initialized with, and it cannot be changed to refer to something else.

```c++
int x = 10, y = 20;
int& ref = x;
ref = y;  // ref now holds the value 20, but it still refers to x
```
* `Automatic Dereferencing`

A reference automatically dereferences the variable it refers to. You don’t need to use the dereference operator (`*`) like with pointers. This makes using references more convenient than pointers in many cases.

```c++
int x = 10;
int& ref = x;
ref = 20;  // Equivalent to: x = 20;
```

### Types of References

* `Lvalue` Reference

An lvalue reference is a reference to an lvalue (an object that persists beyond a single expression). The most common form of reference in C++.

```c++
int x = 5;
int& ref = x;  // ref is an lvalue reference to x
```

* `Rvalue` Reference

An rvalue reference is a reference to an rvalue (a temporary object or an object that does not persist beyond an expression, like the result of an arithmetic operation).

> `Rvalue` references are declared with `&&` (double ampersand).

```c++
int&& rref = 10;  // rref is an rvalue reference to a temporary object (10)
```

* `Const` Reference

A const reference is a reference that cannot be used to modify the referred object. It is declared using `const` before the type.

> They allow you to avoid copying large objects (like large containers or classes) while ensuring that the object cannot be modified.
> They can bind to both `lvalues` and `rvalues`.

```c++
int x = 10;
const int& ref = x;  // ref is a constant reference to x
```

### Pointers vs References

| Feature              | Reference                             | Pointer                           |
|----------------------|---------------------------------------|-----------------------------------|
| `Initialization`       | Must be initialized when declared     | Can be uninitialized or null     |
| `Rebinding`            | Cannot be reassigned to a different variable | Can be reassigned to point to different objects |
| `Dereferencing`        | Implicit dereferencing                | Requires explicit dereferencing with `*` |
| `Nullability`          | Cannot be null                        | Can be null                      |

___

# Module_02
> Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

## Ad-hoc Polymorphism

Ad-hoc polymorphism is a type of polymorphism in C++ (and other programming languages) where a function or operator behaves differently depending on the type of its arguments. It is the simplest form of polymorphism and is achieved through `function overloading` and `operator overloading`.

In contrast to `subtype polymorphism` (also called inheritance-based polymorphism), which involves `subclassing` and `inheritanc`e, ad-hoc polymorphism doesn't require a hierarchy of classes. Instead, it allows multiple functions or operators with the same name to behave differently based on their arguments' types or the number of arguments passed to them.

### Function Overloading

Function overloading is the most common example of ad-hoc polymorphism. It occurs when multiple functions have the same name but differ in their `parameter types`, `number of parameters`, or `order of parameters`.

* Enable multiple functions with the same name but different parameters.

```c++
void print(int x);
void print(double y);
```
* Overloaded functions must have the same name but different parameter lists.

* Parameter differences can include:
    * The `number` of parameters.
    * The `types` of parameters.
    * The `order` of parameters.

```c++
#include <iostream>
using namespace std;

class Calculator {
public:
    // Add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Add three integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Add two doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    cout << "Add two integers: " << calc.add(2, 3) << endl;          // Calls add(int, int)
    cout << "Add three integers: " << calc.add(2, 3, 4) << endl;    // Calls add(int, int, int)
    cout << "Add two doubles: " << calc.add(2.5, 3.5) << endl;      // Calls add(double, double)

    return 0;
}
```
#### Advantages of Function Overloading:

1. `Improves Code Readability`:

*  The same function name can be reused for logically similar operations, making the code easier to understand.

2. `Enhanced Functionality`:

* You can define specialized versions of the same operation for different parameter types or combinations.

3. `Flexibility`:

* Enables a function to handle multiple use cases (e.g., adding integers, floats, or other data types).


## Orthodox Canonical Form

Is a set of functions that are typically implemented in a class to manage its resource ownership properly. These functions ensure correct `construction`, `destruction`, `copying`, and `moving` of objects and are especially important when a class owns dynamically allocated resources.

`The Orthodox Canonical Form` ensures that:

* **Resource management** is handled correctly, `avoiding memory leaks` or `dangling pointers`.
* `Copying` and `assignment` behave predictably and **do not result in shallow copies when deep copies are required**.
* **Performance is optimized** by transferring ownership of resources in move operations rather than duplicating them unnecessarily.

### Default Constructor

A constructor that allows creating an object without passing any arguments. It initializes the object to a valid state.

```c++
class MyClass {
public:
    MyClass() {
        // Initialize the object
    }
};
```

### Destructor

Ensures proper cleanup of resources when the object is destroyed.

```c++
~MyClass() {
    // Release resources
}
```

### Copy Constructor

Defines how an object is copied when passed by value or initialized from another object of the same type. It performs a `deep copy` if the class owns resources.

```c++
MyClass(const MyClass& other) {
    // Copy resources from 'other'
}
```

### Copy Assignment Operator

Defines how an object is assigned from another object of the same type. It performs a deep copy and handles self-assignment.

```c++
MyClass& operator=(const MyClass& other) {
    if (this != &other) {
        // Release current resources
        // Copy resources from 'other'
    }
    return *this;
}
```

### Move Constructor (C++11)

Defines how resources are transferred from a temporary object (rvalue) to a new object.

```c++
MyClass(MyClass&& other) noexcept {
    // Transfer resources from 'other' to 'this'
    // Leave 'other' in a valid but unspecified state
}
```

### Move Assignment Operator (C++11)

Defines how resources are transferred during assignment from a temporary object (rvalue).

```c++
MyClass& operator=(MyClass&& other) noexcept {
    if (this != &other) {
        // Release current resources
        // Transfer resources from 'other' to 'this'
    }
    return *this;
}
```

___

# Module_03
> Inheritance

## Basics of Inheritance

Inheritance allows a class (`derived class`) to reuse and extend the functionality of another class (`base class`).

```c++
class Base {
   // Base class members
};

class Derived : access_specifier Base {
   // Derived class members
};
```

* **Access Specifier**:
    * `public`: Public and protected members of the base class retain their access levels in the derived class.
    * `protected`: Public and protected members of the base class become protected in the derived class.
    * `private`: Public and protected members of the base class become private in the derived class.

## Types of Inheritance

### Single Inheritance

A class derives from a single base class.

```c++
class A {};
class B : public A {};
```

### Multiple Inheritance

A class derives from multiple base classes.

```c++
class A {};
class B {};
class C : public A, public B {};
```

### Multilevel Inheritance

A class derives from another derived class.

```c++
class A {};
class B : public A {};
class C : public B {};
```

### Hierarchical Inheritance

Multiple classes derive from a single base class.

```c++
class A {};
class B : public A {};
class C : public A {};
```

### Hybrid Inheritance: 

A combination of the above types, often involving multiple and hierarchical inheritance.

### Access Control in Inheritance

| **Base Class Member** | **Public Inheritance** | **Protected Inheritance** | **Private Inheritance** |
|------------------------|------------------------|----------------------------|--------------------------|
| **Public**            | Public                | Protected                  | Private                  |
| **Protected**         | Protected             | Protected                  | Private                  |
| **Private**           | Not Inherited         | Not Inherited              | Not Inherited            |
`Private members of the base class` are not accessible directly by the derived class, but they can be accessed through public/protected methods in the base class.


## Overriding and Polymorphism

### Function Overriding 

A derived class can redefine a base class function. The base class function must be marked as `virtual` for proper runtime polymorphism.

```c++
class Base {
public:
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {  // C++98 does not require the `override` keyword, but it's good practice.
        std::cout << "Derived class display" << std::endl;
    }
};
```

### Virtual Functions and Polymorphism

* A **virtual function** allows runtime binding, enabling polymorphism.
* **Virtual Table** (`vtable`): C++ uses vtables for runtime function resolution in polymorphism.
* **Pure Virtual Functions**: A virtual function declared with `= 0` is `pure virtual`, making the class abstract.


### Constructors and Destructors in Inheritance

#### Base Class Constructor

* The base class constructor is called before the derived class constructor.
* The derived class must explicitly invoke non-default base class constructors:

```c++
class Base {
public:
    Base(int x) { std::cout << "Base constructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived(int x, int y) : Base(x) {
        std::cout << "Derived constructor" << std::endl;
    }
};
```

### Destructor

If a base class destructor is declared as `virtual`, the derived class destructor is invoked correctly during object destruction.

```c++
class Base {
public:
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};
```

##  Scope Resolution
The `::` operator can access base class members that are hidden by derived class members.


```c++
class Base {
public:
    int value = 10;
};

class Derived : public Base {
public:
    int value = 20;
    void display() {
        std::cout << "Base value: " << Base::value << std::endl;
        std::cout << "Derived value: " << value << std::endl;
    }
};
```

## Ambiguity in Multiple Inheritance

Ambiguity arises when a derived class inherits multiple base classes with members of the same name.

> `Solution`: Use the scope resolution operator.

```c++
class A {
public:
    void show() { std::cout << "A's show" << std::endl; }
};

class B {
public:
    void show() { std::cout << "B's show" << std::endl; }
};

class C : public A, public B {
public:
    void display() {
        A::show();
        B::show();
    }
};
```

## Virtual Inheritance

Resolves the `diamond problem` in multiple inheritance by ensuring that the base class is shared among all derived classes.

```c++
class A {
public:
    int value;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {
    // A is shared, no duplication of 'value'
};
```
___

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

# Module_05
> Repetition and Exceptions

Exceptions provide a mechanism for handling errors and other exceptional conditions in a structured way.

### Throwing Exceptions


* An exception is thrown using the `throw` keyword.

```c++
throw std::runtime_error("Error occurred!");
```

* Can throw any object, but typically an `exception class` (e.g., `std::exception` or derived types) is used.


### Catching Exceptions

* Exceptions are caught using `try` and `catch` blocks.

```c++
try {
    // Code that might throw an exception
    throw std::runtime_error("Something went wrong!");
} catch (const std::exception& e) {
    // Handle the exception
    std::cout << "Caught exception: " << e.what() << std::endl;
}
```

### Exception Class Hierarchy

* The standard library provides `std::exception` as the base class for all standard exceptions.
* Common derived classes include:
    * `std::runtime_error``
    * `std::logic_error`
    * `std::bad_alloc` (thrown by new on memory allocation failure)
* You can define your own exception classes.

### Re-throwing Exceptions:

You can rethrow a caught exception with `throw`; inside a `catch` block.

```cpp
try {
    // Some code
} catch (const std::exception& e) {
    // Log or partially handle
    throw; // Re-throw the exception
}
```

### Stack Unwinding:

* When an exception is thrown, the runtime performs `stack unwinding`:
    * Destructors for all objects in the current scope are called in reverse order of their creation.

### Important Considerations

* Avoid Throwing from Destructors

Throwing an exception from a destructor during stack unwinding causes `std::terminate()` to be called.

* Uncaught Exceptions

If an exception is thrown and not caught, `std::terminate()` is called.

* Catch-All Handler:

Use `catch(...)` to catch any type of exception:

```c++
try {
    // Some code
} catch (...) {
    std::cout << "Unknown exception caught." << std::endl;
}
```

* Performance:

Exception handling can have a performance cost, so use exceptions for exceptional conditions, not regular control flow.

___

# Module_06
> C++ cast

C++ provides four main types of casts to handle conversions between different types or to control type conversions explicitly. Each has a specific purpose and level of safety.

## Static Cast

Performs compile-time checks and conversions between compatible types.

* Converting between related pointer types (e.g., upcasting/downcasting in inheritance hierarchies).
* Converting numerical types (e.g., `int` to `float`).
* Explicit conversions like void pointer to another pointer type.

Safer than C-style casts but still requires developer care.
No runtime checks; improper use may lead to undefined behavior.

## Dynamic Cast

Used for safe type casting in polymorphism, with runtime type checking.

Useful for upcasting/downcasting pointers or references in class hierarchies.

Requires at least one class in the hierarchy to have a `virtual` function (usually a `virtual` destructor).
Returns `nullptr` for invalid casts when used with pointers.
Throws `std::bad_cast` exception for invalid casts when used with references.

## Const Cast

Adds or removes the const qualifier.

To modify a `const` variable (if it was originally not `const`).
Useful when interfacing with APIs requiring non-const pointers but your data is logically constant.

Only affects `const` or `volatile` qualifiers, not the underlying type.
Modifying a truly `const` object results in undefined behavior.

## Reinterpret Cast

Purpose: Provides low-level casting by reinterpreting the bit pattern of an object.

Casting unrelated pointer types (e.g., `int*` to `char*`).
Casting between function pointers or integer types and pointers.

Most dangerous of all casts; should be avoided unless absolutely necessary.
No type safety or guarantees about the resulting value.

## Summary

| Cast Type          | Safety         | Purpose                                    | Example Use Case                           |
|---------------------|----------------|--------------------------------------------|-------------------------------------------|
| `static_cast`       | Compile-time   | Type-safe conversion between compatible types | `float` to `int` or `void*` to `int*`     |
| `dynamic_cast`      | Runtime        | Safe polymorphic downcasting               | Base pointer to Derived pointer           |
| `const_cast`        | Compile-time   | Remove/add `const`                         | Modifying a `const` function argument     |
| `reinterpret_cast`  | Low            | Low-level bit reinterpretation             | `int*` to `char*` or pointer to integer   |


___

# Module_07
> C++ Templates

## Templates 

* They enable the creation of `functions`, `classes`, and even `aliases` that work with any data type.

### Function Templates

Function templates allow you to write a single function that works for multiple data types.

```c++
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Usage
int main() {
    cout << add(5, 10) << endl;       // Works with integers
    cout << add(5.5, 10.2) << endl;   // Works with doubles
}
```

### Class Templates

```c++
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

// Usage
int main() {
    Box<int> intBox(42);         // Box for integers
    Box<string> strBox("Hello"); // Box for strings
    cout << intBox.getValue() << endl;
    cout << strBox.getValue() << endl;
}
```
> You can also use template `<class T>` instead of template `<typename T>`—both are equivalent.

### Template Parameters

Templates are parameterized by one or more `template parameters`, of three kinds: `non-type`, `type`, and `template`.

* The compiler deduces the type of the template arguments at compile time.

> For example, in `add(5, 10)`, the compiler deduces `T` as `int`.

#### Non-Type Template Parameters;
* Templates can take `non-type` parameters (e.g., integer values).

```c++
template <typename T, int N>
class Array {
    T arr[N];
public:
    void set(int index, T value) { arr[index] = value; }
    T get(int index) { return arr[index]; }
};

// Usage:
int main() {
    Array<int, 5> intArray;
    intArray.set(0, 42);
    cout << intArray.get(0) << endl; // Prints: 42
}
```
* When you use a template, the compiler generates a specific version of the template for the given type(s). This process is called `template instantiation`.

#### Template Instantiation

You can explicitly tell the compiler to instantiate a template for a specific type.

```c++
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Explicit instantiation for `int`
template int multiply<int>(int, int);
```
If you don't explicitly instantiate, the compiler automatically generates the required instantiation when you use the template.

#### Template Specialization

##### Full Specialization

This replaces the generic template entirely for a specific type.

```c++
template <typename T>
class Printer {
public:
    void print(T value) {
        cout << value << endl;
    }
};

// Specialized for `char`
template <>
class Printer<char> {
public:
    void print(char value) {
        cout << "Char: " << value << endl;
    }
};
```

#### Partial Specialization

This customizes the behavior for a subset of template parameters, particularly useful with class templates.

```c++
template <typename T, typename U>
class Pair {
    T first;
    U second;
public:
    Pair(T a, U b) : first(a), second(b) {}
};

// Partial specialization when both types are the same
template <typename T>
class Pair<T, T> {
    T first;
    T second;
public:
    Pair(T a, T b) : first(a), second(b) {}
};
```

## SFINAE (Substitution Failure Is Not An Error)

`SFINAE` is a rule in C++ that allows the compiler to silently ignore a template when its instantiation is invalid, instead of throwing a compilation error.

___

# Module_08
> Templated containers, iterators, algorithms

___

# Module_09
> STL

