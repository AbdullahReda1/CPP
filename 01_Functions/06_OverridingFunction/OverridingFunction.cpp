#include <iostream>   // Standard I/O stream
using namespace std;

/*
 * -------------------------------------------------------------------
 * BASE CLASS: MessagePrinter
 * -------------------------------------------------------------------
 * - Declares a virtual function "printMessage".
 * - Virtual enables runtime polymorphism (dynamic dispatch).
 */
class MessagePrinter {
public:
    // Virtual function: can be overridden in derived classes
    virtual void printMessage() {
        cout << "[Base] Message from MessagePrinter (virtual function)" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS: CustomPrinter
 * -------------------------------------------------------------------
 * - Inherits from MessagePrinter
 * - Overrides "printMessage" using the "override" keyword
 * - "override" ensures compiler checks that the base has a matching
 *   virtual function with the exact same signature.
 */
class CustomPrinter : public MessagePrinter {
public:
    // Correctly overrides base class method
    void printMessage() override {
        cout << "[Derived] Message from CustomPrinter (overridden function)" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * MAIN FUNCTION
 * -------------------------------------------------------------------
 * - Demonstrates overriding with the "override" keyword
 * - Base pointer points to Derived object
 * - At runtime, Derived version of printMessage() is called
 */
int main() {
    // Base class pointer, but object is of type CustomPrinter
    MessagePrinter* printer = new CustomPrinter();

    // Virtual function → resolved dynamically at runtime
    printer->printMessage();

    return 0;
}

/*
 * -------------------------------------------------------------------
 * 🔎 DEEP EXPLANATION: ROLE OF "override"
 * -------------------------------------------------------------------
 ? *
 ? * 1. Without "override":
 ? *    - The compiler assumes we *intend* to override, but it doesn’t check.
 ? *    - If we make a mistake (e.g., typo in function name, wrong signature),
 ? *      the compiler silently creates a *new* function instead of overriding.
 ? *
 ? * 2. With "override":
 ? *    - The compiler enforces that the function truly overrides a virtual
 ? *      function in the base class.
 ? *    - If no matching virtual function exists, compilation fails.
 ? *    - This prevents subtle bugs.
 *
 * -------------------------------------------------------------------
 * 🔎 COMPILATION & EXECUTION PROCESS
 * -------------------------------------------------------------------
 *
 * Compilation:
 *  - Base class has a vtable with an entry for printMessage().
 *  - Derived class’s vtable replaces that entry with CustomPrinter::printMessage().
 *
 * Object Creation:
 *  - The CustomPrinter object contains a hidden VPTR (virtual pointer).
 *  - VPTR points to CustomPrinter’s vtable.
 *
 * Runtime Call:
 *  - printer->printMessage() is called.
 *  - CPU:
 *      (a) Loads VPTR from object in RAM.
 *      (b) Follows VPTR to the vtable in memory.
 *      (c) Finds function pointer for CustomPrinter::printMessage().
 *      (d) Executes it using an indirect CALL instruction.
 *
 * -------------------------------------------------------------------
 * SUMMARY:
 * - "virtual" enables runtime polymorphism.
 * - "override" ensures correctness at compile-time.
 * - Together, they make polymorphic behavior safe and predictable.
 * -------------------------------------------------------------------
 */