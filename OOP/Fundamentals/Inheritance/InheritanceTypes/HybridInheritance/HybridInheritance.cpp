#include <iostream>
using namespace std;

/*
===========================================================
            HYBRID INHERITANCE IN C++
===========================================================

Diagram (class structure):
--------------------------

            parentBase
                |
        -----------------
        |               |
    DerivedChild1     DerivedChild2
        |
    SubDerivedGrandChild
        ^
        (inherits from BOTH DerivedChild1 + DerivedChild2)

This combines:
- Hierarchical (parentBase → multiple children)
- Multilevel   (parentBase → DerivedChild1 → SubDerivedGrandChild)
- Multiple     (SubDerivedGrandChild inherits from 2 parents)

===========================================================
            MEMORY + CPU BEHAVIOR
===========================================================

Object Layout: SubDerivedGrandChild
-----------------------------------
+--------------------------------------------------+
|   DerivedChild1                                  |
|   +--------------------------------------------+ |
|   | parentBase                                 | |
|   +--------------------------------------------+ |
|                                                  |
|   DerivedChild2                                  |
|                                                  |
|   SubDerivedGrandChild                           |
+--------------------------------------------------+

Execution Flow (when methods are called):
-----------------------------------------
1)  Stack allocates object (SubDerivedGrandChild sdgch).
2)  Compiler binds function calls to addresses at compile-time 
    (since no virtual functions are used).
3)  Calls:
    - sdgch.SDGCHMSG()   → SubDerivedGrandChild scope
    - sdgch.DCHMSG1()    → DerivedChild1 scope
    - sdgch.DCHMSG2()    → DerivedChild2 scope
    - sdgch.PBMSG()      → parentBase scope (inherited via DerivedChild1)
===========================================================
*/

class parentBase {
public:
    void PBMSG() {
        cout << "[parentBase] Message from parent base" << endl;
    }
};

class DerivedChild1 : public parentBase {
public:
    void DCHMSG1() {
        cout << "[DerivedChild1] Message from first derived child" << endl;
    }
};

class DerivedChild2 {
public:
    void DCHMSG2() {
        cout << "[DerivedChild2] Message from second derived child" << endl;
    }
};

class SubDerivedGrandChild : public DerivedChild1, public DerivedChild2 {
public:
    void SDGCHMSG() {
        cout << "[SubDerivedGrandChild] Message from subderived grand child" << endl;
    }
};

int main() {
    /*
        --- CPU + Memory Execution Demo ---
        Step 1: Object created in stack → SubDerivedGrandChild sdgch
        Step 2: Compiler sets up memory with:
                parentBase → DerivedChild1 → SubDerivedGrandChild
                and also includes DerivedChild2
        Step 3: Calls are resolved by scope
    */

    SubDerivedGrandChild sdgch;

    cout << "\n--- Normal Calls ---" << endl;
    sdgch.SDGCHMSG();  // SubDerivedGrandChild
    sdgch.DCHMSG1();   // From DerivedChild1
    sdgch.DCHMSG2();   // From DerivedChild2
    sdgch.PBMSG();     // From parentBase (via DerivedChild1)

    return 0;
}

/*
===========================================================
                    KNOWLEDGE RECAP
===========================================================

1) Hybrid Inheritance = combination of multiple inheritance types.
2) It can lead to ambiguities (like diamond problem).
3) If multiple paths lead to the same base → use "virtual inheritance".
4) Memory layout depends on inheritance path:
    - Only one copy of parentBase here → safe.
    - With both sides inheriting parentBase → ambiguity.
5) Calls are statically bound here (no virtual functions).
6) Hybrid is common in complex systems (like C++ libraries).

===========================================================
*/
