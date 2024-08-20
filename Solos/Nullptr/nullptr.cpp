#include <iostream>

using namespace std;


/// @brief Function that takes an int pointer
/// @param pointer is pointer to int
void processPointer(int* pointer)
{
    /* Check if the pointer is null or not */
    if   (pointer == nullptr) { cout << "Passed null pointer. " << endl; }
	else 					  { cout << "passed valid pointer." << endl; }
}

/// @brief Function to create and return a null pointer
/// @return nullptr
int* createNullPointer() { return nullptr; }


int main()
{
    /* Testing a null pointer, then check if the test pointer is nullptr */
    int* testPointer = nullptr;
    cout << "Test Pointer  :\t";

    testPointer == nullptr ? cout << "Pointer is nullptr." << endl : cout << "Pointer is not nullptr." << endl;


    /* Passing a null pointer to a function */
    int* nullPtr = nullptr;
    cout << "Test Pointer  :\t";

    processPointer(nullPtr);
    cout << "Test Pointer  :\t";


    /* Returning a null pointer from a function */
    int* returnedPointer = createNullPointer();
	
    if   (returnedPointer == nullptr) { cout << "Received null pointer. " << endl; }
	else 							  { cout << "Received valid pointer." << endl; }
}