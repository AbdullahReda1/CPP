#include <iostream>
using namespace std;


// Inline function; helps to reduce the function call overhead
// Inline function is a function that is expanded in line when it is called.
// When the inline function is called whole code of the inline function gets inserted or expanded at the point of inline function call.
// This expansion is performed by the compiler at the compile time. Inline function may increase efficiency if it is small.
inline int add(int a, int b) { return a + b; }

// Prototyping an inline function
inline int multiply(int a, int b);

int main() {
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a;
    cin >> b;

    // Calling inline function
    cout << "Sum: " << add(a, b) << endl;
    cout << "Product: " << multiply(a, b) << endl;

    return 0;
}


// Inline function definition
inline int multiply(int a, int b) { return a * b; }