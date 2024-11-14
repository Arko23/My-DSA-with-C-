#include <iostream>
#include <string>
using namespace std;

struct Coin
{
    string name;
    int value;
};

void makeChange(int N, Coin coins[], int numCoins)
{
    int totalCoins = 0;

    for (int i = 0; i < numCoins; ++i)
    {
        int count = N / coins[i].value;
        N %= coins[i].value;

        cout << coins[i].name << " --- " << count << endl;
        totalCoins += count;
    }

    cout << "Total " << totalCoins << " coins" << endl;
}

int main()
{
    int N;
    cout << "Enter the amount in cents: ";
    cin >> N;

    int numCoins;
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;

    Coin coins[numCoins];

    for (int i = 0; i < numCoins; ++i)
    {
        cout << "Enter the name and value of coin #" << i + 1 << ": ";
        cin >> coins[i].name >> coins[i].value;
    }

    makeChange(N, coins, numCoins);

    return 0;
}
