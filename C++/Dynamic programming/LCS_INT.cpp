#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(const vector<int>& nums1, const vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int n1, n2;
    cout << "Enter the size of the first sequence: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the elements of the first sequence: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the size of the second sequence: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the elements of the second sequence: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    int length = longestCommonSubsequence(nums1, nums2);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
