//==========================================================
// There is no C++ replacement, just use this
//==========================================================

#include <stdint.h>

//==========================================================

#include <iostream> // so we can print with COUT
#include <iomanip> // so we can have text alignment
#include <typeinfo> // so we can decypher <TYPENAME T>

//==========================================================

const uint8_t gWidth = 25;
    
//==========================================================

template<typename t>
void PrintSignedIntInfo(t MinValue, t MaxValue)
{
    std::cout << std::left << std::setw(gWidth) << typeid(t).name() << "MinValue = " << std::setw(gWidth) << (int64_t)MinValue << "MaxValue = " << (int64_t)MaxValue << std::endl;
}

//==========================================================

template<typename t>
void PrintUnsignedIntInfo(t MinValue, t MaxValue)
{
    std::cout << std::left << std::setw(gWidth) << typeid(t).name() << "MinValue = " << std::setw(gWidth) << (uint64_t)MinValue << "MaxValue = " << (uint64_t)MaxValue << std::endl;
}

//==========================================================

#define PRINT_SIGNED_INT_INFO(Type, MinValue, MaxValue) std::cout << std::left << std::setw(gWidth) << #Type << "MinValue = " << std::setw(gWidth) << (int64_t)MinValue << "MaxValue = " << (int64_t)MaxValue << std::endl;
#define PRINT_UNSIGNED_INT_INFO(Type, MinValue, MaxValue) std::cout << std::left << std::setw(gWidth) << #Type << "MinValue = " << std::setw(gWidth) << (uint64_t)MinValue << "MaxValue = " << (uint64_t)MaxValue << std::endl;

//==========================================================

namespace NumbersDemo
{
    void ExecuteExamples()
    {
        PrintSignedIntInfo<int8_t>(INT8_MIN, INT8_MAX);
        PrintSignedIntInfo<int16_t>(INT16_MIN, INT16_MAX);
        PrintSignedIntInfo<int32_t>(INT32_MIN, INT32_MAX);
        PrintSignedIntInfo<int64_t>(INT64_MIN, INT64_MAX);
        printf("\n\n");
        PrintUnsignedIntInfo<uint8_t>(0, UINT8_MAX);
        PrintUnsignedIntInfo<uint16_t>(0, UINT16_MAX);
        PrintUnsignedIntInfo<uint32_t>(0, UINT32_MAX);
        PrintUnsignedIntInfo<uint64_t>(0, UINT64_MAX);
        printf("\n\n\n\n");
        PRINT_SIGNED_INT_INFO(int8_t, INT8_MIN, INT8_MAX);
        PRINT_SIGNED_INT_INFO(int16_t, INT16_MIN, INT16_MAX);
        PRINT_SIGNED_INT_INFO(int32_t, INT32_MIN, INT32_MAX);
        PRINT_SIGNED_INT_INFO(int64_t, INT64_MIN, INT64_MAX);
        printf("\n\n");
        PRINT_SIGNED_INT_INFO(int8_t, 0, UINT8_MAX);
        PRINT_SIGNED_INT_INFO(int16_t, 0, UINT16_MAX);
        PRINT_SIGNED_INT_INFO(int32_t, 0, UINT32_MAX);
        PRINT_SIGNED_INT_INFO(int64_t, 0, UINT64_MAX);
    }
}

//==========================================================