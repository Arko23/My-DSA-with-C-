#include <iostream>

using namespace std;
int product(int arr[], int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return arr[n - 1] * product(arr, n - 1);
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
        cin >> arr[i];
    }
    int p = product(arr, n);
    cout << "product of array is: " << p;
}