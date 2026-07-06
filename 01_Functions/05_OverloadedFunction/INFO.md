# Function Overloading in C++

Function overloading in C++ allows the creation of multiple functions within the same scope that  **share the same name but differ in their parameter lists** .

This difference can be in:

* The **number** of parameters
* The **data types** of the parameters
* The **order** of the parameter types

> ⚠️ Return types alone are **not enough** to overload a function. The parameter list must differ.

---

## 🔑 Key Characteristics

* **Same Name** → All overloaded functions share the same function name.
* **Different Signatures** → The parameter list (number, types, order) must differ.
* **Compile-time Polymorphism** → Function overloading is resolved during  **compilation** , not at runtime.

This mechanism enables more **readable** and **intuitive** code, while letting functions handle different input types gracefully.

---

## ⚙️ Overload Resolution Process

When an overloaded function is called, the compiler determines the correct version through a process called  **overload resolution** .

Steps:

1. **Name Lookup**
   * The compiler gathers all functions with the given name that are visible in the current scope.
   * These are called  **candidate functions** .
2. **Candidate Function Set → Viable Functions**
   * A function is **viable** if:
     * Its number of parameters matches the number of arguments, or
     * Missing parameters can be filled using  **default arguments** , and
     * Each argument can be implicitly converted to the parameter type.
3. **Best Viable Function Selection**
   * The compiler ranks conversions needed for each candidate:
     1. **Exact match** (best)
     2. **Lvalue-to-rvalue, array-to-pointer, function-to-pointer conversions**
     3. **Qualification conversions** (e.g., adding `const`)
     4. **Integral promotions** (e.g., `char → int`)
     5. **Integral conversions** (e.g., `int → long`)
     6. **Floating-point promotions and conversions**
     7. **Pointer conversions** (e.g., derived → base pointer)
     8. **User-defined conversions**
     9. **Ellipsis (`...`)** (worst)
4. **Ambiguity**
   * If two or more viable functions are equally good matches → **compiler error** ("ambiguous call").
5. **Access Control**
   * Even after selecting the best match, access rules apply (e.g., cannot call a `private` overload from outside).

---

## 🧠 Behind the Scenes: Memory & Linker

### 🔹 Name Mangling (Decoration)

* During compilation, C++ **mangles** function names to make them unique.
* The mangled name encodes:
  * The original function name
  * Namespace/class scope
  * Parameter types

Example:

```cpp
void func(int);    // may become _Z4funci
void func(double); // may become _Z4funcd
```

This allows the linker to distinguish between overloaded functions.

### 🔹 Linking

* After compilation, the **linker** resolves the function calls using these mangled names.
* Each overload has a unique memory address, so calls are properly matched.

## 🚫 Restrictions on Function Overloading (C++ only)

Although C++ allows function overloading, there are **specific** cases where overloading is  **not permitted** , even if the functions appear different at first glance.

### ❌ You cannot overload functions that differ only in:

1. **Return Type**

   ```cpp
   int f();
   float f();   // ❌ Error: differs only by return type
   ```
2. **Static vs Non-static Member Function**

   ```cpp
   struct A {
       static int f();
       int f();   // ❌ Error: static and non-static with same signature
   };
   ```
3. **Static Template Member Function vs Non-static Template Member Function**

   (with identical parameter lists).
4. **Typedef Names Representing the Same Type**

   ```cpp
   typedef int I;
   void f(float, int);
   void f(float, I);   // ❌ Error: typedef does not create a new type
   ```
5. **Array vs Pointer Parameters**

   ```cpp
   void f(char*);
   void f(char[10]);   // ❌ Error: treated as the same function
   ```

   ⚠️ Note: Except for the  **first dimension** , array sizes are significant:

   ```cpp
   void g(char(*)[20]);   // pointer to array of 20 chars
   void g(char(*)[40]);   // ✅ Different
   ```
6. **Function Type vs Pointer-to-Function**

   ```cpp
   void f(int(float));
   void f(int (*)(float));   // ❌ Equivalent
   ```
7. **cv-qualifiers (`const`, `volatile`, `restrict`) at the outermost level**

   ```cpp
   int f(int);
   int f(const int);      // ❌ Same
   int f(volatile int);   // ❌ Same
   ```

   ✅ But inside a pointer/reference, qualifiers **do** make it different:

   ```cpp
   void g(int*);
   void g(const int*);      // ✅ Different
   void g(volatile int*);   // ✅ Different
   void g(float&);          // ✅ Different
   void g(const float&);    // ✅ Different
   ```
8. **Default Arguments**

   ```cpp
   void f(int);
   void f(int i = 10);   // ❌ Same function, just different defaults
   ```
9. **Extern "C" Linkage**

   Multiple functions declared with `extern "C"` and the same name are  **not overloadable** , even if parameter lists differ.
