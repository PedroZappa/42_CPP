# Exercise Documentation: easyfind Template Function

This exercise implements a generic `easyfind` function template that searches for a value in a container. The implementation demonstrates the use of C++ templates, exception handling, and standard containers.
<!-- mtoc-start -->

* [Overview](#overview)
* [Template Function](#template-function)
* [Exception Handling](#exception-handling)
* [Test Program](#test-program)
* [Helper Functions](#helper-functions)
* [Technical Notes](#technical-notes)
* [Usage Example](#usage-example)

<!-- mtoc-end -->
## Overview

The program consists of three main files:
- `main.cpp`: Contains the test program that demonstrates the functionality
- `easyfind.hpp`: Header file with template declarations and exception class
- `easyfind.tpp`: Template implementation file (referenced in the header)

## Template Function

The `easyfind` function template is designed to:
- Accept any container type as its first parameter
- Take an integer value to search for as its second parameter
- Return the index/position where the value is found
- Throw a `NotFound` exception if the value doesn't exist in the container

```cpp
template 
typename T::value_type easyfind(T &container, int n);
```

This template leverages C++ STL algorithms to search through container types that support standard iteration.

## Exception Handling

The program defines a custom exception class `NotFound` that inherits from `std::exception`:

```cpp
class NotFound : public std::exception {
public:
    virtual const char *what() const throw();
};
```

The `what()` method returns a formatted error message when the searched value is not found in the container.

## Test Program

The `main.cpp` file demonstrates the functionality by:
1. Creating two different container types (vector and list)
2. Populating them with sequential values (0-9)
3. Testing the `easyfind` function with:
   - A value that exists in the containers (7)
   - A value that doesn't exist (42)
4. Using try-catch blocks to handle exceptions

## Helper Functions

The program includes UI helper functions for better output formatting:
- `headerPrinter`: Prints a formatted header with the given text
- `sepPrinter`: Prints separator lines with customizable characters and colors

## Technical Notes

- The implementation uses STL containers (`std::vector` and `std::list`)
- ANSI color codes are used for terminal output formatting
- The template implementation likely uses `std::find` or similar algorithm internally
- The program demonstrates proper separation of interface (header) and implementation (tpp file)

## Usage Example

When executed, the program will:
1. Search for the value 7 in a vector and display its position
2. Attempt to search for the value 42 in a list, which will trigger the `NotFound` exception

This exercise showcases fundamental C++ template programming concepts and proper exception handling techniques.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/84777825-56e5-41b3-9b1a-5a5c930422f3/main.cpp
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/a4390bcf-af04-4576-b249-21181c4733a0/easyfind.hpp
