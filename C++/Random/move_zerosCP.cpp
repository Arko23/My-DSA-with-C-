#include<iostream>
using namespace std;

void move(int arr[],int size)
{
     int nonzero=0;
     for(int j=0;j<size;j++)
     {
        if(arr[j]!=0)
        {
            swap(arr[j],arr[nonzero]);
            nonzero++;
        }
     }
}
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[6]={0,1,0,2,3,0};
    move(arr,6);
    print(arr,6);
}