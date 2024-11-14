#include <iostream>
using namespace std;
int sumseries(int n)
{
    if (n == 0)

        return 0;

    // cout << n << " ";
    return n + sumseries(n - 1);
}
int main()
{
    int num;
    cout << "nth position : ";
    cin >> num;
    cout << "sum of nth number : " << sumseries(num);
    return 0;
}
