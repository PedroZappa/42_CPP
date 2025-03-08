# Span Class Documentation

This exercise implements a `Span` class that stores a set of integers and provides methods to find the shortest and longest spans (differences) between any two numbers in the container.

## Overview

The program consists of three main files:
- `Span.hpp`: Header file with class declaration and exception classes
- `Span.cpp`: Implementation file with method definitions
- `main.cpp`: Test program that demonstrates the functionality

## Class Definition

The `Span` class is designed to:
- Store a fixed-size collection of integers
- Find the shortest span (minimum difference) between any two numbers
- Find the longest span (maximum difference) between any two numbers
- Allow adding numbers individually or in ranges

```cpp
class Span {
public:
    Span(unsigned int N);
    // Other methods...
private:
    unsigned int _size;
    std::vector<int> _container;
};
```

## Core Functionality

### Constructor and Basic Operations

The class provides:
- A parameterized constructor that takes the maximum capacity (`N`)
- Copy constructor and assignment operator for proper resource management
- Destructor for cleanup

### Key Methods

1. **addNumber(int n)**: Adds a single integer to the container
   ```cpp
   void addNumber(int n);
   ```

2. **addRange(iterator begin, iterator end)**: Adds a range of integers from another container
   ```cpp
   void addRange(std::vector::iterator begin, std::vector::iterator end);
   ```

3. **shortestSpan()**: Calculates the minimum difference between any two numbers
   ```cpp
   size_t shortestSpan(void) const;
   ```
   - Implementation uses sorting and adjacent element comparison
   - Time complexity: O(n log n) due to sorting operation

4. **longestSpan()**: Calculates the maximum difference between any two numbers
   ```cpp
   size_t longestSpan(void) const;
   ```
   - Implementation uses min/max element finding
   - Time complexity: O(n)

## Exception Handling

The class defines two custom exception classes:

1. **ContainerFull**: Thrown when attempting to add elements beyond capacity
   ```cpp
   class ContainerFull : public std::exception {
       // Implementation...
   };
   ```

2. **EmptySpan**: Thrown when attempting to find spans in an empty container or one with only a single element
   ```cpp
   class EmptySpan : public std::exception {
       // Implementation...
   };
   ```

## Helper Functions

The program includes UI helper functions for better output formatting:
- `headerPrinter`: Prints a formatted header with the given text
- `sepPrinter`: Prints separator lines with customizable characters and colors

## Test Cases

The `main.cpp` file demonstrates the functionality with several test cases:

1. Normal usage with a small span of size 5
2. Testing with an empty span (exception handling)
3. Testing with a span containing only one element (exception handling)
4. Testing the `addRange()` method with a vector
5. Performance testing with 10,000 numbers
6. Performance testing with 100,000 numbers with specific increments
7. Testing the `ContainerFull` exception

## Technical Notes

- The implementation uses STL containers (`std::vector`) for storage
- ANSI color codes are used for terminal output formatting
- The `shortestSpan()` method creates a copy of the container for sorting to preserve the original order
- The implementation handles edge cases like empty containers and single-element containers

## Algorithm Details

- The shortest span algorithm sorts the vector first, then compares adjacent elements to find the minimum difference
- The longest span algorithm simply finds the minimum and maximum elements and calculates their difference

This exercise demonstrates proper C++ class design, exception handling, STL container usage, and algorithm implementation for finding minimum and maximum differences in a collection of integers.

Citations:
[1] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/e7ed98bf-95da-4f7b-979e-9263c9626c92/main.cpp
[2] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/bfca825d-4b76-43ff-9abc-44b1b815cd3d/Span.cpp
[3] https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/33783262/115d6704-9912-4cb3-87e5-d0ea706219b7/Span.hpp
