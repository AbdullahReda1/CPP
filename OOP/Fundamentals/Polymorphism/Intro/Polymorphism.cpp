#include <iostream>
using namespace std;

/*
    POLYMORPHISM DEMO
    -----------------
    - Shows both Compile-time (function overloading) 
    and Run-time (virtual functions) polymorphism.

    Memory/CPU Flow:
    ----------------
    1) Compile-time polymorphism → function chosen at COMPILE time.
    2) Run-time polymorphism → function chosen at RUN time using vtable.
*/

// --------------------
// Compile-time Polymorphism (Function Overloading)
// --------------------
class MathOps {
    public:
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) {
            return a + b;
        }
};

// --------------------
// Run-time Polymorphism (Virtual Functions)
// --------------------
class Animal {
    public:
        virtual void speak() {   // virtual → runtime binding
            cout << "Animal makes a sound" << endl;
        }
};

class Dog : public Animal {
    public:
        void speak() override {  // override → safety check
            cout << "Dog barks" << endl;
        }
};

class Cat : public Animal {
    public:
        void speak() override {
            cout << "Cat meows" << endl;
        }
};


int main() {
    cout << "\n--- Compile-time Polymorphism ---" << endl;
    MathOps m;
    cout << "add(int, int): " << m.add(2, 3) << endl;
    cout << "add(double, double): " << m.add(2.5, 3.7) << endl;

    cout << "\n--- Run-time Polymorphism ---" << endl;
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak();  // resolved at runtime → "Dog barks"
    a2->speak();  // resolved at runtime → "Cat meows"
    
    return 0;
}