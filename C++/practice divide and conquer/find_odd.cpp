#include <bits/stdc++.h>
using namespace std;
void findodd(int arr[], int low, int high, int brr[])
{
    if (low == high)
    {
        if (arr[low] % 2 != 0)
        {
            brr[low] = arr[low];
        }
        return;
    }
    else
    {
        int mid = (low + high) / 2;
        findodd(arr, low, mid, brr);
        findodd(arr, mid + 1, high, brr);
        return;
    }
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
    int brr[100] = {0};
    findodd(arr, 0, n - 1, brr);
    cout << "odd numbers are : ";
    for (int i = 0; i < n; i++)
    {
        cout << brr[i] << " ";
    }
}