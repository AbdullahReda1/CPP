#include <iostream>
using namespace std;


class parentBase {
    public:
        void PBMSG() {
            cout << "Message from parent base" << endl;
        }
};

class DerivedChild1 : public parentBase {
    public:
        void DCHMSG1() {
            cout << "message from first derived child" << endl;
        }
};

class DerivedChild2 : public parentBase {
    public:
        void DCHMSG2() {
            cout << "message from second derived child" << endl;
        }
};

class SubDerivedGrandChild : public DerivedChild1, public DerivedChild2 {
    public:
        void SDGCHMSG(){
            cout << "message from subderived grand child" << endl;
        }
};

int main() {


    return 0;
}