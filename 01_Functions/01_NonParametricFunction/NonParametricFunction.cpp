#include <iostream>
using namespace std;

// Non-parametric function (no parameters) returning void
void greeting() {
    cout << "Hello from a non-parametric function!" << endl;
}

// Non-parametric function returning int
int getNumber() {
    return 42;
}


int main() {
    greeting();                     // Call the function
    cout << getNumber() << endl;    // Outputs: 42
    return 0;
}