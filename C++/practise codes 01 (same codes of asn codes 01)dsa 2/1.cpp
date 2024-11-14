#include <iostream>
using namespace std;

int Find_Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * Find_Factorial(n - 1);
    }
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "The factorial of given number is : " << Find_Factorial(x) << endl;
}