# Function overriding

In C++ is a feature of Object-Oriented Programming (OOP) that allows a derived class to provide a specific implementation for a function that is already defined in its base class. This is a crucial mechanism for achieving runtime polymorphism.

## Key aspects of function overriding

### **Inheritance:**

  Function overriding inherently relies on inheritance, as it involves a relationship between a base class and a derived class.

### **Same Signature:**

  For a function to be overridden, the function in the derived class must have the exact same name, return type, and parameters (function signature) as the function in the base class.

### **Virtual Functions:**

  To enable runtime polymorphism and ensure that the correct version of the overridden function is called based on the actual object type (not the pointer type), the function in the base class must be declared as `virtual`.

### **Runtime Polymorphism:**

  When a virtual function is overridden, and a base class pointer or reference points to a derived class object, calling that virtual function through the base class pointer/reference will invoke the derived class's version of the function at runtime. This dynamic dispatch is the essence of runtime polymorphism.

### `override` Keyword (C++11 and later)

  While not strictly required for overriding, the `override` keyword can be used in the derived class function declaration to explicitly indicate that the function is intended to override a base class virtual function. This helps in catching errors at compile-time if the signature doesn't match or if the base function isn't virtual.

## Difference Between Overloading vs Overriding

| Feature                    | Overloading                              | Overriding                                        |
| -------------------------- | ---------------------------------------- | ------------------------------------------------- |
| **Definition**       | Same function name, different parameters | Redefining base class function in derived class   |
| **Compile/Run Time** | Compile-time polymorphism                | Run-time polymorphism                             |
| **Inheritance**      | Not required                             | Required                                          |
| **Keyword**          | None                                     | Needs `virtual`(base) and `override`(derived) |

## Heart of how overriding, virtual, and pure virtuals Works

| Case                                  | `virtual` used?  | `override` used? | Behavior                                                          |
| ------------------------------------- | ------------------ | ------------------ | ----------------------------------------------------------------- |
| Overriding w/out `virtual`          | No                 | No                 | Just hides base function → no polymorphism                       |
| Overriding w/`virtual`only          | Yes                | No                 | Polymorphism works, but no compiler check if signature mismatched |
| Overriding w/`virtual`+`override` | Yes                | Yes                | Best practice ✅ → polymorphism + compiler checks                |
| `virtual`without overriding         | Yes                | N/A                | Inherits base behavior, can override later                        |
| `pure virtual`without overriding    | Yes (with `= 0`) | N/A                | Derived stays abstract until it provides implementation           |

## 📌 `virtual` vs `override` Usage

| Case                                               | `virtual` in Base? | `override` in Derived? | Valid?                    | Behavior                                                                                                                        |
| -------------------------------------------------- | -------------------- | ------------------------ | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| **1. Normal overriding (classic way)**       | ✅ Yes               | ❌ No                    | ✅ Valid                  | Derived overrides base. Polymorphism works.                                                                                     |
| **2. Modern best practice (C++11+)**         | ✅ Yes               | ✅ Yes                   | ✅ Valid                  | Derived overrides base. Polymorphism works. Compiler checks signature correctness.                                              |
| **3.`override`without `virtual`in base** | ❌ No                | ✅ Yes                   | ❌**Compile Error** | `override`means **"I am overriding a virtual function"**. If the base function isn’t virtual, the compiler rejects it. |
| **4. Neither `virtual`nor `override`**   | ❌ No                | ❌ No                    | ✅ Valid                  | Function hiding only. No runtime polymorphism (calls are resolved by pointer type at compile time).                             |
