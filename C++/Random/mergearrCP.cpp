#include <iostream>
using namespace std;
//CP question solved Success yeee:)
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
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}
void print(int arr3[], int t)
{
    for (int i = 0; i < t; i++)
    {
        if(arr3[i]==0)
        {

        }else
        {
        cout << arr3[i] << " ";
        }
    }
}

int main()
{
    int arr1[6] = {1, 2, 3, 0, 0, 0};
    int arr2[3] = {2, 5, 6};
    int arr3[9] = {0};
    merge(arr1, 6, arr2, 3, arr3);
    print(arr3, 9);
}