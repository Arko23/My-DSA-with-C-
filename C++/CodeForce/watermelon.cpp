#include <iostream>
using namespace std;

int main()
{
    int melon;
    cin >> melon;
    if (melon % 2 == 0 && melon > 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}