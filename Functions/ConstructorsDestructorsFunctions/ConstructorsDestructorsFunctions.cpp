/*
=====================================================================================
    File: ConstructorsDestructorsFunctions.cpp
    Topic: Object Creation, Initialization, and Cleanup
-------------------------------------------------------------------------------------
    🎯 Goal:
        - Understand what constructors and destructors are.
        - Learn how they control object lifetime.
        - Observe memory and CPU behavior for each phase.
=====================================================================================
*/

#include <iostream>
using namespace std;

/*
=====================================================================================
    CLASS DEFINITION
=====================================================================================
*/

class Build {
private:
    int DefaultValue;
    int Value;
    int *ptr; // dynamically allocated memory (on heap)

public:
    /*
    ---------------------------------------------------------------------------------
        Default Constructor
        -------------------
        Called automatically when an object is created without arguments.
        - Initializes default values.
        - Prepares memory safely.
    ---------------------------------------------------------------------------------
        🧠 CPU & MEMORY BEHAVIOR:
        - Stack memory allocated for object.
        - Each data member gets default or explicit initial values.
        - The constructor code runs immediately after memory allocation.
    ---------------------------------------------------------------------------------
    */
    Build() {
        DefaultValue = 0;
        Value = 0;
        ptr = new int[2]; // allocate heap memory (2 integers)
        cout << "[Constructor] Default object created" << endl;
    }

    /*
    ---------------------------------------------------------------------------------
        Parameterized Constructor
        -------------------------
        Called when an object is created with parameters.
        Example: Build b(5);
    ---------------------------------------------------------------------------------
        🧠 CPU & MEMORY BEHAVIOR:
        - Same stack memory allocation for object.
        - Then, this constructor initializes values using passed arguments.
        - Heap allocation can also happen here (optional).
    ---------------------------------------------------------------------------------
    */
    Build(int val) {
        DefaultValue = 0;
        Value = val;
        ptr = new int[3]; // different size to visualize distinction
        cout << "[Constructor] Object created with value: " << val << endl;
    }

    /*
    ---------------------------------------------------------------------------------
        Destructor
        -----------
        Called automatically when the object goes out of scope.
        - Used to free dynamically allocated memory.
        - Always starts with '~' followed by class name.
    ---------------------------------------------------------------------------------
        🧠 CPU & MEMORY BEHAVIOR:
        - CPU executes destructor code before stack memory is released.
        - Heap memory (allocated via `new`) must be released using `delete`.
        - After this, stack memory is automatically cleaned up.
    ---------------------------------------------------------------------------------
    */
    ~Build() {
        delete[] ptr; // release allocated memory
        cout << "[Destructor] Memory freed, object destroyed" << endl;
    }
};

/*
=====================================================================================
    MAIN FUNCTION
=====================================================================================
*/

int main() {
    cout << "\n--- Phase 1: Creating default object ---" << endl;
    Build obj1; // calls default constructor

    cout << "\n--- Phase 2: Creating parameterized object ---" << endl;
    Build obj2(42); // calls parameterized constructor

    cout << "\n--- Phase 3: End of main() ---" << endl;
    cout << "Objects will now be destroyed automatically..." << endl;

    /*
        🔹 When main() ends:
        - obj2 destructor runs first (LIFO order: last created, first destroyed).
        - Then obj1 destructor runs.
        - Both free their allocated heap memory.
    */

    return 0;
}

/*
=====================================================================================
    KNOWLEDGE RECAP
=====================================================================================

    🧱 CONSTRUCTOR
    --------------
    - A special function automatically called when an object is created.
    - Same name as class.
    - No return type.
    - Can be overloaded (default, parameterized, copy).

    🔹 Types:
        1. Default Constructor     → No arguments.
        2. Parameterized Constructor → Takes arguments.
        3. Copy Constructor        → Copies existing object (optional).

    🔹 Memory:
        - Stack → Object memory.
        - Heap  → Allocated manually via `new`.

    💀 DESTRUCTOR
    --------------
    - Starts with `~` and same name as class.
    - No parameters, no return type.
    - Automatically called when object goes out of scope.
    - Used to release heap memory or clean up resources.

    ⚙️ CPU EXECUTION ORDER
    -----------------------
        1️⃣ Allocate object memory on stack.
        2️⃣ Call constructor.
        3️⃣ Execute program code.
        4️⃣ When scope ends → call destructor.
        5️⃣ Release stack memory.

    🔄 ORDER OF CALLS (Stack-like behavior)
        - Constructors: top to bottom (creation order)
        - Destructors : bottom to top (reverse order)

    🧩 OOP Concept:
        Constructors + Destructors implement *Resource Management*
        → known as **RAII (Resource Acquisition Is Initialization)** in C++.

=====================================================================================
*/