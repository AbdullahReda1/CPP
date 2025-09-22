#include <iostream>
using namespace std;


class HighLevel {
    public:
        void HLmsg() {
            cout << "High level message" << endl;
        }
};

class LeftMediumLevel : public HighLevel {
    public:
        void LMLmsg() {
            cout << "Left Medium level message" << endl;
        }
};

class RightMediumLevel : public HighLevel {
    public:
        void RMLmsg() {
            cout << "Right Medium level message" << endl;
        }
};