#include <iostream>
using namespace std;


// Function declaration
int sum(int a, int b);      // Value-Returning Function
void print_Func();          // Void Function


int main() {
    int num1, num2, Result;
    cout << "Enter two int numbers" << endl << "---------------------" << endl;
    cout << "Enter first numbers: ";
    cin >> num1;
    cout << "Enter second numbers: ";
    cin >> num2;

    // Value-Returning Function call
    /*
        the cpu will jump to the function definition and execute the code inside the function
        then return the result to the main function and continue the execution of the main function.
    */
    Result = sum(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is: " << Result << endl;

    // Void Function call
    print_Func();

    return 0;
}


// Function definition
int sum(int a, int b) {
    return (a + b);
}

void print_Func() {
    cout << "Print function is called" << endl;
}