# 🟦 Inheritance in C++

Inheritance in C++ is a **fundamental concept of Object-Oriented Programming (OOP)** that allows a new class (called the **derived class** or child class) to inherit properties (data members) and behaviors (member functions) from an existing class (called the **base class** or parent class).

This mechanism:

* Promotes **code reusability** (no need to rewrite common features).
* Reduces **redundancy** in code.
* Establishes a **hierarchical relationship** between classes, embodying the **“is-a” relationship** (e.g., a `Car` **is a** `Vehicle`).

---

## 🔑 Key Concepts

* **Base Class (Parent Class):** The class whose members are inherited.
* **Derived Class (Child Class):** The class that inherits members from the base class.
* **Code Reusability:** Derived classes can reuse attributes and methods of the base class.
* **Extensibility:** Derived classes can add new features or override existing ones.

---

## 📝 Syntax

```cpp
class DerivedClass : access_specifier BaseClass {
    // members of DerivedClass
};
```

---

## 🔐 Access Specifiers in Inheritance

The **access specifier** (`public`, `protected`, `private`) defines how base class members are inherited into the derived class.

### Rules of Accessibility

| Inheritance Type    | Base `public`→    | Base `protected`→    | Base `private`→    |
| ------------------- | ----------------- | -------------------- | ------------------ |
| **public**          | public            | protected            | not accessible     |
| **protected**       | protected         | protected            | not accessible     |
| **private**         | private           | private              | not accessible     |

➡️ **Private members of base are never directly accessible in derived classes.**

---

## 🏗️ Types of Inheritance in C++

![alt text](https://files.codingninjas.in/article_images/custom-upload-1712069492-7d6a9d48.webp)

### 1. **Single Inheritance**

* A derived class inherits from a single base class.

```cpp
class Vehicle {
public:
    void move() { cout << "Vehicle is moving\n"; }
};

class Car : public Vehicle {
public:
    void honk() { cout << "Car is honking\n"; }
};
```

---

### 2. **Multiple Inheritance**

* A derived class inherits from more than one base class.

```cpp
class Engine {
public:
    void start() { cout << "Engine started\n"; }
};

class Wheels {
public:
    void rotate() { cout << "Wheels are rotating\n"; }
};

class Car : public Engine, public Wheels {
};
```

---

### 3. **Multilevel Inheritance**

* A class inherits from another derived class, forming a  **chain** .

```cpp
class Animal {
public:
    void eat() { cout << "Eating\n"; }
};

class Mammal : public Animal {
public:
    void breathe() { cout << "Breathing\n"; }
};

class Dog : public Mammal {
public:
    void bark() { cout << "Barking\n"; }
};
```

---

### 4. **Hierarchical Inheritance**

* Multiple derived classes inherit from a single base class.

```cpp
class Shape {
public:
    void draw() { cout << "Drawing shape\n"; }
};

class Circle : public Shape {
};

class Square : public Shape {
};
```

---

### 5. **Hybrid Inheritance**

* Combination of two or more types of inheritance.
* Example: Hierarchical + Multiple → leads to  **diamond problem** .

---

## ⚠️ Diamond Problem & Virtual Inheritance

### ❌ Problem

```cpp
class A { public: void show(){ cout<<"Class A\n"; } };
class B : public A { };
class C : public A { };
class D : public B, public C { };

int main() {
    D obj;
    // obj.show(); ❌ Ambiguity: 2 copies of A
}
```

### ✅ Solution with `virtual` inheritance

```cpp
class A { public: void show(){ cout<<"Class A\n"; } };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };

int main() {
    D obj;
    obj.show();  // ✅ Only one copy of A
}
```

## Effects of Inheritance

Let's see how different components of class are affected in inheritance:

### Static Members and Inheritance

In C++, static members belong to the class itself, not to any object. This means static variables and methods are shared across all instances of the class. When it comes to inheritance, static members from the base class are not inherited by the derived class in the traditional way. However, they can still be accessed using the class name like  ****className::staticMember**** .

### Friend Function and Class in Inheritance

Friend functions and classes in inheritance provides functions or classes to access private and protected members of a class, providing flexibility and better control over class interactions. In inheritance, friend function and classes are not inherited by the base class. It means that the classes and functions declared as friends for the base class does not automatically become a friend for derived class.

### Constructors and Destructors in Inheritance

Constructors and Destructors are generally defined by the programmer and if not, the compiler automatically creates them, so they are present in every class in C++. Now, the question arises what happens to the constructor and destructor when a class is inherited by another class.

In C++ inheritance, the **constructors and destructors are not inherited by the derived class,** but we can call the constructor of the base class in derived class.

* The constructors will be called by the complier in the order in which they are inherited. It means that base class constructors will be called first, then derived class constructors will be called.
* The destructors will be called in reverse order in which the compiler is declared.
* We can also call the constructors and destructors manually in the derived class.

## Polymorphism in Inheritance

In Inheritance, we can redefine the base class member function in the derived class. This type of inheritance is called Function Overriding. Generally, in other programming languages, function overriding is runtime polymorphism but in C++, we can do it at both runtime and compile time. For runtime polymorphism, we have to use the virtual functions.

## Inheritance vs Polymorphism

Inheritance and Polymorphism both works differently. Inheritance allows a new class to inherit properties from an existing class, promoting code reuse, while polymorphism enables a class to perform tasks in different ways, depending on the method used. Inheritance focuses on class relationships, and polymorphism focuses on method behaviour.
