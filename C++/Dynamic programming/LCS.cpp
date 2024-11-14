#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(const string& str1, const string& str2, string& lcs) {
    int m = str1.length();
    int n = str2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lcs = "";  // Initialize the LCS string
    
    // Construct the LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    string lcs;
    int length = longestCommonSubsequence(str1, str2, lcs);
    cout << "Length of Longest Common Subsequence: " << length << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
    



    //////////



//     #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int longestCommonSubsequence(const string& str1, const string& str2, string& lcs) {
//     int m = str1.length();
//     int n = str2.length();
    
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//     for (int i = 1; i <= m; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             if (str1[i - 1] == str2[j - 1]) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     lcs = "";  // Initialize the LCS string
    
//     // Construct the LCS
//     int i = m, j = n;
//     while (i > 0 && j > 0) {
//         if (str1[i - 1] == str2[j - 1]) {
//             lcs = str1[i - 1] + lcs;
//             i--;
//             j--;
//         } else if (dp[i - 1][j] >= dp[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//     }

//     return dp[m][n];
// }

// int longestRepeatingSubsequence(const string& str, string& lrs) {
//     int n = str.length();
    
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             if (str[i - 1] == str[j - 1] && i != j) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             } else {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }

//     lrs = "";  // Initialize the LRS string
    
//     // Construct the LRS
//     int i = n, j = n;
//     while (i > 0 && j > 0) {
//         if (dp[i][j] == dp[i - 1][j - 1] + 1 && str[i - 1] == str[j - 1] && i != j) {
//             lrs = str[i - 1] + lrs;
//             i--;
//             j--;
//         } else if (dp[i - 1][j] >= dp[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//     }

//     return dp[n][n];
// }

// int main() {
//     string str;
//     cout << "Enter a string: ";
//     cin >> str;

//     string lcs, lrs;
//     int lengthLCS = longestCommonSubsequence(str, str, lcs);
//     int lengthLRS = longestRepeatingSubsequence(str, lrs);

//     cout << "Length of Longest Common Subsequence: " << lengthLCS << endl;
//     cout << "Longest Common Subsequence: " << lcs << endl;
//     cout << "Length of Longest Repeating Subsequence: " << lengthLRS << endl;
//     cout << "Longest Repeating Subsequence: " << lrs << endl;

//     return 0;
// }
