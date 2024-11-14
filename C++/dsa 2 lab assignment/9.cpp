#include <iostream>
using namespace std;
int min(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else
    {
        int var = min(arr + 1, n - 1);
        if (arr[0] < var)
        {
            return arr[0];
        }
        else
        {
            return var;
        }
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
    cout << "minimum number is : " << min(arr, n);
}