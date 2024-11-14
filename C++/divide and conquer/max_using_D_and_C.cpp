#include <iostream>
using namespace std;
// Function to find the maximum element in an array using divide and conquer
int findMax(int arr[], int low, int high) {
    // Base case: only one element in the array
    if (low == high) {
        return arr[low];
    }
    
    // Divide the array into two halves
    int mid = (low + high) / 2;
    
    // Recursively find the maximum element in each half
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    
    // Compare and return the maximum of the two sub-arrays
    if (leftMax > rightMax) {
        return leftMax;
    } else {
        return rightMax;
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // Call the recursive function to find the maximum element
    int maxElement = findMax(arr, 0, n - 1);
    
    cout << "The maximum element in the array is: " << maxElement << endl;
    
    return 0;
}
