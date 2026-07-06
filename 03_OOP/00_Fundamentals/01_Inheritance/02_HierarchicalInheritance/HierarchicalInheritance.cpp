#include <iostream>
using namespace std;

/*
    Example: Hierarchical Inheritance in C++
    ----------------------------------------
    - One Base Class (HighLevel)
    - Multiple Derived Classes (all inherit directly from HighLevel)

    Inheritance Tree:
    
        --- High Level ---
        /         |         \
    Left Low   Middle Low   Right Low

    Key Features:
    -------------
    1. Each derived class inherits all public/protected members of HighLevel.
    2. Derived classes can add their own methods (specialized behavior).
    3. No derived class is connected to another (all depend only on HighLevel).
    4. Memory layout:
        - Each object stores a HighLevel part + its own extra part.
        - Example: LeftLow object = { HighLevel members + LeftLow members }
    5. CPU Execution Flow:
        - When object is created → constructor of HighLevel runs first.
        - Then derived class constructor runs (if defined).
        - Function calls are resolved at compile-time (here no virtual used).
    6. Function Behavior:
        - Derived objects can access HighLevel methods directly.
        - Scope resolution (::) can be used if overridden (not done here).
*/

class HighLevel {
public:
    void HLmsg() {
        cout << "[HighLevel] Message from the High level class" << endl;
    }
};

// --- Derived classes (Low Level) ---
class LeftLowLevel : public HighLevel {
public:
    void LLLmsg() {
        cout << "[LeftLowLevel] Specialized Left Low level message" << endl;
    }
};

class MiddleLowLevel : public HighLevel {
public:
    void MLLmsg() {
        cout << "[MiddleLowLevel] Specialized Middle Low level message" << endl;
    }
};

class RightLowLevel : public HighLevel {
public:
    void RLLmsg() {
        cout << "[RightLowLevel] Specialized Right Low level message" << endl;
    }
};

int main() {
    /*
        --- CPU + Memory Phases ---
        Step 1: Allocate stack memory for objects (H, LLL, MLL, RLL).
        Step 2: Initialize base part (HighLevel) before derived parts.
        Step 3: Function call resolution happens at compile time.
        Step 4: Execution moves through instructions in order of calls.
    */

    HighLevel H;
    LeftLowLevel LLL;
    MiddleLowLevel MLL;
    RightLowLevel RLL;

    cout << "\n--- High Level Object ---" << endl;
    H.HLmsg();

    cout << "\n--- Left Low Level Object ---" << endl;
    LLL.HLmsg();   // Inherited method
    LLL.LLLmsg();  // Specialized method

    cout << "\n--- Middle Low Level Object ---" << endl;
    MLL.HLmsg();   // Inherited method
    MLL.MLLmsg();  // Specialized method

    cout << "\n--- Right Low Level Object ---" << endl;
    RLL.HLmsg();   // Inherited method
    RLL.RLLmsg();  // Specialized method

    return 0;
}

/*
📚 Knowledge Recap
    ✅ Hierarchical Inheritance:
        Single base, multiple derived.
        Promotes code reusability (all share HighLevel functions).
        Each child can extend/override behavior independently.

    ✅ Memory Behavior:
        Each child object = HighLevel + its own part.
        No duplication of base, each derived carries its base subobject.

    ✅ CPU Flow:
        Constructors: Base → Derived.
        Destructors: Derived → Base.
        Calls: Resolved at compile-time unless virtual is used.

    ✅ Specs:
        Useful for classifying common behavior in parent, specialized in children.
        Example in real life:
        Vehicle → Car, Bike, Truck.
*/