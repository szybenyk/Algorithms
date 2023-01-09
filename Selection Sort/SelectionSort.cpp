#include <algorithm>
#include <iostream>


void SelectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    for(int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        int bestIndex{ startIndex };
        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            if( comparisonFcn (array[bestIndex], array[currentIndex]) )
                bestIndex = currentIndex;
        }
        if( bestIndex != startIndex )
            std::swap(array[startIndex], array[bestIndex]);
    }
}

bool ascending(int x, int y)
{
    return (x > y);
}

bool descending(int x, int y)
{
    return (x < y);
}

bool evensFirst(int x, int y)
{
    // if x is even and y is odd, x goes first (no swap needed)
    if ( (x % 2 == 0) && !(y % 2 == 0) )
        return false;
    // if x is odd and y is even, y goes first (swap needed)
	if (!(x % 2 == 0) && (y % 2 == 0))
		return true;

    // otherwise sort in ascending order
	return ascending(x, y);
}

void printArray(const int* array, int size)
{
    for (int index{ 0 }; index < size; ++index)
        std::cout << array[index] << ' ';
    std::cout << '\n';
}


int main(int argc, char const *argv[])
{
    int array[9] {3, 7, 9, 5, 6, 1, 8, 2, 4};

    SelectionSort(array, 9, descending);
    printArray(array, 9);

    SelectionSort(array, 9, ascending);
    printArray(array, 9);

    SelectionSort(array, 9, evensFirst);
    printArray(array, 9);

    return 0;
}
