#include <iostream>
using namespace std;
// code wont run because i used & on naming the txt file//
void odd(int arr[], int left, int right, int brr[])
{
    if (left == right)
    {
        if (arr[left] % 2 != 0)
        {
            brr[left] = arr[left];
        }
        return;
    }
    int mid = left + right / 2;
    odd(arr, left, mid, brr);
    odd(arr, mid + 1, right, brr);
    return;
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int arr[n];
    int brr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cout << "Take input : ";
        cin >> arr[i];
    }
    odd(arr, 0, n - 1, brr);
    cout << "Even numbers : ";
    for (int i = 0; i < n; i++)
    {
        cout << brr[i] << " ";
    }
    return 0;
}