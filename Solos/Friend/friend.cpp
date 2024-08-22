#include <iostream>

using namespace std;


/// @brief Forward declaration
class B;

class A
{
    private:
        int privateDataA;
        
        /// @brief Declare B as a "friend" class which make "its all members" accessable
        friend class B;

        /// @brief Declare a non-member function as a "friend"
        /// @param obj class object
        friend void printPrivateData(const A& obj);

    public:
        /// @brief class `A` with setting its private data A
        /// @param data 
        A(int data) : privateDataA(data) {}

        /// @brief Overloaded operator `<<` as a "friend" function
        /// @param os output streams
        /// @param obj the class object bassed to print its private data
        /// @return message "Private Data A: `privateDataA`" 
        friend ostream& operator <<(ostream& os, const A& obj) { os << "Private Data A: \t\t" << obj.privateDataA; return os; }
};

/// @brief Class B can access both the private members of class A and - cascade down - its own private members
class B
{
    private:
        int privateDataB;

    public:
        /// @brief class `B` with setting its private data B
        /// @param data
        B(int data) : privateDataB(data) {}

        /// @brief Check function if private data A of class A accessed from class B
        /// @param obj the class object
        void accessDataA(const A& obj) { cout << "Private Data A accessed from B: " << obj.privateDataA << endl; }

        /// @brief Check function if private data B of class B accessed from class B
        /// @param obj the class object
        void accessDataB(const B& obj) { cout << "Private Data B accessed from B: " << obj.privateDataB << endl; }
};

/// @brief Function to print private data from class `A` which is a non-member friend function
/// @param obj class object
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