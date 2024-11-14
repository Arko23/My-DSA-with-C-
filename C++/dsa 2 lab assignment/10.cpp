#include <iostream>
using namespace std;
float avg(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        float var = arr[n - 1] + avg(arr, n - 1) * (n - 1);
        return (var / n);
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
    cout << "average of array is : " << avg(arr, n);
}
