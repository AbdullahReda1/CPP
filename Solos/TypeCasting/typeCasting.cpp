#include <iostream>

using namespace std;


/// @class   Base class serving as a base for derived classes.
/// @brief   This class provides a base for derived classes to inherit from.
/// @details It contains a virtual destructor to support polymorphic behavior.
class Base
{
    public:
        virtual ~Base() {}
};

/// @class Derived class derived from Base class.
/// @brief This class inherits from the Base class and provides additional functionality specific to the Derived class.
class Derived : public Base
{
    public:

        /// @brief   Performs a specific action unique to the Derived class.
        /// @fn      This method is specific to the Derived class and performs a particular action.
        /// @details In this case, it prints a message indicating that the Derived function has been called.
        void derivedFunction()
        {
            cout << "Derived function called." << endl << endl;
        }
};


int main()
{
    /**
     * @brief   Static Cast Example:
     * @details Demonstrates the usage of static_cast to convert a double variable to an int.
     */
    double doubleVar = 3.14;
    cout << "Befor converting double Variable to int: " << doubleVar << "\t,Its size: " << sizeof(doubleVar) << endl;
    int intVar = static_cast <int> (doubleVar);
    cout << "After converting double Variable to int: " << intVar    << "\t,Its size: " << sizeof(intVar)    << endl << endl;


    /**
     * @brief   Const Cast Example:
     * @details Demonstrates the usage of const_cast to modify a const variable through a pointer.
     */
    const int constVar = 10;
    int* ModifiedPtr = const_cast <int*> (&constVar);
    cout << "Befor modifing casted away const Variable: " << (*ModifiedPtr) << endl;
    *ModifiedPtr = 20;
    cout << "After modifing casted away const Variable: " << (*ModifiedPtr) << endl << endl;


    /**
     * @brief   Reinterpret Cast Example:
     * @details Demonstrates the usage of reinterpret_cast to reinterpret the memory layout of a variable.
     */
    int variable = 10;
    cout << "Before reinterpret: " << (variable)        << "\t\t\t,Its size: " << sizeof(variable)        << endl;
    double* reinterpretptr = reinterpret_cast <double*> (&variable);
    cout << "After reinterpret : " << (*reinterpretptr) << "\t,Its size: "     << sizeof(*reinterpretptr) << endl << endl;


    /**
     * @brief   Dynamic Cast Example:
     * @details Demonstrates the usage of dynamic_cast for downcasting from a base class pointer to a derived class pointer.
     */
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast <Derived*> (basePtr);

    if (derivedPtr)
    {
        cout << "Dynamic cast successful." << endl;
        derivedPtr -> derivedFunction();
    }
    else
    {
        cout << "Dynamic cast failed." << endl;
    }

    delete basePtr; // Clean up memory.
}