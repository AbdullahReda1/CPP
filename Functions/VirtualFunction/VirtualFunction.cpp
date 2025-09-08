#include <iostream>
using namespace std;


class Base {
    public:

        virtual void FunctionInterface(void) {
            cout << "This is a calling to the virtual function interface from Base class" << endl;
        }

        virtual string FunctionBlueprint() {
            return "This is a calling to the virtual function blueprint from Base class \n";
        }
};

class Derived : public Base {
    public:
    void FunctionInterface() {
        cout << "A message from Derived Interface function" << endl;
    }

    void FunctionBlueprint() {
        return "A message from Derived blueprint function \n"
    }
};

int main(void) {
    
    return 0;
}