#include <iostream>
using namespace std;

// Pass by Value: Passing a copy of the variable
void incrementValue(int num) {
    num++;
    cout << "Inside incrementValue (by value): " << num << endl;
}

// Pass by Reference: Passing the actual variable
void incrementReference(int &num) {
    num++;
    cout << "Inside incrementReference (by reference): " << num << endl;
}

// Pass by Pointer: Passing the address of the variable
void incrementPointer(int *num) {
    (*num)++;
    cout << "Inside incrementPointer (by pointer): " << *num << endl;
}

int main() {
    int x = 5;

    incrementValue(x);
    cout << "After incrementValue: " << x << endl; // x is still 5

    incrementReference(x);
    cout << "After incrementReference: " << x << endl; // x is now 6

    incrementPointer(&x);
    cout << "After incrementPointer: " << x << endl; // x is now 7

    return 0;
}