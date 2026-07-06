#include <iostream>
using namespace std;

/*
    Example: Multiple Inheritance in C++
    ------------------------------------
    - One Derived class inherits from *more than one* Base class.

    Inheritance Tree:
    
        --Base1       Base2
            -\         /
            --\       /
            ---\     /
            ---Derived

    Key Features:
    -------------
    1. Derived gets access to all public/protected members of Base1 and Base2.
    2. Code reusability: we don’t rewrite Feature1() or Feature2().
    3. If both bases have functions with the same name → ambiguity arises, solved using scope resolution (::).
    4. Memory layout:
        - Derived object contains a Base1 subobject + a Base2 subobject + its own members.
    5. CPU Execution Flow:
        - Constructors: Base1 → Base2 → Derived (in order of inheritance).
        - Function calls resolved at compile-time (since no virtual used).
*/

class Base1 {
public:
    void Feature1() {
        cout << "[Base1] Feature 1 added" << endl;
    }
};

class Base2 {
public:
    void Feature2() {
        cout << "[Base2] Feature 2 added" << endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void Feature3() {
        cout << "[Derived] Feature 3 added" << endl;
    }
};

int main() {
    /*
        --- CPU + Memory Phases ---
        Step 1: Allocate stack memory for object D (Derived).
        Step 2: Initialize Base1 part → then Base2 part → then Derived part.
        Step 3: Calls are resolved:
            - D.Feature1() → Base1 method
            - D.Feature2() → Base2 method
            - D.Feature3() → Derived method
    */

    Derived D;

    cout << "\n--- Multiple Inheritance in Action ---" << endl;
    D.Feature1();   // From Base1
    D.Feature2();   // From Base2
    D.Feature3();   // From Derived

    cout << "\n--- Accessing Base explicitly (using scope resolution) ---" << endl;
    D.Base1::Feature1(); // Explicit call to Base1 version
    D.Base2::Feature2(); // Explicit call to Base2 version

    return 0;
}

/*
📚 Knowledge Recap
    ✅ Multiple Inheritance:
        One class inherits from two or more base classes.
        Promotes reuse across unrelated classes.

    ✅ Memory Behavior:
        Derived object stores Base1 part + Base2 part + Derived part.

    ✅ CPU Flow:
        Constructor order = order of inheritance (left → right in declaration).
        Destructor order = reverse (Derived → Base2 → Base1).

    ✅ Potential Issue:
        Ambiguity problem if both Base1 and Base2 define the same function.
        Solved using scope resolution operator (::) or virtual inheritance.
*/