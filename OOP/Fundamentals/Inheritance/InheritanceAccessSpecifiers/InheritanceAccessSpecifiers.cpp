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
    public:
        void ShowAccess() {
            AccessPublic();
            AccessProtected();
        }
};

// protected access inheritance
class Derived2 : protected Base {
    public:
        void ShowAccess() {
            AccessPublic();
            AccessProtected();
        }
};

// private access inheritance
class Derived3 : private Base {
    public:
        void ShowAccess() {
            AccessPublic();
            AccessProtected();
        }
};


int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;



    return 0;
}