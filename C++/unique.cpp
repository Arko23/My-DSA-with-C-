#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "size: ";
    cin >> n;

    int ara[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "orignal array: " << ara[i] << endl;
    }

    for (int i = 1; i < n; i++)
    {
        int temp = ara[i];
        int j = i - 1;
        while (j >= 0 && ara[j] > temp)
        {
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=temp;
    }
    cout<<"sorted array: ";
    for(int i=0;i<n;i++)
    {
        
        cout<<" "<<ara[i]<<" ";
    }
    cout<<endl;
    //XOR
     int ans=0;
     for(int i=0;i<n;i++)
     {
        ans=ans^ara[i];
     }
     cout<<"unique = "<<ans;
    return 0;

}