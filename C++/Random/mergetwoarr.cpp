#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}
//if the arr1[5]={1,3,5,7,9}
//and if arr2[4]={24,12,3,5}
void insertation(int arr3[], int t)
{
    for (int i = 1; i < t; i++)
    {
        int temp = arr3[i];
        int j = i - 1;
        while (j >= 0 && arr3[j] > temp)
        {
            arr3[j + 1] = arr3[j];
            j--;
        }
        arr3[j + 1] = temp;
    }
}
void print(int arr3[], int t)
{
    cout << "array :";
    for (int i = 0; i < t; i++)
    {
        cout << arr3[i] << " ";
    }
}

int main()
{
    int n;
    cout << "size of array 1: ";
    cin >> n;
    int arr1[n];//arr1[]={1,3,5,7,9}
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cout << "size of array 2: ";
    cin >> m;
    int arr2[m];//arr2[]={2,4,6}
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int t = n + m;
    int arr3[t];

    merge(arr1, n, arr2, m, arr3);
    insertation(arr3, t);
    print(arr3, t);
}