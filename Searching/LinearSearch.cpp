#include <iostream>
using namespace std;

int linearSearch(const int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int size = 8;
    int array[size] = {4, 2, 8, 1, 7, 5, 3, 6};
    int target = 5;

    int result = linearSearch(array, size, target);

    if (result != -1)
    {
        cout << "Linear Search: Target found at index " << result << endl;
    }
    else
    {
        cout << "Linear Search: Target not found in the array" << endl;
    }

    return 0;
}
