#include <iostream>
using namespace std;

/*
!-----------------------------------------------------------------------------------
*| Scope / Access Modifiers | Global | Derived class | Friend class | Within class |
?|--------------------------|--------|---------------|--------------|--------------|
*| Private                  |    X   |        X      |       ✓      |       ✓      |
*| Protected                |    X   |        ✓      |       ✓      |       ✓      |
*| Public                   |    ✓   |        ✓      |       ✓      |       ✓      |
!-----------------------------------------------------------------------------------
*/
class Data {
    /* This access modifier allows us to access the class members only to the class methods and the friend functions and classes */
    private:
        string CryptoMSG = "97F2A05A";

    /* This access modifier allows us to have the flexibility to keep the class members private and accessible to its derived or friend class */
    protected:
        int ProtectivID = 102;

    /* This access modifier makes the class members be accessible anywhere in the program */
    public:
        void CryptoMSGFunc() { cout << CryptoMSG << endl; }
};

// Derived Class (inherited)
class BankData: public Data {
    public:
        void ProtectivIDFunc() { cout << ProtectivID << endl; }
};


int main() {
    BankData b;
    b.CryptoMSGFunc();       // Access base class public method
    b.ProtectivIDFunc();     // Access protected member via derived class method
    return 0;
}