#include <bits/stdc++.h>
using namespace std;
int calc_sum(int arr[], int i, int j)
{
    if (i == j)
    {
        if (arr[i] % 2 == 0)
        {
            return arr[i];
        }
        else
            return 0;
    }
    else
    {
        int mid = (i + j) / 2;
        int left = calc_sum(arr, i, mid);
        int right = calc_sum(arr, mid + 1, j);
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
    int var = calc_sum(arr, 0, n - 1);
    cout << "sum of even numbers : " << var;
    return 0;
}