/*
=====================================================================================
    File: GettersAndSetters.cpp
    Topic: Encapsulation and Data Access Control in OOP
-------------------------------------------------------------------------------------
    🎯 Goal:
        - Learn how to use getter and setter functions.
        - Understand data encapsulation and controlled access to private members.
        - Observe how memory and CPU handle these operations.
=====================================================================================
*/

#include <iostream>
using namespace std;

/*
=====================================================================================
    SECTION 1: CLASS DEFINITION
=====================================================================================
    The class `Value` encapsulates (hides) its data.
    The private variable `Number` cannot be accessed directly outside the class.
=====================================================================================
*/

class Value {
private:
    int Number;   // Private member — accessible only within this class.

public:
    /*
    -------------------------------------------------------------------------------
        Setter Function — setNumber(int val)
        -------------------------------------
        - Purpose: Assign a value to the private member `Number`.
        - Input : int val → new value to assign.
        - Output: None (void).
        - Access: Public → can be called from outside the class.
    -------------------------------------------------------------------------------
        🧠 CPU & MEMORY FLOW:
        - Parameter `val` is passed via a register or the call stack.
        - The function writes `val` into the object's memory location corresponding to its `Number` member.
        - CPU performs a "store" instruction (MOV) to that address.
    -------------------------------------------------------------------------------
    */
    void setNumber(int val) {
        Number = val;
    }

    /*
    -------------------------------------------------------------------------------
        Getter Function — getNumber(void)
        ----------------------------------
        - Purpose: Return the value of `Number`.
        - Output : int (value of the private data member).
        - `const` keyword means this function does not modify any class data.
    -------------------------------------------------------------------------------
        🧠 CPU & MEMORY FLOW:
        - CPU loads the integer stored at the object's memory address for `Number`.
        - Returns that value through a CPU register (like EAX/RAX).
    -------------------------------------------------------------------------------
    */
    int getNumber(void) const {
        return Number;
    }
};

/*
=====================================================================================
    SECTION 2: MAIN FUNCTION — EXECUTION FLOW
=====================================================================================
*/

int main() {
    /*
    -------------------------------------------------------------------------------
        Step 1: Object Creation
        -----------------------
        - `Value value;`
        - Memory is allocated on the stack for the object `value`.
        - Inside that memory block, space for `Number` is reserved (4 bytes typical).
    -------------------------------------------------------------------------------
    */
    Value value;

    /*
    -------------------------------------------------------------------------------
        Step 2: Using the Setter Function
        ---------------------------------
        - Calls `setNumber(5)`.
        - This writes the integer 5 into the `Number` memory cell of the object.
    -------------------------------------------------------------------------------
    */
    value.setNumber(5);

    /*
    -------------------------------------------------------------------------------
        Step 3: Using the Getter Function
        ---------------------------------
        - Calls `getNumber()`.
        - Reads the current stored integer from the object's private data.
        - CPU fetches the value and sends it back to main().
    -------------------------------------------------------------------------------
    */
    cout << "The stored value is: " << value.getNumber() << endl;

    /*
    -------------------------------------------------------------------------------
        Step 4: Program End
        -------------------
        - Object `value` goes out of scope.
        - Stack memory used by it is automatically released.
    -------------------------------------------------------------------------------
    */

    return 0;
}

/*
=====================================================================================
    KNOWLEDGE RECAP
=====================================================================================

    🔹 Concept: Encapsulation
        → Hiding internal data (private) and exposing access methods (public).

    🔹 Getters
        → Allow safe read access to private variables.

    🔹 Setters
        → Allow controlled modification of private variables (can include validation).

    🔹 const Keyword
        → Ensures getter doesn’t modify the object.

    🔹 Why use them?
        - Protect internal data from corruption.
        - Add data validation logic inside setter (e.g., range checks).
        - Improve modularity and maintainability.

    🔹 CPU/Memory Summary
        - Each object has its own memory block for private members.
        - Functions operate on that block via hidden object pointers.
        - Getter = CPU LOAD instruction.
        - Setter = CPU STORE instruction.

    🔹 OOP Connection:
        - This is the foundation of *Encapsulation* — the “E” in the OOP pillars.
        - You’ll use getters/setters everywhere — even in inheritance and polymorphism.
=====================================================================================
*/