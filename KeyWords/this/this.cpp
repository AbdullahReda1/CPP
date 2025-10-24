#include <iostream>
using namespace std;

/*
=====================================================================
🧩 The `this` Keyword + Static Function Behavior in C++
=====================================================================
The `this` pointer is available ONLY inside **non-static member functions**.
Static functions **belong to the class itself**, not to any object — 
so they have **no `this` pointer** because there’s no instance context.

This example demonstrates:
- How `this` works inside normal functions.
- Why `this` is unavailable in static functions.
- How both interact in memory and execution.
=====================================================================
*/

class Device {
    private:
        int id;          // Each object gets its own copy
        int configA, configB;
    
        static int instanceCount; // Shared among all objects (no `this`)
    
    public:
        /*
        ------------------------------------------------------------
        🧱 Constructor — initializes instance and updates count
        ------------------------------------------------------------
        */
        Device() {
            id = ++instanceCount;   // Count is shared, so increment once per new object
            configA = configB = 0;
            cout << "[Constructor] Device #" << id << " created." << endl;
        }
    
        /*
        ------------------------------------------------------------
        🧱 Non-static Member Function using `this`
        ------------------------------------------------------------
        Resolves naming conflicts and modifies specific object members.
        The compiler internally converts:
            setConfiguration(&obj, a, b);
        */
        void setConfiguration(int configA, int configB) {
            this->configA = configA;
            this->configB = configB;
            cout << "[Device " << this->id << "] Configuration set via `this` pointer." << endl;
        }
    
        /*
        ------------------------------------------------------------
        🧩 Method Chaining (returning *this)
        ------------------------------------------------------------
        Demonstrates how `this` can be used to return the current object
        reference for fluent interface (method chaining).
        */
        Device& updateConfigA(int value) {
            this->configA = value;
            return *this;  // Dereferenced pointer to the same object
        }
    
        Device& updateConfigB(int value) {
            this->configB = value;
            return *this;
        }
    
        void showConfiguration() {
            cout << "[Device " << id << "] ConfigA: " << configA << ", ConfigB: " << configB << endl;
        }
    
        /*
        ------------------------------------------------------------
        🧱 Static Function — belongs to the class, not the object
        ------------------------------------------------------------
        ❌ Cannot use `this` (no instance exists here)
        ✅ Can access only static members
        ------------------------------------------------------------
        */
        static void showInstanceCount() {
            cout << "[Static] Total Device instances: " << instanceCount << endl;
        
            // ❌ this->id;  // INVALID — 'this' does not exist in static context
            // ✅ Because static functions have no implicit object pointer
        }
    
        /*
        ------------------------------------------------------------
        🧱 Destructor — cleans up object when it goes out of scope
        ------------------------------------------------------------
        */
        ~Device() {
            cout << "[Destructor] Device #" << id << " destroyed." << endl;
        }
};

/*
------------------------------------------------------------
🧩 Definition of the Static Member
------------------------------------------------------------
Static data members are defined outside the class to allocate memory.
They live in a single global memory location shared by all instances.
------------------------------------------------------------
*/
int Device::instanceCount = 0;

/*
=====================================================================
🧩 MAIN FUNCTION — Execution, Memory, and CPU Flow
=====================================================================
1️⃣  `Device dev1;` allocates object memory on stack.
    → Constructor increments instanceCount and sets defaults.
2️⃣  Calls using `this` are rewritten internally by the compiler:
    dev1.setConfiguration(10, 20); → setConfiguration(&dev1, 10, 20);
3️⃣  Static function is called using class name: Device::showInstanceCount();
    → No object or `this` needed.
=====================================================================
*/

int main() {
    cout << "\n--- Creating Devices ---" << endl;
    Device dev1, dev2;

    cout << "\n--- Setting Configuration Using `this` ---" << endl;
    dev1.setConfiguration(10, 20);
    dev2.setConfiguration(30, 40);

    cout << "\n--- Method Chaining (Fluent Interface) ---" << endl;
    dev1.updateConfigA(15).updateConfigB(25).showConfiguration();

    cout << "\n--- Static Function Call (No `this`) ---" << endl;
    Device::showInstanceCount();

    cout << "\n--- End of Program (Destructors Auto-called) ---" << endl;
    return 0;
}

/*
=====================================================================
🧠 MEMORY + CPU BEHAVIOR OVERVIEW
=====================================================================
📍 Stack:
| dev1.id | 1 |
| dev1.configA | 15 |
| dev1.configB | 25 |
| dev2.id | 2 |
| dev2.configA | 30 |
| dev2.configB | 40 |

📍 Static Memory Segment:
| Device::instanceCount | 2 |

⚙️ CPU Flow (simplified):
- When calling `dev1.setConfiguration(10,20)`:
    RDI = &dev1   → 'this'
    ESI = 10
    EDX = 20
    → Function modifies values at memory pointed by RDI.

=====================================================================
📘 KNOWLEDGE SUMMARY
=====================================================================
✅ `this` is an implicit pointer passed to non-static member functions.  
✅ It points to the current object instance (on stack or heap).  
✅ Used to:
    - Resolve naming conflicts.
    - Return *this for method chaining.
    - Pass current object as parameter.
✅ Not available in:
    - Static functions.
    - Global/friend functions.
✅ Static members/functions:
    - Belong to the class, not objects.
    - Shared by all instances.
    - Accessed via class name (e.g., Device::instanceCount).
=====================================================================
*/