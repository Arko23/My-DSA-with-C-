#include <iostream>
#include <algorithm>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int mid = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[i] <= mid)
        {
            i++;
        }
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "size : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Take input : ";
        cin >> arr[i];
    }
    cout << "original array : ";
    print(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "sorted array : ";
    print(arr, n);
}