/*
    Example: Classes and Objects in C++

    This file demonstrates:
    - How to define a class (Robot)
    - How to create objects (R1, R2) from that class
    - How to access and use member variables and functions

    -------------------------------
    CLASS DEFINITION:
    -------------------------------
    class Robot {
    public:
        string Name;   // Attribute: Robot's name
        int DOF;       // Attribute: Degrees of Freedom

        void Speak();  // Method: Robot introduces itself
    };

    - The class is a blueprint. It does NOT use memory until you create objects.
    - Members (Name, DOF, Speak) are defined for all future objects of Robot.

    -------------------------------
    OBJECT CREATION:
    -------------------------------
    Robot R1, R2;

    - Here, two objects (R1 and R2) are created.
    - Each object gets its own copy of Name and DOF in memory.
    - The Speak() function is shared (code is not duplicated), but operates on the calling object's data.

    -------------------------------
    MEMORY VISION:
    -------------------------------
    +-------------------+      +-------------------+
    |   Robot R1        |      |   Robot R2        |
    +-------------------+      +-------------------+
    | Name: "NAO"       |      | Name: "YANSHEE"   |
    | DOF: 25           |      | DOF: 17           |
    +-------------------+      +-------------------+

    - Each object has its own data members.
    - When R1.Speak() is called, it uses R1's Name and DOF.
    - When R2.Speak() is called, it uses R2's Name and DOF.

    -------------------------------
    COMPILATION PROCESS (DETAILED):
    -------------------------------
    1. Preprocessing:
        - Handles #include <iostream>, expands macros, removes comments.
    2. Compilation:
        - Reads the class definition and sets up the structure for Robot in the symbol table.
        - For each member variable (Name, DOF), notes their types and memory requirements.
        - For the member function Speak(), generates code using the 'this' pointer to access the calling object's data.
        - When Robot R1, R2; is encountered, allocates memory for two Robot objects (each with their own Name and DOF).
        - Sets up calls to Speak() so that 'this' points to the correct object.
        - Generates an object file (.o) with machine code and metadata.
    3. Linking:
        - Combines your object file with the standard library (for iostream and cout).
        - Resolves all function calls (main, Speak, cout).
        - Produces the final executable.
    4. Memory Layout at Runtime:
        - Code Segment: Contains compiled code for functions (including Speak()).
        - Stack Segment: Local variables like R1 and R2 are created here, each with their own memory for Name and DOF.
        - Heap Segment: (Not used in this example, but would be used for dynamic objects.)
    5. Execution:
        - main() runs, R1 and R2 are constructed.
        - Assignments like R1.Name = "NAO"; store data in R1's memory.
        - When R1.Speak() is called, CPU jumps to Speak() code, with 'this' set to R1's address.
        - Output is printed using cout.

    -------------------------------
    OUTPUT:
    -------------------------------
    Hey, my name is NAO and my DOF is 25
    Hey, my name is YANSHEE and my DOF is 17
*/

#include <iostream>
using namespace std;

// Class definition: blueprint for Robot objects
class Robot {
    public:
        string Name;   // Attribute: Robot's name
        int DOF;       // Attribute: Degrees of Freedom

        // Method: Robot introduces itself
        void Speak() {
            cout << "Hey, my name is " << Name << " and my DOF is " << DOF << endl;
        }
};

int main() {
    // Create two Robot objects (instances)
    Robot R1, R2;

    // Assign values to R1's attributes
    R1.Name = "NAO";
    R1.DOF  = 25;

    // Assign values to R2's attributes
    R2.Name = "YANSHEE";
    R2.DOF  = 17;

    // Each object uses its own data when calling Speak()
    R1.Speak();
    R2.Speak();
    
    return 0;
}