#include <iostream>
using namespace std;


int main() {
    
    return 0;
}

/*
Function overloading in C++ allows the creation of multiple functions within the same scope that share the same name but differ in their parameter lists. This difference can be in the number of parameters, the data types of the parameters, or the order of the parameter types.
When an overloaded function is called, the C++ compiler determines which specific function to invoke by comparing the arguments provided in the function call with the parameter lists (signatures) of all candidate functions with that name. This process is known as overload resolution. 
Key characteristics of overloaded functions:
Same Name: All overloaded functions share the identical function name.
Different Signatures: The distinguishing factor is their parameter list, which includes the number, type, and order of parameters. Return types alone are not sufficient to overload a function; the parameter list must differ.
Compile-time Polymorphism: Function overloading is a form of compile-time polymorphism, meaning the specific function to be executed is resolved during the compilation phase, not at runtime.
Overload resolution in C++ is the process by which the compiler determines which specific function, from a set of overloaded functions with the same name, should be called based on the arguments provided in a function call. This process involves several steps:
Name Lookup:
The compiler first identifies all functions with the given name that are visible within the scope where the function call is made. These are known as candidate functions.
Candidate Function Set:
From the candidate functions, the compiler forms a set of viable functions. A function is viable if: 
Its number of parameters matches the number of arguments in the function call (or default arguments can fill missing parameters).
Each argument can be converted to the type of its corresponding parameter through an implicit conversion sequence.
Best Viable Function Selection:
The compiler then selects the "best" viable function from the set. This is done by comparing the implicit conversion sequences required to convert the arguments to the parameter types for each viable function. The "best" function is the one that requires the "least specialized" or "most direct" conversions. The hierarchy of implicit conversions, from best to worst, typically includes: 
Exact match (no conversion needed).
Lvalue-to-rvalue conversion, array-to-pointer conversion, function-to-pointer conversion.
Qualification conversions (e.g., adding const).
Integral promotions (e.g., char to int).
Integral conversions (e.g., int to long).
Floating-point promotions and conversions.
Pointer conversions (e.g., derived to base class pointer).
User-defined conversions.
Ellipsis (...).
Ambiguity:
If there are multiple viable functions that are considered equally good matches (i.e., no single function is "better" than all others), the call is considered ambiguous, and the compiler will typically issue an error.
Access Control:
After overload resolution determines the best viable function, access control rules are applied. If the selected function is not accessible from the call site (e.g., a private member function called from outside the class), the program is ill-formed.
Here's how the compiler resolves overloaded functions and their relation to memory:
Name Mangling (or Name Decoration): During compilation, the C++ compiler modifies the names of overloaded functions to create unique, internal names. This process is called name mangling or name decoration. The mangled name typically encodes information about the original function name, its namespace, and its parameter types. This allows the linker to distinguish between different overloaded functions even though they share the same source-level name.
For example, a function void func(int) might be mangled to something like _Z4funci, while void func(double) might be mangled to _Z4funcd.
Memory Resolution (Linker Phase):
After compilation, the linker takes the object files (containing the mangled function names) and resolves references to these functions. Since each overloaded function has a unique mangled name, the linker can correctly identify and link the specific function implementation chosen during overload resolution to its corresponding memory location in the executable.
*/