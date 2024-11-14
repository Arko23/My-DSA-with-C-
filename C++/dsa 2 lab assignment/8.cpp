#include<iostream>
using namespace std;
int max(int arr[],int n)
{
    if(n==1)
    {
        return arr[0];
    }
    else
    {
        int m=max(arr+1,n-1);
        if(arr[0]>m)
        {
            return arr[0];
        }
        else
        {
            return m;
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
    cout<<"maximum number is : "<<max(arr,n);
}