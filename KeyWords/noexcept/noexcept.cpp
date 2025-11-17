#include <iostream>
using namespace std;


// 2. Move Constructors //// and Move Assignment Operators
class Buffer {
    private:
        int* Data; // Pointer to dynamically allocated array
        size_t Size; // Size of the array
    
    public:
        // Constructor: Allocates memory for the array
        Buffer(size_t n) : Data(new int[n]), Size(n) {
            cout << "Buffer of size " << n << " created." << endl;
        };

        // Move Constructor: Transfers ownership of resources from another Buffer object
        Buffer(Buffer && Other) noexcept : Data(Other.Data), Size(Other.Size) {
            cout << "Buffer moved." << endl;
            Other.Data = nullptr; // Nullify the source pointer to avoid double deletion
            Other.Size = 0; // Reset the size of the source object
        }

        // Destructor: Releases allocated memory
        ~Buffer() noexcept {
            cout << "Buffer of size " << Size << " destroyed." << endl;
            delete[] Data;
        }
};


int main() {
    // Demonstrating the use of the Buffer class
    cout << "Creating buf1..." << endl;
    Buffer buf1(10); // Create a Buffer object with 10 elements

    cout << "Moving buf1 to buf2..." << endl;
    Buffer buf2(std::move(buf1)); // Move buf1 into buf2

    cout << "Exiting main..." << endl;

    return 0;
}

/*
🧩 5. When You Should Use noexcept
    ✅ Use noexcept for:
        Destructors (~Class() noexcept)
        Move constructors & assignment operators
        Utility/helper functions that can’t logically throw
        Performance-critical or real-time code
        Logging / cleanup / deallocation functions
        Embedded and robotics systems
    ❌ Don’t use noexcept for:
        Code that might reasonably fail and report errors
        Functions that depend on user input, files, or networks
        Experimental or high-risk sections of code
*/
/*
Application of noexcept:
    1. Destructors — Always Non-throwing
    2. Move Constructors and Move Assignment Operators
    3. Utility and Helper Functions
    4. Low-Level System and Embedded Code
    5. Move Semantics in STL Containers
    6. Type Traits and Compile-Time Checks
    7. Custom Memory Allocators
    8. Threading and Concurrency Utilities
    9. Exception Boundary Functions
    10. Game Engines, Robotics, and Real-Time Systems
*/