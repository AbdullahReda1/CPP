#include <iostream>
using namespace std;


class Base {
    public:

        virtual void VirtualFunctionInterface(void) {
            cout << "This is a calling to the virtual function interface from Base class" << endl;
        }

        virtual int VirtualFunctionBlueprint() {

        }
};