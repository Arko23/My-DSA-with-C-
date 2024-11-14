#include<iostream>
using namespace std;
int lcm(int a,int b,int f)
{

    if(f%a==0 && f%b==0)
    {
        return f;
    }
    else
    {



        return lcm(a,b,f+1);
    }
}
int main()
{

    int a,b;
    cout<<"first and last input = ";
    cin>>a>>b;
    if(a>b)
    {
        cout<<lcm(a,b,a);
    }
    else
    {

        cout<<lcm(a,b,b);
    }


}
