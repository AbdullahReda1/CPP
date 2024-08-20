#include <iostream>


/* Data name space */

namespace Data
{
    /* Global variable */

    int variable = 5;

    /* Function of Data name space */

    int function()
    {
        using std::cout;
        using std::endl;

        cout << endl;
        cout << "Hello World!";
		
		return 0;
    }

    /* Class of Data name space */

    class App
    {
        
        public:
            
            /* Function of The class of Data name space */

            int function()
            {
                int printer;
                std::cout << "\n" << "print ";
                std::cin  >> printer;
                return printer;
            }
    };

    /* Nested name space */

    namespace Region
    {
        /* Nested name space */

        namespace Supregion1
        {
            bool data = true;
        }

        /* Nested name space */

        namespace Supregion2
        {
            bool data = false;
        }
    }
    
    /* Anonymous/Unnamed name space */

    namespace
    {
        std::string word1 = "Unnamed";
    }

    /* Anonymous/Unnamed name space */

    namespace
    {
        std::string word2 = "Region";
    }

    /* Inline name space */

    inline namespace LineRegion   {  int data = rand();  }
}


int main()
{
    /*---------------------------------------------------*/

    std::cout << Data::variable;

    /*---------------------------------------------------*/

    Data::function();

    /*---------------------------------------------------*/

    Data::App app;
    std::cout << app.function() << std::endl;

    /*---------------------------------------------------*/

    std::cout << Data::Region::Supregion1::data << std::endl;
    std::cout << Data::Region::Supregion2::data << std::endl;

    /*---------------------------------------------------*/

    std::cout << Data::word1 + " " + Data::word2 << std::endl;

    /*---------------------------------------------------*/

    std::cout << Data::LineRegion::data << std::endl;
}