#include <iostream>
using namespace std;


class Base {
    public:
        virtual void func() = 0;
};

class Derived : public Base {
    public:
        void func() {
            cout << "this illustrating the pure virtual functoin concept and its aplication for abstraction" << endl;
        }
};


int main() {
    Base *f = new Derived();

    f->func();

    return 0;
}