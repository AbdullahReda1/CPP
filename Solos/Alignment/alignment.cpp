#include <iostream>
using namespace std;

int main()
{
    /* Define an array of characters with alignment of 2 */
    alignas(2) char charBuffer[2];

    /* Define an unsigned integer with alignment of 1 */
    alignas(1) unsigned int intBuffer = 4294967295;

    /* Define a structure with custom alignment of 16 */
    struct alignas(16) AlignedStructure
	{
        int Variable1;             /* 4 bytes */
        int Variable2;             /* 4 bytes */
        short ShortVariable;       /* 2 bytes */

        /* char aligned to 4 bytes in memory. */
        alignas(4) char Array[5];
    };
    
    /* Print alignment of charBuffer */
    cout << "Alignment of char Buffer:       " << alignof(charBuffer) << endl;

    /* Print alignment of intBuffer */
    cout << "Alignment of int  Buffer:       " << alignof(intBuffer) << endl;

    /* Print value of intBuffer */
    cout << "Value of int Buffer     :       " << intBuffer << endl;

    /* Print alignment of AlignedStructure */
    cout << "Alignment of Aligned Structure: " << alignof(AlignedStructure) << endl;
    
    return 0;
}