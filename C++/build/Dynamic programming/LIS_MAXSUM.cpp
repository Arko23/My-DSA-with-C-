#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> v(N);
int dp[N];

int lisSum(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = v[i];  // Initialize ans with the value at index i
    for (int j = 0; j < i; j++) {
        if (v[i] > v[j]) {
            ans = max(ans, lisSum(j) + v[i]);
        }
    }
    return dp[i] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
       maxSum = max(maxSum, lisSum(i));
    }
    cout << maxSum << endl;
    return 0;
}
