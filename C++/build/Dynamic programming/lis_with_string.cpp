#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(const std::vector<std::string> &sequence) {
    int n = sequence.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[i].compare(sequence[j]) > 0) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    int numStrings;
    std::cout << "Enter the number of strings: ";
    std::cin >> numStrings;

    std::vector<std::string> sequence(numStrings);
    std::cout << "Enter the strings:" << std::endl;
    for (int i = 0; i < numStrings; ++i) {
        std::cin >> sequence[i];
    }

    int lisLength = longestIncreasingSubsequence(sequence);

    std::cout << "Length of Longest Increasing Subsequence: " << lisLength << std::endl;

    return 0;
}
