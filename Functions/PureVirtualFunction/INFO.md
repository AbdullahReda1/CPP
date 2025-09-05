# 📌 Pure Virtual Functions & Abstract Classes in C++

## 🔹 What is a Pure Virtual Function?

* A **pure virtual function** is a virtual function with **no implementation** in the base class.
* Declared by assigning `= 0` in its declaration.
* Forces derived classes to provide their own implementation.

---

## 🔹 What is an Abstract Class?

* Any class that contains  **at least one pure virtual function** .
* Abstract classes **cannot be instantiated** (you cannot create objects from them).
* They serve as a **blueprint** or **interface** for derived classes.

When we say:

> **Abstract classes serve as a blueprint or interface for derived classes.**

We mean:

### 🔹 Blueprint Idea

* Think of an **abstract class** like an architect’s blueprint for a house.
* The blueprint shows **what rooms must exist** (living room, kitchen, bathroom), but  **not how they’re built** .
* Similarly, an abstract class declares functions (with `= 0`) that **must exist** in any derived class, but it doesn’t provide their implementation.

Example idea:

* The abstract class might say:
  * “Every shape must have a function to calculate area.”
  * But it does **not** say how to calculate it.

Each derived class (Circle, Rectangle, Triangle) is like a contractor who **follows the blueprint** but decides how to actually build each room.

### 🔹 Interface Idea

* An **interface** in programming defines  **what actions a class must support** , but **not how** they are performed.
* In C++, an abstract class with only pure virtual functions behaves just like an interface.
* Example: If you design a `Drawable` interface, it says:
  * “Any class that is drawable must have a `draw()` function.”
  * How it draws depends on the derived class (a Button draws differently from a Circle).

### ✅ In short

* Abstract class = **Blueprint** → Defines *requirements* but not the  *implementation* .
* Derived class = **Builder** → Provides the  *actual implementation* .
* This enforces consistency (all shapes must have `area()`), but allows flexibility (each shape computes it differently).

---

## 🔹 Purpose

* To enforce that all derived classes must implement certain functions.
* To provide a **common interface** while leaving specific details to the derived classes.
* To achieve **abstraction** in Object-Oriented Programming.

---

## 🔹 Characteristics of Pure Virtual Functions

1. Defined in a base class with `= 0`.
2. Must be overridden in derived classes to make them  **concrete** .
3. If not overridden, the derived class also becomes  **abstract** .
4. Can be part of **interfaces** (classes with only pure virtual functions).

---

## 🔹 Characteristics of Abstract Classes

1. Cannot create objects directly.
2. Can have both **normal member functions** and  **pure virtual functions** .
3. Can be used to define **interfaces** in C++.
4. A derived class must implement all pure virtual functions to be instantiable.

---

## 🔹 Use Cases

* **Interfaces** : Defining functions that must be implemented (e.g., `print()`, `draw()`, `area()`).
* **Frameworks & APIs** : Providing a base contract for user-defined classes.
* **Polymorphism** : Allowing derived classes to behave differently while sharing a common interface.

---

## 🔹 Difference Between Virtual & Pure Virtual Functions

| Aspect         | Virtual Function                            | Pure Virtual Function                |
| -------------- | ------------------------------------------- | ------------------------------------ |
| Implementation | May have default implementation             | Has no implementation (`= 0`)      |
| Class Type     | Class can be instantiated                   | Class becomes abstract               |
| Override       | Derived class may override                  | Derived class**must**override  |
| Purpose        | Provides default behavior but allows change | Enforces contract, acts as interface |

---

## 🔹 Best Practices

* Use **pure virtual functions** to enforce rules in derived classes.
* Use abstract classes to define **interfaces** in C++.
* Combine **normal functions** and **pure virtual functions** in abstract classes for flexibility.
* Use references or pointers to abstract classes to achieve  **runtime polymorphism** .
