#include <iostream>
using namespace std;
// find even numbers in an array using divide and conquer method//
void fun(int arr[], int i, int j, int brr[])
{
    if (i == j)
    {
        if (arr[i] % 2 == 0)
        {
            brr[i] = arr[i];
        }
        return;
    }
    int mid = (i + j) / 2;
    fun(arr, i, mid, brr);
    fun(arr, mid + 1, j, brr);
    return;
}
int main()
{
    int num;
    cout << "size : ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Take input : ";
        cin >> arr[i];
    }
    int brr[num] = {0};
    fun(arr, 0, num - 1, brr);
    for (int i = 0; i < num; i++)
    {
        cout <<  brr[i]<<" ";
    }
    return 0;
}