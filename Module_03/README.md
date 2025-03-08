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


