#include <iostream>
using namespace std;

int count(int arr[], int n, int cunt, int indx)
{
    if (indx == n)
    {
        return cunt;
    }
    if (arr[indx] % 2 == 0)
    {
        cout << "even " << arr[indx] << endl;
        return count(arr, n, cunt + 1, indx + 1);
    }
    else
    {
       return count(arr, n, cunt, indx + 1);
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
    cout << "count : " << count(arr, n, 0, 0);
}