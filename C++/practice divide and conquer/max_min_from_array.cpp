#include <bits/stdc++.h>
using namespace std;
struct s
{
    int maxiii;
    int miniii;
};
s fun(int arr[], int i, int j)
{
    if (i == j)
    {
        return {arr[i], arr[i]};
    }
    int mid = (i + j) / 2;
    s ma = fun(arr, i, mid);
    s mi = fun(arr, mid + 1, j);
    return {max(ma.maxiii, mi.maxiii), min(ma.miniii, mi.miniii)};
}

int main()
{
    int n;
    cout << "Array size : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Take input : ";
        cin >> arr[i];
    }
    s r = fun(arr, 0, n - 1);
    cout << "Max : " << r.maxiii << " "
         << "MIN : " << r.miniii << endl;
}
