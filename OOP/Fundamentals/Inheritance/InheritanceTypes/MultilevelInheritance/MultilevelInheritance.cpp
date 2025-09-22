#include <iostream>
using namespace std;

/*
    Example: Multilevel Inheritance in C++
    --------------------------------------
    Parent  →  Child  →  Grandchild

    Key Concepts:
    -------------
    - Inheritance chain: Parent → Child → Grandchild
    - A derived class can:
        * Inherit methods directly
        * Override methods (redefine with same name/signature)
        * Add its own unique methods
    - Overriding hides the parent version unless scope resolution (::) is used.
    - If virtual was used → runtime polymorphism (vtable) kicks in.
    - Without virtual → compile-time (static) binding.

    Memory/Execution Flow:
    ----------------------
    1. Objects P, CH, G are allocated on the stack.
    2. Compiler resolves which Msg() to call based on object type.
    3. For inherited methods, function addresses are copied down the chain.
*/

class Parent {
public:
    void Msg() {
        cout << "[Parent] Overridden Msg()" << endl;
    }

    void PMsg() {
        cout << "[Parent] Unique method PMsg()" << endl;
    }
};

class Child : public Parent {
public:
    void Msg() {
        cout << "[Child] Overridden Msg()" << endl;
    }

    void CHMsg() {
        cout << "[Child] Unique method CHMsg()" << endl;
    }
};

class Grandchild : public Child {
public:
    void Msg() {
        cout << "[Grandchild] Overridden Msg()" << endl;
    }

    void GMsg() {
        cout << "[Grandchild] Unique method GMsg()" << endl;
    }
};

int main() {
    /*
        --- CPU + Memory Phases ---
        Step 1: Objects P, CH, and G are created in stack memory
        Step 2: Function calls resolved at compile-time (no virtual)
        Step 3: Jumps directly to function addresses
    */

    Parent P;
    Child CH;
    Grandchild G;

    cout << "\n--- Normal Calls (Overriding in Action) ---" << endl;
    P.Msg();    // Parent Msg()
    CH.Msg();   // Child overrides Parent Msg()
    G.Msg();    // Grandchild overrides Child Msg()

    cout << "\n--- Calling Unique + Inherited Methods ---" << endl;
    P.PMsg();     // Only in Parent

    CH.CHMsg();   // Only in Child
    CH.PMsg();    // Inherited Parent method
    
    G.GMsg();     // Only in Grandchild
    G.CHMsg();    // Inherited Child method
    G.PMsg();     // Inherited Parent method

    cout << "\n--- Using Scope Resolution (::) ---" << endl;
    CH.Parent::Msg();   // Force Parent's Msg() from Child
    G.Child::Msg();     // Force Child's Msg() from Grandchild
    G.Parent::Msg();    // Force Parent's Msg() from Grandchild

    return 0;
}