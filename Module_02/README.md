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


