//==========================================================
// There is no C++ replacement, just use this
//==========================================================

#include <stdint.h>

//==========================================================

#include <iostream> // so we can print with COUT
#include <iomanip> // so we can have text alignment
#include <typeinfo> // so we can decypher <TYPENAME T>
#include <limits> // for retrieving the numberic limits

//==========================================================

#define COLUMN_WIDTH 25
    
//==========================================================

template<typename t>
void PrintIntInfo()
{
    std::cout << std::left << std::setw(COLUMN_WIDTH) << typeid(t).name() << "MinValue = " << std::setw(COLUMN_WIDTH) << (int64_t)std::numeric_limits<t>::min() << "MaxValue = " << (int64_t)std::numeric_limits<t>::max() << std::endl;
}

template<typename t>
void PrintIntInfoUnsigned()
{
    std::cout << std::left << std::setw(COLUMN_WIDTH) << typeid(t).name() << "MinValue = " << std::setw(COLUMN_WIDTH) << (uint64_t)std::numeric_limits<t>::min() << "MaxValue = " << (uint64_t)std::numeric_limits<t>::max() << std::endl;
}

//==========================================================

#define PRINT_INT_INFO(Type)\
std::cout << std::left << std::setw(COLUMN_WIDTH) << #Type << "MinValue = " << std::setw(COLUMN_WIDTH) << (int64_t)std::numeric_limits<Type>::min() << "MaxValue = " << (int64_t)std::numeric_limits<Type>::max() << std::endl;

#define PRINT_INT_INFO_UNSIGNED(Type)\
std::cout << std::left << std::setw(COLUMN_WIDTH) << #Type << "MinValue = " << std::setw(COLUMN_WIDTH) << (uint64_t)std::numeric_limits<Type>::min() << "MaxValue = " << (uint64_t)std::numeric_limits<Type>::max() << std::endl;

//==========================================================

void PrintMikesDirtySecret()
{
    #ifdef ENABLE_MIKES_DIRTY_SECRET
    printf("\n\nCheese on toast is to be made in the Microwave.\n\n");
    #else
    printf("\n\n");
    #endif // ENABLE_MIKES_DIRTY_SECRET
}

//==========================================================

namespace NumbersDemo
{
    void Execute()
    {
        int8_t min8 = INT8_MIN;
        int8_t max8 = INT8_MAX;
        uint8_t umin8 = 0; // MIN unsigned is not defined in stdint.h
        uint8_t umax8 = UINT8_MAX;
        int16_t min16 = INT16_MIN;
        // ETC ETC ETC...

        PrintIntInfo<int8_t>();
        PrintIntInfo<int16_t>();
        PrintIntInfo<int32_t>();
        PrintIntInfo<int64_t>();
        PrintIntInfo<uint8_t>();
        PrintIntInfo<uint16_t>();
        PrintIntInfo<uint32_t>();
        PrintIntInfo<uint64_t>();
        printf("\n\n");
        PRINT_INT_INFO(int8_t);
        PRINT_INT_INFO(int16_t);
        PRINT_INT_INFO(int32_t);
        PRINT_INT_INFO(int64_t);
        PRINT_INT_INFO(int8_t);
        PRINT_INT_INFO(int16_t);
        PRINT_INT_INFO(int32_t);
        PRINT_INT_INFO(int64_t);

        PrintMikesDirtySecret();
    }
}

//==========================================================
// SUMMARY
//==========================================================

/*
Try to avoid using char, short, int, long and long long
Instead use stdint.h to have platform agnostic integers that closely resemble Unreal's integer format

Preprocessors are pre-compile-time text substitution which can cut and paste code, unfortunately this code is unmappable by a debugger
Templates are compile-time code generates which offer less in capabilities but are more stable and debuggable
Preprocessors can define anything the programmer can, even the number 5
Templates can only define object layous & instances of objects and layouts & instances of functions
Preprocessors are fast as they are just dumb copy and paste
Templates are slow as they run significantly more validation

If you want something that doesn't belong in just one place or needs to be tailored to a location then use a preprocessor.
Useful examples of a good preprocessor:
1. constant numbers: #define INDEX_NONE -1
2. bitshifted enums: #define #define BIT_SHIFT( x ) ( 1 << ( x ) )
3. Compiler Flags:
*/





#define MOODY_BASIC_MACRO 5 //Isolated enties are fine
#define MOODY_BASIC_MACRO (5 + 17 * 36) // anything more complex that can be externally tampered with should be wraped
#define SQUARE(x) (x * x)
#define SQUARE(8) (8 * 8)
#define SQUARE(4 + 4) (4 + 4 * 4 + 4)
#define SQUARE((4 + 4)) ((4 + 4) * (4 + 4)) // inelegant
#define SQUARE(x) ((x) * (x))
#define SQUARE(4 + 4) ((4 + 4) * (4 + 4))

// TYPE SAFETY WITH MACROS DOES NOT EXIST
// * can either mean multiply or dereference. This may compile but not do what you want. And again, this is NOT debuggable

#define UObject FStruct
#define if while
// https://gist.github.com/aras-p/6224951
// Macros are ron burgundy

// Compile time flags
// Define functions comparing against Inline (inline is a copy and paste at compile time and is only a hint (unless you use the force inline keyword))
// Defining global data (objects and functions)
// Include manipulation (STB style includes)

#define FUCKS_GIVEN 0
const int FucksGivenGlobalConst = 0;
enum { FucksGivenAnnonEnum = 0 };

int main()
{
    printf("%d", FUCKS_GIVEN); // in asm we just have 0 put into printf
    printf("%d", FucksGivenGlobalConst); // in asm we get a reference out to a place in memory somewhere
    printf("%d", FucksGivenAnnonEnum); // in asm we get a reference to a register with no allocations, we keep type safety and because it's in register space we experience no perf hit in fetching it
}
