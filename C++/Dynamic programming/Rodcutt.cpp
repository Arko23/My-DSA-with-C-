#include <bits/stdc++.h>
using namespace std;

void rC(int P[], int n) {
    int r[n + 1];
    int cuts[n + 1];
    r[0] = 0;

    for (int i = 1; i <= n; i++) {
        r[i] = -9999;
        for (int j = 1; j <= i; j++) {
            int cur = P[j] + r[i - j];
            if (cur > r[i]) {
                r[i] = cur;
                cuts[i] = j;
            }
        }
    }

    cout << "Maximum revenue: " << r[n] << endl;

    cout << "Optimal cut lengths: ";
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the price list: ";
    cin >> n;

    int P[n + 1];
    cout << "Enter the price list (starting from length 1):\n";
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    int rodLength;
    cout << "Enter the length of the rod: ";
    cin >> rodLength;

    rC(P, rodLength);
    return 0;
}


// int findMaxProfitForCut(int P[], int n, int cutLength) {
//     int r[n + 1];
//     r[0] = 0;

//     for (int i = 1; i <= n; i++) {
//         r[i] = -9999;
//         for (int j = 1; j <= i; j++) {
//             if (j == cutLength) {
//                 int cur = P[j] + r[i - j];
//                 r[i] = max(r[i], cur);
//             }
//         }
//     }

//     return r[n];
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements in the price list: ";
//     cin >> n;

//     int P[n + 1];
//     cout << "Enter the price list (starting from length 1):\n";
//     for (int i = 1; i <= n; i++) {
//         cin >> P[i];
//     }

//     int cutLength;
//     cout << "Enter the cut length you want to find the max profit for: ";
//     cin >> cutLength;

//     int maxProfit = findMaxProfitForCut(P, n, cutLength);
//     cout << "Maximum profit for cut length " << cutLength << ": " << maxProfit << endl;

//     return 0;
// }
// In this modified code, we've created a new function findMaxProfitForCut that calculates the maximum profit for a specific cut length using dynamic programming. The function directly calculates the maximum profit for the given cut length, instead of calculating all possible cut configurations.

// The rest of the main function remains mostly the same as the previous code. When you run this code, it will take inputs for the price list, and then it will output the maximum profit for the specified cut length.







// #include <bits/stdc++.h>
// using namespace std;

// int countRodCuttingPatterns(int n) {
//     int dp[n + 1];
//     memset(dp, 0, sizeof(dp));
//     dp[0] = 1;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= i; j++) {
//             dp[i] += dp[i - j];
//         }
//     }

//     return dp[n];
// }

// void rC(int P[], int n) {
//     int r[n + 1];
//     int cuts[n + 1];
//     r[0] = 0;

//     for (int i = 1; i <= n; i++) {
//         r[i] = -9999;
//         for (int j = 1; j <= i; j++) {
//             int cur = P[j] + r[i - j];
//             if (cur > r[i]) {
//                 r[i] = cur;
//                 cuts[i] = j;
//             }
//         }
//     }

//     cout << "Maximum revenue: " << r[n] << endl;

//     cout << "Optimal cut lengths: ";
//     while (n > 0) {
//         cout << cuts[n] << " ";
//         n -= cuts[n];
//     }
//     cout << endl;

//     int numPatterns = countRodCuttingPatterns(n);
//     cout << "Total number of rod cutting patterns: " << numPatterns << endl;
// }

// int main() {
//     int n;
//     cout << "Enter the number of elements in the price list: ";
//     cin >> n;

//     int P[n + 1];
//     cout << "Enter the price list (starting from length 1):\n";
//     for (int i = 1; i <= n; i++) {
//         cin >> P[i];
//     }

//     int rodLength;
//     cout << "Enter the length of the rod: ";
//     cin >> rodLength;

//     rC(P, rodLength);
//     return 0;
// }

