#include <iostream>
using namespace std;

/* ===========================================================
   *Base Class with Different Access Specifiers
   =========================================================== */
class Base {
    private:
        void AccessPrivate() {
            cout << "Private Base Data" << endl;
        }

    protected:
        void AccessProtected() {
            cout << "Protected Base Data" << endl;
        }

    public:
        void AccessPublic() {
            cout << "Public Base Data" << endl;
        }

        // Helper functions to show indirect access
        void TestPrivate() {
            AccessPrivate();   // allowed (private accessible inside Base itself)
        }

        void TestProtected() {
            AccessProtected(); // allowed (protected accessible inside Base)
        }
};

/* ===========================================================
   *Public Inheritance
   =========================================================== */
class Derived1 : public Base {
    public:
        void ShowAccess() {
            // Accessing from Derived1
            // AccessPrivate();    ❌ not accessible

            AccessProtected();     // ✅ accessible (protected -> protected)
            AccessPublic();        // ✅ accessible (public -> public)
        }
};

/* ===========================================================
   *Protected Inheritance
   =========================================================== */
class Derived2 : protected Base {
    public:
        void ShowAccess() {
            // AccessPrivate();    ❌ not accessible

            AccessProtected();     // ✅ accessible (protected -> protected)
            AccessPublic();        // ✅ accessible (public -> protected)
        }
};

/* ===========================================================
   *Private Inheritance
   =========================================================== */
class Derived3 : private Base {
    public:
        void ShowAccess() {
            // AccessPrivate();    ❌ not accessible

            AccessProtected();     // ✅ accessible (protected -> private here)
            AccessPublic();        // ✅ accessible (public -> private here)
        }
};

/* ===========================================================
   *Main Function
   =========================================================== */
int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    cout << "\n--- Public Inheritance ---\n";

    d1.AccessPublic();     // ✅ still public
    d1.ShowAccess();       // ✅ shows internal access

    // d1.AccessProtected();  ❌ cannot call from outside
    // d1.AccessPrivate();    ❌ not visible

    cout << "\n--- Protected Inheritance ---\n";

    // d2.AccessPublic();     ❌ now protected, not callable directly

    d2.ShowAccess();         // ✅ accessible through member function

    cout << "\n--- Private Inheritance ---\n";

    // d3.AccessPublic();     ❌ now private, not callable directly

    d3.ShowAccess();         // ✅ accessible through member function

    cout << "\n--- Base Class Direct Access ---\n";

    Base b;
    b.AccessPublic();        // ✅ public
    b.TestProtected();       // ✅ indirect access to protected using helper function
    b.TestPrivate();         // ✅ indirect access to private using helper function

    // b.AccessProtected();   ❌ protected
    // b.AccessPrivate();     ❌ private

    return 0;
}

/*  ===========================================================
    Summary Table (Access Specifier Transformation)
    ===========================================================
    Base Member    | Public Inheritance | Protected Inheritance | Private Inheritance
    --------------------------------------------------------------------------------
    public         | public             | protected             | private
    protected      | protected          | protected             | private
    private        | not inherited      | not inherited         | not inherited
    =========================================================== */