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


