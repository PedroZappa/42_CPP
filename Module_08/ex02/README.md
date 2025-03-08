# MutantStack Documentation
<!-- mtoc-start -->

* [Overview](#overview)
* [Class Description](#class-description)
  * [Iterator Types](#iterator-types)
  * [Iterator Methods](#iterator-methods)
* [Technical Explanation](#technical-explanation)
  * [Underlying Implementation](#underlying-implementation)
  * [Why This Matters](#why-this-matters)
* [Usage Example](#usage-example)
* [Helper Functions](#helper-functions)
* [Comparison with Standard Containers](#comparison-with-standard-containers)
* [Technical Notes](#technical-notes)

<!-- mtoc-end -->
## Overview

The MutantStack project implements a custom stack container that extends the functionality of the standard C++ `std::stack` container by adding iterator capabilities. This allows for more flexible traversal and manipulation of stack elements without compromising the fundamental stack operations.

## Class Description

The `MutantStack` class template inherits from `std::stack` and adds iterator support:

```cpp
template 
class MutantStack : public std::stack
```

### Iterator Types

The class defines four iterator types:
- `it`: Regular iterator (mutable)
- `const_it`: Constant iterator (immutable)
- `rev_it`: Reverse iterator (mutable)
- `const_rev_it`: Constant reverse iterator (immutable)

These iterators are actually typedefs to the underlying container's iterators:

```cpp
typedef typename std::stack::container_type::iterator it;
typedef typename std::stack::container_type::const_iterator const_it;
typedef typename std::stack::container_type::reverse_iterator rev_it;
typedef typename std::stack::container_type::const_reverse_iterator const_rev_it;
```

### Iterator Methods

The class provides methods to access the beginning and end of the container using different iterator types:

- `begin()` and `end()`: For regular iteration
- `begin() const` and `end() const`: For constant iteration
- `rbegin()` and `rend()`: For reverse iteration
- `rbegin() const` and `rend() const`: For constant reverse iteration

## Technical Explanation

### Underlying Implementation

The `std::stack` is an adapter container that wraps another container (by default `std::deque`). The `MutantStack` implementation accesses this underlying container through the protected member `c` that is inherited from `std::stack`.

### Why This Matters

Standard `std::stack` only provides access to the top element and doesn't support iteration. The `MutantStack` extension allows for:
- Traversing all elements in the stack
- Iterating in both forward and reverse directions
- Using both mutable and immutable iterators

## Usage Example

The provided `main.cpp` demonstrates how to use `MutantStack` with various iterator types:

1. Creating and populating a `MutantStack`
2. Traversing elements using regular iterators
3. Performing standard stack operations (push, pop, top)
4. Using constant iterators for read-only access
5. Traversing in reverse order with reverse iterators
6. Comparing functionality with `std::list` for reference

## Helper Functions

The implementation includes UI helper functions for better visualization:
- `headerPrinter`: Prints a formatted header with text
- `sepPrinter`: Prints separator lines

## Comparison with Standard Containers

The main program compares `MutantStack` with `std::list` to demonstrate that the custom implementation provides similar iteration capabilities while maintaining stack semantics.

## Technical Notes

1. The implementation uses ANSI color codes (from `Ansi.h`) for formatted console output
2. The class maintains the LIFO (Last In, First Out) behavior of a stack while adding iteration capabilities
3. All standard stack operations (push, pop, top, size, empty) remain available through inheritance

This implementation demonstrates how to extend standard library containers to add functionality while preserving their original behavior.
