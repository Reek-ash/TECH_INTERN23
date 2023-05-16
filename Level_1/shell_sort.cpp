#include <iostream>
#include <vector>

using namespace std;

// Shell Sort function
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a big gap and reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for elements at each gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 4, 2, 7, 1, 5, 8, 3, 6,8,46};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    shellSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
