#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int j;
        for(j=1;j=n-i;j++)
        {
            cout<<" ";
        }
        int k=i;
        for(;j<=n;j++)
        {
            cout<<k--<<endl;
        }
        for(;j<=n+i-1;j++)
        {
            cout<<k++<<endl;
        }
        cout<<endl;
    }
    return 0;
}