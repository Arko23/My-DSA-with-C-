#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int i, int j)
{
    if (i == j)
    {
        return arr[i];
    }
    else
    {
        int mid = (i + j) / 2;
        int left = sum(arr, i, mid);
        int right = sum(arr, mid + 1, j);
        return (left + right);
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
    cout << "sum 0f array : " << sum(arr, 0, n - 1) << endl;
    return 0;
}