#include <iostream>

using namespace std;


/// @brief  Function to the return of auto keyword
/// @return void pointer
auto pvfunction()  { void *ptr; return ptr;  }


int main()
{
    /* Declare and initialize a several auto variables */

    auto autoBuffer0 = 'a';
    auto autoBuffer1 = 2147483647;
    auto autoBuffer2 = 2147483648;
    auto autoBuffer3 = true;
    auto autoBuffer4 = 100U;
    auto autoBuffer5 = 3.0;
    auto autoBuffer6 = 3.0f;
    auto autoBuffer7 = pvfunction();
    inline void autoBuffer8(void);


    /* Print the size and type of each auto variable */

    cout << "auto Buffer 0 size:  " << sizeof(autoBuffer0) << ",  Its Type: " << typeid(autoBuffer0).name() << endl;
    cout << "auto Buffer 1 size:  " << sizeof(autoBuffer1) << ",  Its Type: " << typeid(autoBuffer1).name() << endl;
    cout << "auto Buffer 2 size:  " << sizeof(autoBuffer2) << ",  Its Type: " << typeid(autoBuffer2).name() << endl;
    cout << "auto Buffer 3 size:  " << sizeof(autoBuffer3) << ",  Its Type: " << typeid(autoBuffer3).name() << endl;
    cout << "auto Buffer 4 size:  " << sizeof(autoBuffer4) << ",  Its Type: " << typeid(autoBuffer4).name() << endl;
    cout << "auto Buffer 5 size:  " << sizeof(autoBuffer5) << ",  Its Type: " << typeid(autoBuffer5).name() << endl;
    cout << "auto Buffer 6 size:  " << sizeof(autoBuffer6) << ",  Its Type: " << typeid(autoBuffer6).name() << endl;
    cout << "auto Buffer 7 size:  " << sizeof(autoBuffer7) << ",  Its Type: " << typeid(autoBuffer7).name() << endl;
    cout << "auto Buffer 8 size:  1"                       << ",  Its Type: " << typeid(autoBuffer8).name() << endl;
    cout                                                                                                    << endl;

    return 0;
}