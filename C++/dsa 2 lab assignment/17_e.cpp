#include <iostream>
#include <math.h>

using namespace std;
int series(int n, int x)
{
    if (n == 0)
        return 0;
    return pow(2, n) * ((2 * n) + 1) * x + series(n - 1, x + 1);
}

int main()
{
    int n;
    cout << "take input : ";
    cin >> n;
    cout << "output sum : " << series(n, 1);
}