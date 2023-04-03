//==========================================================
// C++ style writing
//==========================================================
#include <iostream> // Input Output Stream and STD namespace definitions. This also brings through all the C99 functions, like printf and puts
#include <iomanip> // allows for embeds of instructions into output streams

void PrintInCPPStyle()
{
    std::cout << "NOW FOR THE C++ DEMO!"<< std::endl;

    float Number1 = 44.3267784f;
    std::string Text1 = "you can concatonate many different elements together into a single \"stream\" of output\nIncluding numbers!: ";

    std::cout << "cout (Character-OUTput) is an output stream" << std::endl << "Meaning...\n" << Text1 << 25763 << ", " << std::setprecision(5) << Number1 << std::endl;

    const int NumberOfEntries = 3;
    std::string FirstNames[NumberOfEntries] = {"Marcin", "Ryan", "Tom"};
    std::string LastName[NumberOfEntries] = {"Dudkowski", "Johnson", "Shinton"};
    unsigned int NumberOfDonuts[NumberOfEntries] = {1, 0, 17};

    std::cout << std::left << std::setw(20) << "First Name" << '|' << std::setw(20) << "Last Name" << '|' << std::setw(20) << "Number of Jam Donuts" << std::endl;
    for(int i = 0; i < NumberOfEntries; ++i)
    {
        std::cout << std::left << std::setw(20) << FirstNames[i] << '|' << std::setw(20) << LastName[i] << '|' << std::right << std::setw(20) << NumberOfDonuts[i] << std::endl;
    }

    std::cout << std::endl << std::endl;
}

//==========================================================
// C99 style writing
//==========================================================
#include <stdio.h> // short for STandarD IO

void PrintInC99Style()
{
    puts("Puts simply drops plain text and is the fastest\n"); // Just dumps text to output

    int NumberOfApples = 5;
    printf("The number of apples in the box is: %d\n", NumberOfApples); // formats text before printing to output

    const int NumberOfEntries = 3;
    std::string FirstNames[NumberOfEntries] = {"Marcin", "Ryan", "Tom"};
    std::string LastName[NumberOfEntries] = {"Dudkowski", "Johnson", "Shinton"};
    unsigned int NumberOfDonuts[NumberOfEntries] = {1, 0, 17};

    printf("%-20s|%-20s|%-20s\n","First Name","Last Name","Number of Jam Donuts");
    for(int i = 0; i < NumberOfEntries; ++i)
    {
        printf("%-20s|%-20s|%20u\n", FirstNames[i].c_str(), LastName[i].c_str(), NumberOfDonuts[i]);
    }

    printf("\n\n");
}

//==========================================================

namespace PrintingTextDemo
{
    void Execute()
    {
        PrintInC99Style();
        PrintInCPPStyle();
    }
}

//==========================================================
// SUMMARY
//==========================================================

/*
puts() is the goto for printing just plain text
printf() is the goto for formatted text
std::cout is useful when you are not certain about types
std::format exists in C++ 20 and later, though not covered here it also offers type agnostic behaviour, though formatting information is more complex
further reading for std::format found here: https://www.cppstories.com/2023/fun-print-tables-format/ 
*/