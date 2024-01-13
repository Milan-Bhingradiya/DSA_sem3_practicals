#include<iostream>
using namespace std;

int binarySearch(const int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    const int size = 8;
    int array[size] = {11,22,1,3,4,9,99,44};
    int target = 99;

    int result = binarySearch(array, 0, size - 1, target);

    if (result != -1) {
        cout << "Binary Search: Target found at index " << result << std::endl;
    } else {
        cout << "Binary Search: Target not found in the array" << std::endl;
    }

    return 0;
}
