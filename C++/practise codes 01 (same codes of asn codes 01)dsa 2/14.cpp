#include<iostream>
using namespace std;
bool palindrome_string(string&ch,int s, int e)
{
   if(s==e)
   
    return true;
   
    if(ch[s]!=ch[e])
   
      return false;  
   
   palindrome_string(ch,s+1,e-1);
}
bool palin(string&ch)
{
    int s=0;
    int e=ch.length()-1;
    palindrome_string(ch,s,e);
}
int main()
{
    string ch;
    cout<<"enter a string = ";
    cin>>ch;
    if(palin(ch))
    {
        cout<<"it's palindrome";
    }
    else
    {
        cout<<"it's not palindrome";
    }

}