#include <iostream>

using namespace std;

int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, (y - 1));
    }
}
int main()
{
    int x, y;
    cout << "enter the value : ";
    cin >> x;
    cout << "enter the positive numbered power: ";
    cin >> y;
    cout << "power of given number is : " << power(x, y);
}