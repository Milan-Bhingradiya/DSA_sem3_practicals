#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (i < n - 1)
    {
      if (a[i] > a[i + 1])
      {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

void selectionSort(int a2[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;

    for (int j = i + 1; j < n; j++)
    {
      if (a2[min] > a2[j])
      {
        min = j;
      }
    }

    if (min != i)
    {

      int temp = a2[i];
      a2[i] = a2[min];
      a2[min] = temp;
    }
  }
}

void insertionsort(int a[3], int n)
{

  for (int i = 1; i < n; i++)
  {

    int temp = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > a[i])
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = temp;
  }
}

void display(int a[], int n)
{
  for (size_t i = 0; i < n; i++)
    cout << a[i] << " | ";
}

int main(int argc, char const *argv[])
{
  int a1[] = {1, 4, 2, 6, 8};
  int a2[] = {1, 100, 2, 6, 8};
  int a3[] = {1, 30, 2, 6, 8};
  int n = sizeof(a1) / sizeof(a1[0]);

  cout << "Unsorted array :   ";
  display(a1, n);
  cout << endl;
  bubble_sort(a1, n);
  cout << "sorted array using Bubble sort :";
  display(a1, n);
  cout << endl;

  cout << "Unsorted array :   ";
  display(a2, n);
  cout << endl;
  selectionSort(a2, n);
  cout << "sorted array using Selection sort :";
  display(a2, n);
  cout << endl;

  cout << "Unsorted array :   ";
  display(a3, n);
  cout << endl;
  insertionsort(a3, n);
  cout << "sorted array using Insertion sort :";
  display(a3, n);

  return 0;
}
