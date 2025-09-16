#include <iostream>
using namespace std;


class Base {
    private:
        void Accessprivate() {
            cout << "Private Base Data" << endl;
        }
    protected:
        void AccessProtected() {
            cout << "Protected Base Date" << endl;
        }
    public:
        void AccessPublic() {
            cout << "Public Base Data" << endl;
        }
};

// public access inheritance
class Derived1 : public Base {

};

// protected access inheritance
class Derived2 : protected Base {

};

// private access inheritance
class Derived3 : private Base {

};


int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    d1.AccessPublic();
    d1.AccessProtected();
    d1.Accessprivate();
    
    d2.AccessPublic();
    d2.AccessProtected();
    d2.Accessprivate();

    d3.AccessPublic();
    d3.AccessProtected();
    d3.Accessprivate();

    return 0;
}