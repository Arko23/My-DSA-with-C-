#include<bits/stdc++.h>
using namespace std;

int coin_exchange(int M, int C[], int d) {
    int sol[M + 1], A[M + 1];
    sol[0] = 0;
    A[0] = -1;

    for (int m = 1; m <= M; m++) {
        sol[m] = 9999;
        for (int i = 0; i < d; i++) {
            if (C[i] <= m) {
                int cur = 1 + sol[m - C[i]];
                if (cur < sol[m]) {
                    sol[m] = cur;
                    A[m] = C[i];
                }
            }
        }
    }

    return sol[M];
}

int main() {
    int coins[] = {1, 5, 23, 25};
    int d = sizeof(coins) / sizeof(coins[0]);
    int targetAmount = 46;
    
    int numCoins = coin_exchange(targetAmount, coins, d);
    cout << "To make " << targetAmount << " cents:" << endl;
    for (int j = 0; j < d; j++) {
        int count = 0;
        int amountLeft = targetAmount;
        while (amountLeft >= coins[j] && coin_exchange(amountLeft, coins, d) == numCoins) {
            amountLeft -= coins[j];
            count++;
        }
        cout << count << " coin(s) of value " << coins[j] << endl;
    }
    
    return 0;
}
