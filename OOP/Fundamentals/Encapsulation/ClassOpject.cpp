#include <iostream>
using namespace std;

class Robot {
    public:
        string Name;
        int DOF;

        void Speak() {
            cout << "Hey, my name is " << Name << " and my DOF is " << DOF << endl;
        }
};

int main() {
    Robot R1, R2;

    R1.Name = "NAO";
    R1.DOF  = 25;

    R2.Name = "YANSHEE";
    R2.DOF  = 17;

    R1.Speak();
    R2.Speak();
    
    return 0;
}