# 📘 Polymorphism in C++

---

## 🔹 Introduction

The word **Polymorphism** means  *"many forms"* .

In  **real life** , a person can play different roles: a man can be a  **father** , a  **husband** , and an **employee** at the same time. His behavior changes depending on the situation.

Similarly, in  **C++** , **polymorphism** allows functions and operators to behave differently based on the context in which they are used.

This makes code  **reusable, consistent, and flexible** .

---

## 🔹 Types of Polymorphism in C++

Polymorphism in C++ can be classified into two major categories:

1. **Compile-time Polymorphism** (Static / Early Binding)
2. **Run-time Polymorphism** (Dynamic / Late Binding)

---

## 1. **Compile-time Polymorphism**

Also known as **early binding** or  **static polymorphism** , the decision of which function/operator to call is made by the  **compiler at compile time** .

### Mechanisms of COmpile-time type

* **Function Overloading**
  * Same function name, different parameter lists (type, number, or order).
  * Decided at compile time which version will be called.
* **Operator Overloading**
  * Extends the meaning of operators (`+`, `-`, `<<`, `>>`, etc.) for  **user-defined data types** .
  * Example: `+` can add integers or concatenate strings.

⚠️ Restrictions: Some operators (`::`, `.`, `.*`, `?:`, `sizeof`) cannot be overloaded as they are fundamental to the language.

### Advantages

* Faster execution (no runtime overhead).
* Improves readability (same function/operator name across different contexts).

---

## 2. **Run-time Polymorphism**

Also known as **late binding** or  **dynamic polymorphism** , the decision of which function to call is made  **at runtime** .

### Mechanisms of Run-time type

* **Virtual Functions**
  * Declared in the base class using the `virtual` keyword.
  * Overridden in derived classes using the `override` keyword.
* **Function Overriding**
  * A derived class provides a **new implementation** of a base class’s virtual function.
  * Ensures correct function call depending on the object being pointed to.
* **Pure Virtual Functions & Abstract Classes**
  * A base class can declare pure virtual functions (`= 0`) to enforce that derived classes **must** implement them.
  * Used for  **abstraction** .

---

## 3. **How Run-time Polymorphism Works Internally**

When a class contains a  **virtual function** :

* The compiler builds a **VTable (Virtual Table)** containing function addresses.
* Each object of that class stores a hidden pointer called **vptr** that points to the class’s VTable.
* At runtime, when a virtual function is called via a  **base pointer/reference** , the `vptr` ensures the **correct overridden function** is executed.

### Keywords used

* `virtual` → Enables runtime polymorphism.
* `override` → Ensures derived function overrides base class version.
* `final` → Prevents further overriding.
* `abstract class` → Any class with pure virtual functions.

---

## 4. **Other Polymorphism Mechanisms in C++**

* **Templates (Generic Programming)** → Compile-time polymorphism through generic types.
* **Function Pointers / std::function** → Allow indirect polymorphic function calls.
* **Lambda Functions** (C++11+) → Inline polymorphic behaviors.
* **Dynamic Casting (`dynamic_cast`)** → Safely downcasts base pointers to derived pointers at runtime.

---

## 5. **Comparison: Compile-time vs Run-time Polymorphism**

| Feature                  | Compile-time Polymorphism                  | Run-time Polymorphism                          |
| ------------------------ | ------------------------------------------ | ---------------------------------------------- |
| **Also Called**    | Static Binding / Early Binding             | Dynamic Binding / Late Binding                 |
| **Resolution**     | At compile time                            | At runtime                                     |
| **Mechanisms**     | Function Overloading, Operator Overloading | Virtual Functions, Function Overriding, VTable |
| **Decision Maker** | Compiler                                   | VTable and vptr at runtime                     |
| **Speed**          | Faster (no runtime lookup)                 | Slower (small overhead due to vtable lookup)   |
| **Flexibility**    | Less flexible                              | More flexible                                  |
| **Keywords**       | None                                       | virtual, override, final, abstract             |

---

## 6. **Why Polymorphism?**

Polymorphism helps in writing  **consistent, maintainable, and extensible code** .

Example: Calculating the area of different shapes.

Instead of writing separate functions (`circleArea()`, `squareArea()`), we can have a base class `Shape` with a virtual function `calculateArea()`.

Derived classes (`Circle`, `Square`) provide their own implementations.

This makes the code **uniform** and **easier to extend** when adding new shapes.
