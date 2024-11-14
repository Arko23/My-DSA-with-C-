#include <bits/stdc++.h>
using namespace std;
int power(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        int p = power(n, m / 2);
        if (m % 2)
        {
            return p * p * n;
        }
        else
        {
            return p * p;
        }
    }
}
int main()
{
    int n, m;
    cout << "Base value : ";
    cin >> n;
    cout << "Power value : ";
    cin >> m;
    cout << "The value is : " << power(n, m) << endl;
}