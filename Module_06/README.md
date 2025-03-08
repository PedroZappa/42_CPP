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


