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


