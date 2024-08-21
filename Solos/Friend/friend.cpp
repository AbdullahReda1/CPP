#include <iostream>

using namespace std;


class B; // Forward declaration

class A
{
    private:
        int privateDataA;

        friend class B;         // Declare B as a "friend" class which make `its all members` accessable

        friend void printPrivateData(const A& obj);     // Declare a non-member function as a "friend"

    public:
        A(int data) : privateDataA(data) {}

        // Overloaded operator << as a "friend" function
        friend ostream& operator <<(ostream& os, const A& obj) { os << "Private Data A: \t\t" << obj.privateDataA; return os; }
};

class B
{
    private:
        int privateDataB;

    public:
        B(int data) : privateDataB(data) {}

        void accessDataA(const A& obj) { cout << "Private Data A accessed from B: " << obj.privateDataA << endl; }

        // Class B can access both the private members of class A and - cascade down - its own private members.
        void accessDataB(const B& obj) { cout << "Private Data B accessed from B: " << obj.privateDataB << endl; }
};

void printPrivateData(const A& obj) { cout << "Printing private data of A:     " << obj.privateDataA << endl; }


int main()
{
    A objectA(10);
    B objectB(20);

    objectB.accessDataA(objectA);
    objectB.accessDataB(objectB);
    printPrivateData(objectA);
    cout << objectA << endl << endl;
}