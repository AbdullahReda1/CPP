#include <iostream>
using namespace std;

/*
=====================================================================
🧩 Understanding the `new` Keyword in C++
=====================================================================
The `new` operator dynamically allocates memory on the **heap** 
during runtime and returns a pointer to that memory.

Key Concepts:
--------------
- Memory from `new` persists until explicitly released by `delete`.
- Variables created by `new` live **beyond the scope** of where they are created.
- When `delete` is not used → **memory leak** occurs.
=====================================================================
*/

// A simple class to visualize constructor/destructor behavior
class Robot {
public:
    Robot() {
        cout << "[Constructor] Robot constructed 🤖" << endl;
    }

    ~Robot() {
        cout << "[Destructor] Robot destroyed 💀" << endl;
    }

    void Speak() {
        cout << "Beep boop! I am alive in heap memory." << endl;
    }
};

int main() {
    cout << "\n==============================" << endl;
    cout << "📍 Exploring the `new` Keyword" << endl;
    cout << "==============================\n" << endl;

    /*
    ------------------------------------------------------------
    🧠 Part 1: Allocating a single integer dynamically
    ------------------------------------------------------------
    `new int(5)` allocates 4 bytes (for int) on the heap 
    and initializes it with the value 5.
    Returns → pointer to that memory.
    */
    int* dynamicInt = new int(5);

    cout << "[dynamicInt] Value: " << *dynamicInt << endl;
    cout << "[dynamicInt] Address: " << dynamicInt << endl;

    /*
    ------------------------------------------------------------
    🧠 Part 2: Allocating an object dynamically
    ------------------------------------------------------------
    `new Robot()`:
        1️⃣ Allocates heap memory for the Robot object.
        2️⃣ Calls its constructor immediately.
        3️⃣ Returns pointer to the object.
    */
    Robot* robotPtr = new Robot();
    robotPtr->Speak();
    cout << "[robotPtr] Address: " << robotPtr << endl;

    /*
    ------------------------------------------------------------
    🧠 Part 3: Allocating an array dynamically
    ------------------------------------------------------------
    `new int[3]{1, 2, 3}`:
    - Allocates contiguous memory for 3 integers.
    - Initializes them with 1, 2, 3.
    */
    int* dynamicArray = new int[3]{1, 2, 3};

    cout << "[dynamicArray] Elements: ";
    for (int i = 0; i < 3; ++i)
        cout << dynamicArray[i] << " ";
    cout << endl;

    cout << "[dynamicArray] Address (base): " << dynamicArray << endl;

    /*
    ⚠️ Notice:
    ------------------------------------------------------------
    - No `delete` used → memory remains allocated until program ends.
    - Destructors of dynamically allocated objects (like Robot) 
      are **NOT automatically called**.
    - The OS will reclaim this memory only after the program terminates.
    ------------------------------------------------------------
    */

    cout << "\n--- End of program (memory not freed yet) ---" << endl;
    return 0;
}

/*
=====================================================================
🧩 MEMORY AND CPU BEHAVIOR
=====================================================================

🧱 MEMORY LAYOUT (Simplified):
------------------------------
| Stack                      | Heap
|-----------------------------|--------------------------
| dynamicInt (ptr) ---------->| [int: 5]
| robotPtr (ptr) ------------>| [Robot object]
| dynamicArray (ptr) -------->| [int: 1][int: 2][int: 3]

🧠 CPU Steps:
-------------
1️⃣ Allocate heap memory block via `operator new`
2️⃣ Constructor runs (if object)
3️⃣ Pointer stored on stack
4️⃣ Dereference with `*` or `->` to access data
5️⃣ When function ends → pointers destroyed but memory remains

⚠️ Destructor never called unless `delete` is used manually.
=====================================================================

💡 KNOWLEDGE SUMMARY
=====================================================================
✅ `new` dynamically allocates memory on heap
✅ Memory stays allocated until `delete` is used
✅ Constructor is called for classes, but destructor is not
✅ Dereference with `*` (for values) or `->` (for objects)
✅ If you forget to free heap memory → memory leak!

Next Step:
-----------
Learn about `delete` and `delete[]` to properly free memory:
- `delete ptr;`        → frees single object
- `delete[] ptr;`      → frees array
=====================================================================
*/