#include <iostream>

using namespace std;

int main()
{
    int t, Petya, Vasya, Tonya;
    int count = 0;
    cin >> t;
    while (t--)
    {
        cin >> Petya >> Vasya >> Tonya;
        if (Petya + Vasya + Tonya >= 2)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}