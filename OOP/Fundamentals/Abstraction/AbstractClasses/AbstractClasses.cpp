#include <iostream>   // Standard I/O library
using namespace std;

/*
 * -------------------------------------------------------------------
 * ABSTRACT BASE CLASS: Shape
 * -------------------------------------------------------------------
 * - Represents a general "Shape" blueprint.
 * - Declares a pure virtual function Draw().
 * - Pure virtual function (= 0) makes this class ABSTRACT.
 * - Abstract classes cannot be instantiated directly.
 * - Derived classes must implement Draw().
 */
class Shape {
public:
    // Pure virtual function → no implementation here.
    virtual void draw() = 0;
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS: Circle
 * -------------------------------------------------------------------
 * - Inherits from Shape.
 * - Implements the pure virtual function draw().
 */
class Circle : public Shape {
public:
    void draw() override {
        cout << "[Circle] ⚪ Drawing a Circle" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS: Square
 * -------------------------------------------------------------------
 * - Inherits from Shape.
 * - Implements the pure virtual function draw().
 */
class Square : public Shape {
public:
    void draw() override {
        cout << "[Square] ⬜ Drawing a Square" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * DERIVED CLASS: Heart
 * -------------------------------------------------------------------
 * - Inherits from Shape.
 * - Implements the pure virtual function draw().
 */
class Heart : public Shape {
public:
    void draw() override {
        cout << "[Heart] 🤍 Drawing a Heart" << endl;
    }
};

/*
 * -------------------------------------------------------------------
 * MAIN FUNCTION
 * -------------------------------------------------------------------
 * - Demonstrates abstraction + polymorphism.
 * - Base-class pointer can point to any derived class object.
 * - Calls the correct overridden draw() function at runtime.
 */
int main() {
    // Abstract class cannot be instantiated:
    // Shape s;        ❌ ERROR
    // Shape* shape = new Shape(); ❌ ERROR

    // ✅ Base pointers → Derived objects
    Shape* circle = new Circle();
    Shape* square = new Square();
    Shape* heart  = new Heart();

    // Runtime polymorphism: correct draw() is called
    circle->draw();
    square->draw();
    heart->draw();

    return 0;
}

/*
 * -------------------------------------------------------------------
 * 🔎 DEEP EXPLANATION: ABSTRACTION IN C++
 * -------------------------------------------------------------------
 *
 * 1. ABSTRACT CLASSES:
 *    - Declaring at least one pure virtual function (= 0) makes a class abstract.
 *    - Abstract classes serve as blueprints/interfaces.
 *    - They cannot be instantiated directly.
 *
 * 2. DERIVED CLASSES:
 *    - Must provide an implementation for all pure virtual functions.
 *    - If a derived class does NOT implement them, it also remains abstract.
 *
 * 3. COMPILATION STAGE:
 *    - Compiler generates a vtable for each derived class.
 *    - For abstract classes, the vtable has "pure" placeholders
 *      (no function address until derived overrides it).
 *
 * 4. OBJECT CREATION (MEMORY LAYOUT):
 *    - Derived objects (Circle, Square, Heart) contain a VPTR (virtual pointer).
 *    - VPTR points to their respective vtables with function pointers to draw().
 *
 * 5. RUNTIME EXECUTION (DYNAMIC DISPATCH):
 *    - Example: circle->draw();
 *      (a) CPU loads VPTR from Circle object in RAM.
 *      (b) Follows VPTR to Circle’s vtable.
 *      (c) Finds address of Circle::draw().
 *      (d) Executes via indirect CALL instruction.
 *
 * 6. ABSTRACTION BENEFIT:
 *    - The user of the Shape interface doesn’t care HOW each shape is drawn.
 *    - Only knows that every shape has a "draw" function.
 *    - This decouples interface (what to do) from implementation (how to do it).
 *
 * -------------------------------------------------------------------
 * SUMMARY:
 * - Abstract classes define a contract/blueprint.
 * - Derived classes provide concrete implementations.
 * - Polymorphism ensures correct method execution at runtime.
 * - This is the core of Abstraction in OOP.
 * -------------------------------------------------------------------
 */