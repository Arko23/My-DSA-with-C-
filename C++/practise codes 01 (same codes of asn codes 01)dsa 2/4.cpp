#include <iostream>
using namespace std;

int count_num(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + count_num(n / 10);
}
int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    cout << "counted number of that particular given input is : " << count_num(num);
}