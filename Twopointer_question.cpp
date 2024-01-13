#include <iostream>
using namespace std;

void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << "|";
    }
    cout << endl;
}

void sort_using_2pointer(int a[], int size)
{

    int left = 0, right = size - 1;

    while (left < right)
    {

        if (a[left] == 0)
        {
            left++;
        }

        if (a[right] == 1)
        {
            right--;
        }

        swap(a[left], a[right]);
        left++;
        right--;
    }
}

void sort_using_3pointer(int a[], int size)
{

    int left = 0;
    int middle = 0;
    int right = size - 1;

    while (left < right)

    {
        printarray(a, size);

        if (a[left] > a[right])
        {

          
        }
    }}

    int main()
    {

        int array[13] = {1, 1, 2, 0, 0, 0, 2, 2, 0, 1, 0, 2, 2};
        printarray(array, 13);
        // sort_using_2pointer(array,8);
        // printarray(array, 8);
        cout << "starting";
        sort_using_3pointer(array, 13);
        // printarray(array, 13);
    }