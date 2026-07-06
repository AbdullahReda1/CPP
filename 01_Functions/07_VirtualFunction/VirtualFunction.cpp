#include <iostream>   // Standard I/O stream library
using namespace std;

/*
 * -------------------------------------------------------------------
 * BASE CLASS: Shape_Interface_Blueprint
 * -------------------------------------------------------------------
 * - Demonstrates the concept of virtual functions in C++.
 * - Contains virtual methods that serve as "blueprints" for derived classes.
 * - Virtual keyword allows dynamic (runtime) binding through the vtable mechanism.
 */
class Shape_Interface_Blueprint {
    public:

        // Virtual function: defines an "interface" to be overridden
        virtual void displayInterfaceMessage() {
            cout << "[Base] Default interface message from Shape_Interface_Blueprint" << endl;
        }

        // Virtual function: blueprint-style, returns a string
        virtual string getBlueprintDescription() {
            return "[Base] Default blueprint description from Shape_Interface_Blueprint\n";
        }
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS 1: CircleShape
 * -------------------------------------------------------------------
 * - Inherits from Shape_Interface_Blueprint
 * - Overrides both virtual methods with specific behavior
 */
class CircleShape : public Shape_Interface_Blueprint {
    public:

        // Override interface function
        void displayInterfaceMessage() {
            cout << "[Derived: Circle] Interface message for CircleShape" << endl;
        }

        // Override blueprint function
        string getBlueprintDescription() {
            return "[Derived: Circle] Blueprint for CircleShape\n";
        }
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS 2: SquareShape
 * -------------------------------------------------------------------
 * - Inherits from Shape_Interface_Blueprint
 * - Overrides both virtual methods with specific behavior
 */
class SquareShape : public Shape_Interface_Blueprint {
    public:

        // Override interface function
        void displayInterfaceMessage() {
            cout << "[Derived: Square] Interface message for SquareShape" << endl;
        }

        // Override blueprint function
        string getBlueprintDescription() {
            return "[Derived: Square] Blueprint for SquareShape\n";
        }
};

/*
 * -------------------------------------------------------------------
 * MAIN FUNCTION
 * -------------------------------------------------------------------
 * - Demonstrates polymorphism using virtual functions
 * - Creates an array of base-class pointers
 * - Stores base and derived objects inside
 * - Calls overridden methods through base pointers
 */
int main() {
    // Array of base class pointers (to demonstrate polymorphism)
    Shape_Interface_Blueprint* shapePtrs[3];

    // Dynamically allocate objects of base and derived types
    shapePtrs[0] = new Shape_Interface_Blueprint();     // Base class instance
    shapePtrs[1] = new CircleShape();                   // Derived class instance: Circle
    shapePtrs[2] = new SquareShape();                   // Derived class instance: Square

    // Loop through array and call virtual functions
    for (int i = 0; i < 3; i++) {
        // Calls overridden displayInterfaceMessage() dynamically at runtime
        shapePtrs[i]->displayInterfaceMessage();

        // Calls overridden getBlueprintDescription() dynamically at runtime
        cout << shapePtrs[i]->getBlueprintDescription() << endl;
    }

    return 0;
}

/*
 * -------------------------------------------------------------------
 * 🔎 DEEP EXPLANATION: HOW VIRTUAL FUNCTIONS WORK
 * -------------------------------------------------------------------
 *
 * 1. COMPILATION STAGE:
 *    - The compiler sees the keyword "virtual" and generates a hidden
 *      structure called the VTABLE (Virtual Table).
 *    - Each class with virtual functions gets its own vtable.
 *    - Each entry in the vtable is a function pointer pointing to
 *      the correct implementation of the virtual function.
 *
 * 2. OBJECT CREATION (MEMORY LAYOUT):
 *    - When an object of a class with virtual functions is created,
 *      the compiler inserts a hidden pointer inside the object called
 *      the VPTR (Virtual Pointer).
 *    - The VPTR points to the class’s vtable.
 *
 * 3. RUNTIME EXECUTION (DYNAMIC DISPATCH):
 *    - When we call a virtual function through a base pointer:
 *        shapePtrs[i]->displayInterfaceMessage();
 *      The CPU:
 *        (a) Loads the VPTR from the object (in RAM).
 *        (b) Follows the VPTR to find the correct vtable (in memory).
 *        (c) Uses the function pointer in the vtable to jump to the
 *            correct function implementation (base or derived).
 *
 * 4. CPU/ASSEMBLY LEVEL:
 *    - Non-virtual calls = direct "CALL" instruction to fixed address.
 *    - Virtual calls = indirect "CALL [address_in_vtable]" instruction.
 *    - This indirection enables polymorphism but costs a single
 *      pointer dereference at runtime.
 *
 * -------------------------------------------------------------------
 * SUMMARY:
 * - "virtual" keyword enables runtime polymorphism via vtables.
 * - Derived classes override base class behavior cleanly.
 * - Base class pointers can point to derived objects and still call
 *   the correct overridden methods.
 * -------------------------------------------------------------------
 */