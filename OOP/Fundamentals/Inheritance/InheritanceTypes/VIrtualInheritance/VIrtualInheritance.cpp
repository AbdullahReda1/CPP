#include <iostream>
using namespace std;

/*
    Virtual Inheritance Example (Diamond Problem Solution)
    ------------------------------------------------------
    - When multiple derived classes inherit from the same base class,
    and then another class inherits from those derived classes,
    ambiguity can occur ("diamond problem").
    - Virtual inheritance ensures that only **one shared instance**
    of the base class exists, avoiding ambiguity and duplication.
*/

class Base {
public:
    void BMsg() {
        cout << "Base message" << endl;
    }
};

class Derived1 : virtual public Base {   // Virtual inheritance
public:
    void D1Msg() {
        cout << "Derived 1 message" << endl;
    }
};

class Derived2 : virtual public Base {   // Virtual inheritance
public:
    void D2Msg() {
        cout << "Derived 2 message" << endl;
    }
};

class SupDerived : public Derived1, public Derived2 {
public:
    void SDMsg() {
        cout << "SupDerived message" << endl;
    }
};

int main() {
    SupDerived sd;

    // Call functions from all inheritance levels
    sd.SDMsg();   // SupDerived level
    sd.D1Msg();   // Derived1 level
    sd.D2Msg();   // Derived2 level
    sd.BMsg();    // Base level (unambiguous due to virtual inheritance)

    return 0;
}

/*
    📘 Knowledge Recap
    ------------------
    ✅ Normal multiple inheritance without "virtual" creates **two copies**
    of the Base class when Derived1 and Derived2 are combined in SupDerived.
    → This causes ambiguity (which Base?).

    ✅ With "virtual public Base":
    - Only ONE shared Base object is created.
    - Both Derived1 and Derived2 share this Base.
    - SupDerived inherits this single Base, avoiding ambiguity.

    ✅ Behavior:
    - Virtual inheritance ensures memory efficiency (1 Base instance).
    - Resolves function call ambiguity when accessing Base methods.

    🧩 Key Terms:
    - Diamond Problem → Multiple inheritance ambiguity.
    - Virtual Inheritance → Solution ensuring one shared base instance.

    ⚙️ Specs & Features:
    - Memory: Shared Base instance (saves memory).
    - CPU: Simplifies function resolution → no need for explicit disambiguation.
    - Usage: Common in cases like interfaces, multiple-role hierarchies.

    📝 Rule of Thumb:
    → Use virtual inheritance only when you expect the diamond pattern.

Questions?
    ?1. Does the compiler see them as one class?
    * No, they are still separate classes (Derived1, Derived2, SupDerived, and Base).
    * What virtual changes is how the Base subobject is laid out in memory when multiple paths lead to it.
    * Without virtual, each derived branch gets its own Base. With virtual, the compiler ensures only one
    * shared Base instance exists inside the final derived class.
    👉 So, the compiler does not merge classes, but it merges the Base subobject into one shared instance.
    ?2. Is it like “one signature with different implementation”?
    * That idea applies more to polymorphism (virtual functions), where multiple derived
    * classes override the same function signature differently.
    * But virtual inheritance is different: it’s about class layout and object structure, not function overriding.
    * 👉 Here, the compiler doesn’t see multiple BMsg() implementations — it just ensures there’s only one Base,
    * so there’s only one BMsg() to call.
✅ In short:
    * Virtual inheritance = one shared Base subobject (memory/layout issue).
    * Virtual functions = one signature, many implementations (polymorphism issue).
*/

/*
===========================================================
        VIRTUAL INHERITANCE MEMORY LAYOUT
===========================================================

CASE 1: WITHOUT virtual inheritance
-----------------------------------
class Base {};
class Derived1 : public Base {};
class Derived2 : public Base {};
class SupDerived : public Derived1, public Derived2 {};

Memory Layout (object SupDerived):
+-------------------------+
|   Derived1              |
|   +-------------------+ |
|   |  Base (copy #1)   | |
|   +-------------------+ |
|                         |
|   Derived2              |
|   +-------------------+ |
|   |  Base (copy #2)   | |
|   +-------------------+ |
|                         |
|   SupDerived members    |
+-------------------------+

❌ Problem: TWO copies of Base → ambiguity:
    sd.BMsg(); // ERROR: ambiguous

-----------------------------------------------------------

CASE 2: WITH virtual inheritance
--------------------------------
class Base {};
class Derived1 : virtual public Base {};
class Derived2 : virtual public Base {};
class SupDerived : public Derived1, public Derived2 {};

Memory Layout (object SupDerived):
+-------------------------+
|   Derived1              |
|   (no separate Base)    |
|                         |
|   Derived2              |
|   (no separate Base)    |
|                         |
|   SupDerived members    |
+-------------------------+
|   Shared Base (only 1!) |
|   +-------------------+ |
|   |   Base            | |
|   +-------------------+ |
+-------------------------+

✅ Solution: ONLY ONE copy of Base exists.
    sd.BMsg(); // works fine, unambiguous

===========================================================
        RUNTIME CALL RESOLUTION (CPU + VTABLE)
===========================================================

Step-by-step when calling methods on SupDerived object:

Object: SupDerived sd;

1) sd.SDMsg();
    - Compiler sees SDMsg in SupDerived → direct call.
    - No vtable needed, resolved at compile-time.

2) sd.D1Msg();
    - Lookup goes to Derived1 vtable (if virtual functions exist).
    - Since it's non-virtual here, compiler resolves statically.

3) sd.D2Msg();
    - Same as above, statically resolved from Derived2.

4) sd.BMsg();
    - Virtual inheritance ensures only ONE Base subobject exists.
    - Compiler generates "virtual base table" (vbptr).
    - sd → Derived1/Derived2 → follow vbptr → shared Base.
    - Call BMsg() from that single Base.

Diagram of pointers:
+--------------------+
| SupDerived sd      |
|   + Derived1 part -+--> vbptr --> Base (shared)
|   + Derived2 part -+--> vbptr --> (same Base)
|   + SupDerived part|
+--------------------+

So both Derived1 and Derived2 lead to the SAME Base subobject.

===========================================================
*/