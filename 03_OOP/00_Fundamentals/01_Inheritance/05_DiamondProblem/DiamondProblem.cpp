#include <iostream>
using namespace std;

/*
    Example: Diamond Problem & Virtual Inheritance Solution
    -------------------------------------------------------
    Inheritance Tree:

            parentBase
            /       \
    DerivedChild1   DerivedChild2
            \       /
        SubDerivedGrandChild

    Problem:
    --------
    - Without virtual inheritance:
        * Two copies of parentBase exist (via DerivedChild1 & DerivedChild2).
        * Ambiguous when calling parentBase methods.
    - With virtual inheritance:
        * Only ONE shared copy of parentBase exists.
        * Ambiguity is removed.
*/

class parentBase {
public:
    void PBMSG() {
        cout << "[parentBase] Message from parent base" << endl;
    }
};

// --- Ambiguous Path (❌ Diamond Problem) ---
class DerivedChild1 : public parentBase {
public:
    void DCHMSG1() {
        cout << "[DerivedChild1] Message from first derived child" << endl;
    }
};

class DerivedChild2 : public parentBase {
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

// --- Fixed Path (✅ Virtual Inheritance) ---
class VDerivedChild1 : virtual public parentBase {
public:
    void VDCHMSG1() {
        cout << "[VDerivedChild1] Message from first virtual derived child" << endl;
    }
};

class VDerivedChild2 : virtual public parentBase {
public:
    void VDCHMSG2() {
        cout << "[VDerivedChild2] Message from second virtual derived child" << endl;
    }
};

class VSubDerivedGrandChild : public VDerivedChild1, public VDerivedChild2 {
public:
    void VSDGCHMSG() {
        cout << "[VSubDerivedGrandChild] Message from virtual subderived grand child" << endl;
    }
};

int main() {
    /*
        --- CPU + Memory Phases ---
        Step 1: Objects created in stack (SubDerivedGrandChild & VSubDerivedGrandChild).
        Step 2: 
            - Non-virtual: TWO parentBase sub-objects exist → ambiguity.
            - Virtual: ONE shared parentBase sub-object exists → no ambiguity.
        Step 3: Function calls resolved:
            - Non-virtual → compile-time binding (static).
            - Virtual inheritance changes memory layout (but still static binding here).
    */

    cout << "\n--- ❌ Diamond Problem Demonstration ---" << endl;
    SubDerivedGrandChild G;

    G.DCHMSG1();
    G.DCHMSG2();
    G.SDGCHMSG();

    // ❌ Ambiguous: two parentBase copies exist
    // G.PBMSG();  // compiler error

    // ✅ Can disambiguate manually:
    cout << "Disambiguating with scope resolution:" << endl;
    G.DerivedChild1::PBMSG();
    G.DerivedChild2::PBMSG();


    cout << "\n--- ✅ Solution with Virtual Inheritance ---" << endl;
    VSubDerivedGrandChild VG;

    VG.VDCHMSG1();
    VG.VDCHMSG2();
    VG.VSDGCHMSG();

    // ✅ No ambiguity → only one parentBase exists
    VG.PBMSG();

    return 0;
}


/*
    ===============================
        📚 Knowledge Recap
    ===============================

    🔹 Diamond Problem:
        - Happens when multiple paths inherit from the same base class.
        - Creates multiple base class instances → ambiguity in method calls.

    🔹 CPU/Memory Behavior:
        - Without virtual:
            * TWO parentBase copies in memory.
            * Calls like G.PBMSG() are ambiguous.
        - With virtual:
            * ONE shared parentBase sub-object.
            * No ambiguity.

    🔹 Solutions:
        1. Explicit disambiguation with scope resolution (::).
        2. Preferred → use virtual inheritance.

    🔹 Key Takeaways:
        - Virtual inheritance ensures only one shared base in diamond-shaped hierarchies.
        - Essential in large OOP designs (e.g., GUI frameworks, multiple mixins).
        - Reduces redundancy, prevents ambiguity, keeps hierarchy clean.
*/
