#include <iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *leftarr = new int[n1];
    int *rightarr = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int i, int j)
{
    if (i < j)
    {
        int mid = (i + j) / 2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);
        merge(arr, i, mid, j);
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
    cout << "original array :";
    print(arr, n);

    mergeSort(arr, 0, n - 1);
    cout << "sorted array : ";
    print(arr, n);
    return 0;
}