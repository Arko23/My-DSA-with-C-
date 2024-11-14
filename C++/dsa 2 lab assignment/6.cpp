#include <iostream>

using namespace std;

int sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return arr[n - 1] + sum(arr, n - 1);
    }
}
int main()
{
    int n;
    cout << "size :";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = sum(arr, n);
    cout << "The sum of array is: " << s;
}
