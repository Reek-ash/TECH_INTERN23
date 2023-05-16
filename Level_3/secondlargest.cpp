#include <iostream>
#include <limits>

int findSecondLargest(int arr[], int size) {
    int largest = arr[0]; // Initialize the largest element as the first element
    int secondLargest = std::numeric_limits<int>::min(); // Initialize the second-largest element as the minimum possible value
    
    // Traverse the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest; // Update the second largest with the previous largest
            largest = arr[i]; // Update the largest element
        }
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i]; // Update the second largest element
        }
    }
    
    return secondLargest;
}

int main() {
    int arr[] = {5, 8, 2, 10, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int secondLargest = findSecondLargest(arr, size);
    
    if (secondLargest != std::numeric_limits<int>::min()) {
        std::cout << "The second largest element is: " << secondLargest << std::endl;
    }
    else {
        std::cout << "There is no second largest element in the array." << std::endl;
    }
    
    return 0;
}
