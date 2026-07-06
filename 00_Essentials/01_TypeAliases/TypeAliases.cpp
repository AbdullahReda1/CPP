#include <iostream>

using namespace std;


// Using typename to create a new name for an existing type in a template to make the code more readable and easier to maintain.
// `typename` is used to declare a type in a template.
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}   // The return type of add() is the type of the expression a + b.


int main()
{
    // Using teypedef to create a new name for an existing type.

    typedef int var;    // var is an alias for int.
    var X = 5;
    cout << X << "\ttype of X: " << typeid(X).name() << endl;


    // Using decltype to get the type of a variable.

    /*
        It allows you to deduce the type of a variable or expression at compile time.
        This can be particularly useful in template programming and when working with complex types.
    */
    int z = 5;
    decltype(z) y = 10;     // y is of type int because z is of type int.
    cout << y << "\ttype of y: " << typeid(y).name() << endl;

    auto result = add(5, 3.14);    // result is of type double because 5 + 3.14 is of type double.
    cout << result << "\ttype of result: " << typeid(result).name() << endl;
}