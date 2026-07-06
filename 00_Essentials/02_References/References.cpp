#include <iostream>
using namespace std;

/*
---------------------------------------------------------
    📘  C++ REFERENCES – Full Demonstration
---------------------------------------------------------
This program illustrates:
    1️⃣  L-value references (&)
    2️⃣  Const references (const &)
    3️⃣  R-value references (&&)
    4️⃣  References as function parameters
    5️⃣  Global variable references
---------------------------------------------------------
*/

//------------------------------------------------------
// 🧠 Global variable – stored in data segment
//------------------------------------------------------
int Gvar = 9;

//------------------------------------------------------
// 🧩 Function using reference parameter
// Returns the same value via reference (no copy).
//------------------------------------------------------
int GetByReference(int &ref_var) {
    // CPU: 'ref_var' is just another name for the original variable.
    // MOV EAX, [address_of_ref_var]
    return ref_var;
}

//------------------------------------------------------
// 🧩 Another function using a reference
//------------------------------------------------------
int GetGlobalVar(int &ref) {
    return ref;
}

//------------------------------------------------------
// 🧩 MAIN EXECUTION FLOW
//------------------------------------------------------
int main() {

    /*
        --- Step 1: L-value reference ---
        ---------------------------------
        - Created using '&'
        - Must refer to a valid object (cannot be null)
        - Acts as an alias (no new memory allocation)
    */
    int VARIABLE0 = 4;          // Stored on stack
    // double VARIABLE0 = 4;       Error: type mismatch for reference
    int & L_ref = VARIABLE0;     // L_ref binds to the same address as VARIABLE0

    cout << L_ref << endl;      // prints 4
    L_ref++;                    // modifies VARIABLE0 directly (VARIABLE0 = 5)
    cout << L_ref << endl;      // prints 5

    /*
        --- Step 2: Const reference ---
        ---------------------------------
        - Can bind to l-values and r-values
        - Read-only; cannot modify the underlying object
    */
    int VARIABLE1 = 6;
    const int & C_ref = VARIABLE1;  // const reference bound to VARIABLE1
    cout << C_ref << endl;         // prints 6
    // C_ref++; ❌ Error: cannot modify const reference target

    /*
        --- Step 3: R-value reference (C++11) ---
        ---------------------------------
        - Declared using '&&'
        - Binds to temporaries (values without names)
        - Enables move semantics (optimization)
    */
    int && R_ref = 6;           // R_ref binds to temporary integer object
    R_ref++;                   // allowed; modifies the temporary
    cout << R_ref << endl;     // prints 7

    /*
        --- Step 4: Function call by reference ---
        ---------------------------------
        - No copy occurs; function directly accesses caller’s variable
        - CPU passes address, not value
    */
    int var = 8;
    int & ref = var;                     // ref is alias for var
    cout << GetByReference(ref) << endl;  // prints 8 (reads var via reference)

    /*
        --- Step 5: Reference to a global variable ---
        ---------------------------------
        - Works exactly like local references
        - Refers to data segment memory
    */
    int & reference = Gvar;                     // alias to Gvar (global memory)
    cout << GetByReference(reference) << endl;  // prints 9

    /*
        --- Step 6: CPU + Memory Recap ---
        ---------------------------------
        Stack:
            VARIABLE0 (5)
            L_ref -> [alias to VARIABLE0]
            VARIABLE1 (6)
            C_ref  -> [alias to VARIABLE1, read-only]
            R_ref  -> [temporary 7]
            var    (8)
            ref    -> [alias to var]
        Data Segment:
            Gvar (9)
            reference -> [alias to Gvar]
    */

    return 0;
}

/*
----------------------------------------------------------
🧩 KNOWLEDGE & CONCEPTUAL SUMMARY
----------------------------------------------------------
✅  Reference = Alias to another variable (not a copy)
✅  Must be initialized at declaration
✅  Cannot be null or reseated
✅  L-value reference binds to normal variables
✅  Const reference can bind to temporaries & literals
✅  R-value reference binds to temporary (for moves)
✅  CPU passes references as addresses internally
✅  References introduce zero runtime overhead
✅  Common uses:
    - Function parameters (avoid copies)
    - Return values (allow chaining)
    - Operator overloading
    - Constructors & copy semantics
    - Polymorphism and dynamic dispatch
----------------------------------------------------------
*/