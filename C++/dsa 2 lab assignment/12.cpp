#include <iostream>
using namespace std;
void rev(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[n - 1] << " ";
    rev(arr, (n - 1));
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
    cout << "reversed array : ";
    rev(arr, n);
    return 0;
}