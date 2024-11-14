#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> v(N);
int dp[N];
int cnt[N];  // To store the count of subsequences

int lisCount(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (v[i] > v[j]) {
            int subsequenceCount = lisCount(j);
            if (subsequenceCount + 1 > ans) {
                ans = subsequenceCount + 1;
                cnt[i] = cnt[j];  // Update count with the count of previous subsequence
            } else if (subsequenceCount + 1 == ans) {
                cnt[i] += cnt[j];  // Increment count if we found another longest subsequence
            }
        }
    }
    if (cnt[i] == 0) cnt[i] = 1;  // Initialize count if it's not set
    return dp[i] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, lisCount(i));
    }
    int totalCnt = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLength) {
            totalCnt += cnt[i];
        }
    }
    cout << totalCnt << endl;
    return 0;
}
