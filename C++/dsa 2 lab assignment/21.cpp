#include <iostream>
using namespace std;

bool bin(int arr[], int i, int j, int digit)
{
    int mid = i + (j - i) / 2;
    if (arr[mid] == digit)
        return true;
    if (i >= j)
        return false;
    else if (arr[mid] > digit)
    {
        j = mid - 1;
        return bin(arr, i, j, digit);
    }
    else
    {
        i = mid + 1;
        return bin(arr, i, j, digit);
    }
}
int main()
{
    int n;
    cout << "array size :  ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "take input : ";
        cin >> arr[i];
    }
    int digit, s, e;
    cout << "take a digit please  : ";
    cin >> digit;
    cout << "start and end of your array : ";
    cin >> s >>e;

    if (bin(arr, s, e, digit))
        cout << " Yess!!!!Found :)";
    else
        cout << "Not Found,Sorry :(";
}
