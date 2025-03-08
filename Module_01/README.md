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


