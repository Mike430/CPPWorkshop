//==========================================================
// C99 style writing
//==========================================================
#include <stdio.h>

void PrintInC99Style()
{
    puts("Puts simply drops plain text and is the fastest\n"); // Just dumps text to output

    int NumberOfApples = 5;
    printf("The number of apples in the box is: %d\n", NumberOfApples); // formats text before printing to output
}

//==========================================================
// C++ style writing
//==========================================================
#include <iostream> // This also brings through all the C99 functions

void PrintInCPPStyle()
{
    std::string text1 = "you can concatonate many different elements together into a single \"stream\" of output";
    std::cout << "cout (Character-OUTput) is an output stream" << std::endl << "Meaning...\n" << text1 << std::endl;
}

//==========================================================

namespace PrintingTextDemo
{
    void ExecuteExamples()
    {
        PrintInC99Style();
        PrintInCPPStyle();
    }
}

//==========================================================
