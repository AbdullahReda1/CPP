#include <iostream>  
using namespace std;

/* ===========================================================
    Base Class Definition
   =========================================================== */
class Base {
    public:
        void PrintBMessage() {
            // At runtime:
            // - CPU jumps to this function’s instructions in the text/code segment.
            // - "Hello from Base class!" is fetched from read-only data segment.
            // - std::cout writes it into output buffer (which OS flushes to terminal).
            cout << "Hello from Base class!" << endl;
        }
};

/* ===========================================================
    Derived Class (Single Inheritance)
   =========================================================== */
class Derived : public Base {  
    // "public Base" → Base’s public members remain public in Derived.
    public:
        void PrintDMessage() {
            // Same runtime process:
            // - CPU executes instructions in text segment.
            // - String literal is in read-only data segment.
            // - Output written into OS-managed buffer.
            cout << "Hello from Derived class!" << endl;
        }
};

/* ===========================================================
    Main Function (Entry Point)
   =========================================================== */
int main() {
    /*
        Memory Layout during program execution:
        ---------------------------------------
        Code (Text Segment):
            - Machine instructions for main(), Base::PrintBMessage(), Derived::PrintDMessage()
        
        Read-only Data Segment:
            - "Hello from Base class!"
            - "Hello from Derived class!"
        
        Stack:
            - Local object 'd' of type Derived
            - Return addresses when functions are called
        
        Heap:
            - Not used here (no 'new'), but std::cout manages internal heap buffers.
    */

    // Step 1: Object creation
    Derived d;  // Allocated on stack. Internally includes Base subobject.

    // Step 2: Call Derived’s function
    d.PrintDMessage();  
    /*
        CPU:
        - Push return address on stack.
        - Jump to Derived::PrintDMessage() instructions.
        - Fetch string literal from read-only segment.
        - Pass pointer to std::cout, which writes to buffer.
    */

    // Step 3: Call Base’s function (inherited into Derived)
    d.PrintBMessage();  
    /*
        CPU:
        - Push return address on stack.
        - Jump to Base::PrintBMessage() instructions.
        - Fetch "Hello from Base class!" literal from read-only segment.
        - Pass pointer to std::cout.
    */

    // Step 4: Program ends
    // - Stack memory for 'd' is released.
    // - Output buffer flushed to terminal.
    return 0;
}

/* ===========================================================
    ASCII Diagram: Memory Layout (Simplified)
    ===========================================================

    +-------------------+
    |   Code Segment    |  -> contains instructions for main(), PrintBMessage(), PrintDMessage()
    +-------------------+
    |   Read-only Data  |  -> "Hello from Base class!", "Hello from Derived class!"
    +-------------------+
    |   Heap (unused)   |  -> would hold 'new' allocations, cout buffers
    +-------------------+
    |   Stack           |
    |   [return addr]   | <- pushed when calling functions
    |   [Derived d]     | <- object 'd' (contains Base subobject)
    +-------------------+
    |   Registers (CPU) | -> hold temporary values, pointers, etc.
    +-------------------+

=========================================================== */