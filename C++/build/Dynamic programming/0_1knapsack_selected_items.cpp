#include<bits/stdc++.h>
using namespace std;

int knap(const int W, const vector<int>& weight, const vector<int>& value, const int n, vector<int>& selectedItems) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    selectedItems.clear();
    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] > dp[i - 1][w]) {
            selectedItems.push_back(i);
            w -= weight[i - 1];
        }
        i--;
    }

    reverse(selectedItems.begin(), selectedItems.end());

    return dp[n][W];
}

int main() {
    int n, w;
    cout << "Number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);
    cout << "Weight of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Value of items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int W;
    cout << "Max weight: ";
    cin >> W;

    vector<int> selectedItems;
    int maxValue = knap(W, weight, value, n, selectedItems);

    cout << "Max value: " << maxValue << endl;
    cout << "Selected items: ";
    for (int i = 0; i < selectedItems.size(); i++) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;

    return 0;
}
