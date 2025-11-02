#include <iostream>
using namespace std;

/*
=====================================================================
🧩 Understanding the `delete` Keyword in C++
=====================================================================

The `delete` keyword is used to **deallocate memory** that was
previously allocated using the `new` operator.

💡 Purpose:
------------
- Frees heap memory manually.
- Invokes destructor (if the object has one).
- Prevents memory leaks.

🧱 Memory Management Pair:
--------------------------
| Allocation      | Deallocation     |
|-----------------|------------------|
| new             | delete            |
| new[]           | delete[]          |

⚠️ Rule of Thumb:
-----------------
Every `new` should have one corresponding `delete`.
Every `new[]` should have one corresponding `delete[]`.

=====================================================================
*/

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
    cout << "📍 Exploring the `delete` Keyword" << endl;
    cout << "==============================\n" << endl;

    /*
    ------------------------------------------------------------
    🧠 Part 1: Deleting a single integer
    ------------------------------------------------------------
    - Allocate integer dynamically
    - Access and delete it
    */
    int* dynamicInt = new int(5);
    cout << "[dynamicInt] Value: " << *dynamicInt << endl;
    cout << "[dynamicInt] Address: " << dynamicInt << endl;

    delete dynamicInt; // ✅ Frees heap memory for single int
    dynamicInt = nullptr; // 🚫 Avoids dangling pointer (good practice)

    /*
    ------------------------------------------------------------
    🧠 Part 2: Deleting an object
    ------------------------------------------------------------
    - Calls the object's destructor automatically.
    - Frees memory after destructor execution.
    */
    Robot* robotPtr = new Robot();
    robotPtr->Speak();
    cout << "[robotPtr] Address: " << robotPtr << endl;

    delete robotPtr; // ✅ Calls ~Robot() then releases memory
    robotPtr = nullptr; // Prevents accidental reuse

    /*
    ------------------------------------------------------------
    🧠 Part 3: Deleting an array
    ------------------------------------------------------------
    - Must use `delete[]` to correctly release the whole array.
    - Using `delete` on arrays ⇒ ❌ Undefined Behavior.
    */
    int* dynamicArray = new int[3]{1, 2, 3};

    cout << "[dynamicArray] Elements: ";
    for (int i = 0; i < 3; ++i)
        cout << dynamicArray[i] << " ";
    cout << endl;

    cout << "[dynamicArray] Address (base): " << dynamicArray << endl;

    delete[] dynamicArray; // ✅ Frees entire block of array memory
    dynamicArray = nullptr;

    /*
    ------------------------------------------------------------
    🧠 Part 4: Common mistakes to avoid
    ------------------------------------------------------------
    ❌ Deleting the same pointer twice → "double free" crash.
    ❌ Deleting memory not allocated by `new` → undefined behavior.
    ❌ Forgetting `delete[]` for arrays → memory leak.
    ✅ Always set pointers to nullptr after deletion.
    */
    cout << "\n✅ All dynamically allocated memory freed successfully.\n";

    return 0;
}

/*
=====================================================================
🧩 MEMORY AND CPU BEHAVIOR
=====================================================================

🧱 MEMORY LAYOUT OVERVIEW
-------------------------
| Stack (local vars) |   →   | Heap (dynamically allocated data)  |
------------------------------------------------------------
| dynamicInt (ptr)   | ----> | [int: 5]             ← deleted
| robotPtr (ptr)     | ----> | [Robot object]       ← deleted (calls destructor)
| dynamicArray (ptr) | ----> | [int:1][int:2][int:3]← deleted with delete[]

🧠 CPU STEPS (simplified):
--------------------------
1️⃣ `delete ptr;` checks pointer validity.
2️⃣ If object → destructor runs.
3️⃣ Memory block returned to free store (heap manager).
4️⃣ Pointer remains but is now dangling (use nullptr).

=====================================================================
💡 KNOWLEDGE SUMMARY
=====================================================================
✅ `delete` frees heap memory allocated by `new`.
✅ `delete[]` frees memory allocated by `new[]`.
✅ Destructor is automatically called before freeing object memory.
✅ Setting pointer to `nullptr` after deletion avoids invalid access.
✅ Always match `new` → `delete`, `new[]` → `delete[]`.

⚙️ Real-World Best Practices:
-----------------------------
- Always use smart pointers (like `std::unique_ptr`) in modern C++.
- Avoid manual memory management when possible.
- Use memory check tools (Valgrind, ASan) to detect leaks.

=====================================================================
*/