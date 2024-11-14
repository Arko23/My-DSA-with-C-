#include <iostream>
using namespace std;
// without implementing function

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // bubble sort ascending order
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"sorted in ascending order : ";

    for (int i = 0; i < n; i++)
    {
        cout <<arr[i] <<" ";
    }
    cout << endl;
    return 0;
}