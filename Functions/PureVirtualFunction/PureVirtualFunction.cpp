#include <iostream>   // Standard input-output stream
using namespace std;

/*
 * -------------------------------------------------------------------
 * ABSTRACT BASE CLASS: AbstractShape
 * -------------------------------------------------------------------
 * - Declares a pure virtual function (func = 0).
 * - A pure virtual function makes this class ABSTRACT.
 * - Abstract classes cannot be instantiated directly.
 * - Serves as a blueprint (or interface) for derived classes.
 */
class AbstractShape {
public:
    // Pure virtual function (blueprint only, no implementation here).
    // "= 0" tells the compiler that derived classes MUST override this.
    virtual void draw() = 0;
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS: Circle
 * -------------------------------------------------------------------
 * - Inherits from AbstractShape.
 * - Provides an implementation for the pure virtual function "draw".
 * - Because "draw" is implemented here, Circle is a concrete class.
 */
class Circle : public AbstractShape {
public:
    // Override pure virtual function
    void draw() {
        cout << "[Circle] Drawing a circle: implementing the abstract draw() function" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * MAIN FUNCTION
 * -------------------------------------------------------------------
 * - Demonstrates abstraction + polymorphism
 * - Base-class pointer points to a derived-class object
 * - Calls the derived implementation at runtime (dynamic dispatch)
 */
int main() {
    //! AbstractShape* shape = new AbstractShape(); ❌ ERROR: cannot instantiate abstract class

    AbstractShape* shape = new Circle(); // ✅ Allowed: Base pointer → Derived object

    // Calls Circle’s implementation of draw() at runtime
    shape->draw();

    return 0;
}

/*
 * -------------------------------------------------------------------
 * 🔎 DEEP EXPLANATION: PURE VIRTUAL FUNCTION PROCESS
 * -------------------------------------------------------------------
 *
 * 1. COMPILATION STAGE:
 *    - The compiler sees "= 0" → marks AbstractShape as ABSTRACT.
 *    - AbstractShape cannot be instantiated directly.
 *    - Compiler generates a VTABLE (virtual table) entry for "draw",
 *      but since it is pure, it only marks it as "unimplemented".
 *
 * 2. OBJECT CREATION (MEMORY LAYOUT):
 *    - When we instantiate Circle, the compiler creates a vtable
 *      for Circle containing the pointer to Circle::draw().
 *    - The object of Circle contains a hidden VPTR (virtual pointer)
 *      pointing to this vtable.
 *
 * 3. RUNTIME EXECUTION (DYNAMIC DISPATCH):
 *    - When calling shape->draw():
 *        (a) CPU loads VPTR from the object (in RAM).
 *        (b) Follows VPTR to Circle’s vtable.
 *        (c) Finds function pointer for draw() → jumps to Circle::draw().
 *
 * 4. CPU/ASSEMBLY LEVEL:
 *    - Normal (non-virtual) calls = direct "CALL" to a fixed address.
 *    - Pure virtual overridden calls = indirect "CALL [address_in_vtable]".
 *    - This is slightly slower than static dispatch but enables abstraction
 *      and polymorphism at runtime.
 *
 * -------------------------------------------------------------------
 * SUMMARY:
 * - "= 0" makes a function PURE VIRTUAL.
 * - Abstract classes are blueprints (cannot be instantiated).
 * - Derived classes must implement pure virtual functions to be concrete.
 * - Polymorphism ensures the correct overridden function runs at runtime.
 * -------------------------------------------------------------------
 */
