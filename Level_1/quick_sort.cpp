#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array.......................
int partition_(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function.........................
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition_(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the array..............
void print_Array(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}



int main() {
    vector<int> arr = {9, 4, 2, 7, 1, 5, 8, 3, 6};
    int n = arr.size();

    cout << "Original array: ";
    print_Array(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    print_Array(arr);

    return 0;
}
