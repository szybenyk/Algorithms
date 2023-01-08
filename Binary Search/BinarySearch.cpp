#include <array>
#include <iostream>


int binarySearch(const int* array, int target, int min, int max)
{
    do{
        int center{ (min + max) / 2 };
        if ( array[center] == target )
            return center;
        else if (array[center] > target)
            max = center - 1;
        else
            min = center + 1;
    } while ( min <= max );

    return -1;
}


int main(int argc, char const *argv[])
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26 ,32, 36, 37, 42, 44, 48 };

    constexpr int numTestValue{ 10 };
    constexpr int testValues[numTestValue]{ 0, 3, 12, 13, 22, 26, 43, 44, 49, 48 };
    constexpr int expectedValues[numTestValue]{ -1, 0, 3, -1, -1, 8, -1, 13, -1, 14 };

    for ( int count{ 0 }; count < numTestValue; ++count )
    {
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else
            std::cout << "test value " << testValues[count] << " failed. There's something wrong with your code!\n";
    }

    return 0;
}
