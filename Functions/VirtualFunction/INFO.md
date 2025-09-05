# 📌 Virtual Functions in C++

## 🔹 What is a Virtual Function?

* A **virtual function** is a function in a base class declared with the `virtual` keyword.
* It allows  **runtime polymorphism** , meaning the function that gets called depends on the **actual object type** (not the pointer type).
* Ensures that if a derived class provides its own implementation, it will be used when accessed through a base class pointer or reference.

---

## 🔹 Why Virtual Functions?

* They enable **dynamic dispatch** instead of  **static dispatch** .
* Without `virtual`, functions are resolved at **compile time** (function hiding).
* With `virtual`, functions are resolved at **runtime** (true overriding).

---

## 🔹 Key Features

* Declared in the base class using `virtual`.
* Overridden in derived classes with the same function signature.
* Usually called through  **pointers or references** .
* Introduces a small runtime overhead (via vtable lookup).

---

## 🔹 Rules

1. Virtual functions must be **member functions** (not standalone).
2. They can be **overridden** in derived classes.
3. A base class with a virtual function should have a  **virtual destructor** .
4. Virtual functions can also be **pure virtual** (making the class abstract).
5. If a derived class does not override a virtual function, the base version is used.

---

## 🔹 Pure Virtual Functions & Abstract Classes

* A **pure virtual function** has no implementation (`= 0`).
* Any class with at least one pure virtual function becomes an  **abstract class** .
* Abstract classes **cannot be instantiated** directly.
* Derived classes must implement pure virtual functions to become  **concrete classes** .

---

## 🔹 `virtual` vs `override`

| Case                            | `virtual`in Base? | `override`in Derived? | Valid? | Behavior                                                |
| ------------------------------- | ------------------- | ----------------------- | ------ | ------------------------------------------------------- |
| Normal overriding               | ✅ Yes              | ❌ No                   | ✅     | Polymorphism works.                                     |
| Best practice                   | ✅ Yes              | ✅ Yes                  | ✅     | Polymorphism works. Compiler ensures correct signature. |
| `override`without `virtual` | ❌ No               | ✅ Yes                  | ❌     | Compile-time error.                                     |
| Neither used                    | ❌ No               | ❌ No                   | ✅     | Function hiding only (no polymorphism).                 |

---

## 🔹 Best Practices

* Always declare intended polymorphic functions as `virtual`.
* Always mark overriding functions with `override` (C++11+).
* Always give polymorphic base classes a  **virtual destructor** .
* Use pure virtual functions to enforce a **contract** (interface-like behavior).
