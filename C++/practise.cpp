#include<iostream>
using namespace std;

int main()
{
  //taking two number as input
    int x,y;
    cout<<"please enter number one and two respectively"<<endl;
    cin>>x>>y;
    //for sum
    int s;
    s=x+y;
    //printing the sum of two digit
    cout<<"The sum of both digit is : "<<s<<endl;
    
    if(s==0)
    {
        cout<<"sum is null"<<endl;
    }
    else if(s>0)
    {
        cout<<"sum is positive so adding one"<<endl;
        s++;
        cout<<s<<endl;
    }
    else
    {
        cout<<"sum is negative so substracting mineus"<<endl;
        s--;
        cout<<s<<endl;
    }
    return 0;


}