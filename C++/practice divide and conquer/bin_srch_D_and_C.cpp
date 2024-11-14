#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int BIN_SRH(int arr[], int s, int e, int key)
{
    // sort(arr, arr + n);
    if (e >= s)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return arr[mid];
        if (arr[mid] > key)
            return BIN_SRH(arr, s, mid - 1, key);
        else
            return BIN_SRH(arr, mid + 1, e, key);
    }
    return -1;
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
    int key;
    cout << "key is : ";
    cin >> key;
    sort(arr, arr + n);
    int var = BIN_SRH(arr, 0, n - 1, key);
    if (var == -1)
    {
        cout << "element is not in the array ";
    }
    else
    {
        cout << "element found " << var;
    }
}