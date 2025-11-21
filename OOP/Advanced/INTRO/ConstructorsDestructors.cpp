#include <iostream>
using namespace std;

/*
=====================================================================
📘 Constructors & Destructors in C++
=====================================================================
🧩 A constructor is a special member function automatically called
when an object is created — used to initialize data members.

🧩 A destructor is a special member function automatically called
when an object goes out of scope — used to clean up resources.

These two define the *lifecycle* of an object:
Creation → Usage → Destruction

---------------------------------------------------------------------
🧱 Types of Constructors
---------------------------------------------------------------------
1️⃣ Default Constructor        → No parameters
2️⃣ Parameterized Constructor  → Accepts arguments
3️⃣ Copy Constructor           → Initializes object from another object
4️⃣ Move Constructor (C++11+)  → Moves resources from temporary objects

---------------------------------------------------------------------
🧩 Destructor Rules
---------------------------------------------------------------------
- Has same name as class prefixed with `~`
- No parameters, no return type
- Called automatically when:
    - Object goes out of scope (stack)
    - delete operator called (heap)
=====================================================================
*/

class Robot {
private:
    string name;
    int id;
    int* sensors;  // Dynamic memory to demonstrate cleanup

public:
    /*
    ------------------------------------------------------------
    1️⃣ Default Constructor
    ------------------------------------------------------------
    Automatically invoked when object created with no parameters.
    */
    Robot() {
        name = "Unnamed Robot";
        id = 0;
        sensors = new int[3]{0, 0, 0};
        cout << "[Constructor: Default] Robot created: " << name << endl;
    }

    /*
    ------------------------------------------------------------
    2️⃣ Parameterized Constructor
    ------------------------------------------------------------
    Allows object initialization with custom values.
    */
    Robot(string robotName, int robotId) {
        name = robotName;
        id = robotId;
        sensors = new int[3]{1, 2, 3};
        cout << "[Constructor: Parameterized] Robot created: " << name << endl;
    }

    /*
    ------------------------------------------------------------
    3️⃣ Copy Constructor
    ------------------------------------------------------------
    Called when a new object is initialized using an existing one.
    Performs deep copy to avoid pointer conflicts.
    */
    Robot(const Robot& other) {
        name = other.name + "_copy";
        id = other.id;
        sensors = new int[3];
        for (int i = 0; i < 3; i++) sensors[i] = other.sensors[i];
        cout << "[Constructor: Copy] Copied from " << other.name << endl;
    }

    /*
    ------------------------------------------------------------
    4️⃣ Move Constructor (C++11)
    ------------------------------------------------------------
    Transfers ownership of dynamically allocated resources
    from a temporary (rvalue) object to a new object.
    */
    Robot(Robot&& temp) noexcept {
        // As above the (this->name) is resolved to the current object's (name) so they are the same.
        // The std::move function is used to cast temp.name to an rvalue reference, allowing the name string to be moved instead of copied.
        this->name = move(temp.name);
        this->id = temp.id;
        this->sensors = temp.sensors;
        /*
            The temp.sensor pointer is set to nullptr to ensure that the temporary 
            object does not delete the memory when it is destroyed.
            This prevents a double deletion issue, which would occur if both temp 
            and this tried to delete the same memory.
        */
        temp.sensors = nullptr;  // avoid double free
        cout << "[Constructor: Move] Resources moved from temporary." << endl;
    }

    /*
    ------------------------------------------------------------
    🧱 Destructor
    ------------------------------------------------------------
    Cleans up allocated memory or external resources.
    */
    ~Robot() {
        delete[] sensors;
        cout << "[Destructor] Robot destroyed: " << name << endl;
    }

    /*
    ------------------------------------------------------------
    🔧 Utility Methods
    ------------------------------------------------------------
    */
    void showData() {
        cout << "Robot: " << name << " | ID: " << id << " | Sensors: ";
        for (int i = 0; i < 3; i++) cout << sensors[i] << " ";
        cout << endl;
    }
};

/*
=====================================================================
🧩 MAIN — CPU & MEMORY FLOW
=====================================================================
1️⃣ Stack allocates local variables (robots).
2️⃣ Each constructor sets up data in memory and heap.
3️⃣ When the scope ends:
    → Destructors called automatically (reverse order of creation).
=====================================================================
*/

int main() {
    cout << "\n--- Default Constructor ---" << endl;
    Robot r1;
    r1.showData();

    cout << "\n--- Parameterized Constructor ---" << endl;
    Robot r2("Atlas", 101);
    r2.showData();

    cout << "\n--- Copy Constructor ---" << endl;
    Robot r3 = r2;  // Calls copy constructor
    r3.showData();

    cout << "\n--- Move Constructor ---" << endl;
    Robot r4 = Robot("TempBot", 999); // Calls move constructor
    r4.showData();

    cout << "\n--- End of Main (Destructors Auto-called) ---" << endl;
    return 0;
}

/*
=====================================================================
🧠 MEMORY & CPU INSIGHT
=====================================================================
📍 Stack:
| r1 | r2 | r3 | r4 | → each object stores local metadata and a pointer to sensors.

📍 Heap (Dynamic Memory):
| sensors_r1[] | sensors_r2[] | sensors_r3[] | sensors_r4[] |

⚙️ CPU Flow:
- When object constructed, address of `this` passed implicitly.
- Memory for object allocated on stack.
- For `sensors`, heap memory allocated and pointer stored.
- When destructor runs, CPU executes delete[] on heap memory.

=====================================================================
📘 KNOWLEDGE SUMMARY
=====================================================================
✅ Default constructor → auto-generated if none defined.  
✅ Parameterized constructor → for custom initialization.  
✅ Copy constructor → defines how to clone existing objects.  
✅ Move constructor → optimizes temporary object transfers.  
✅ Destructor → ensures cleanup of heap memory & resources.  
✅ Order of Calls:
    - Constructors: Base → Derived (creation)
    - Destructors: Derived → Base (destruction)
=====================================================================
🧩 OUTPUT OF THE PROGRAM
=====================================================================
--- Default Constructor ---
[Constructor: Default] Robot created: Unnamed Robot
Robot: Unnamed Robot | ID: 0 | Sensors: 0 0 0 

--- Parameterized Constructor ---
[Constructor: Parameterized] Robot created: Atlas
Robot: Atlas | ID: 101 | Sensors: 1 2 3 

--- Copy Constructor ---
[Constructor: Copy] Copied from Atlas
Robot: Atlas_copy | ID: 101 | Sensors: 1 2 3 

--- Move Constructor ---
[Constructor: Parameterized] Robot created: TempBot
Robot: TempBot | ID: 999 | Sensors: 1 2 3 

--- End of Main (Destructors Auto-called) ---
[Destructor] Robot destroyed: TempBot
[Destructor] Robot destroyed: Atlas_copy
[Destructor] Robot destroyed: Atlas
[Destructor] Robot destroyed: Unnamed Robot
=====================================================================
*/