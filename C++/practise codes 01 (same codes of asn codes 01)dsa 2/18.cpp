#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}
int main()
{
    int a, b;
    cout << "take first and last input = ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " are " << gcd(a, b);
}