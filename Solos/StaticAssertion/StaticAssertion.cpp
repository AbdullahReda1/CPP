#include <iostream>

using namespace std;


int main()
{
    /* Static assertion using `#error` directive */

    #if !defined(some_file)
        //#error "error, some_file is not defined"
    #endif

    /* Static assertion using `static_assert` keyword */
    
    // 1. Unlike #error, assertion using static_assert takes place after the preprocessing translation stage.
    //    Therefore, it is possible to check for the size of a datatype with sizeof using static_assert.
    // 2. Libraries can detect common usage errors at compile time.
    // 3. Implementations of the C++ Standard Library can detect and diagnose common usage errors, improving usability.
    
    // `static_assert` is a software assertion (a condition that you expect to be true at a particular point in your program).

    // `static_assert` scopes are global "Declaration Scopes" "namespace scope", class, and block.
    static_assert(sizeof(int) == 4, "int is not 4 bytes size");
    cout << "assertion passed. The program didn't produce an error" << endl;

    return 0;
}