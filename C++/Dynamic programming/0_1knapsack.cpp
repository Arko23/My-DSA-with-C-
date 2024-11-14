#include<bits/stdc++.h>
using namespace std;
int knap(int W,const vector<int>&weight,const vector<int>&value,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
           if(weight[i-1]<=w)
           {
            dp[i][w]=max(dp[i-1][w],value[i-1]+dp[i-1][w-weight[i-1]]);
           }
           else
           {
            dp[i][w]=dp[i-1][w];
           }
        }
    }
    return dp[n][W];

}
int main()
{
    int n,w;
    cout<<"number of items : ";
    cin>>n;
    vector<int> weight(n),value(n);
    cout<<"weight of items :";
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    cout<<"value of item : ";
     for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int W;
    cout<<"max weight : ";
    cin>>W;
   
    cout<<"max value :"<< knap(W,weight,value,n)<<endl;

}















// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int w = 1; w <= W; ++w) {
//             if (weights[i - 1] <= w) {
//                 dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
//             } else {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }

//     return dp[n][W];
// }

// int main() {
//     int n, W;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<int> weights(n), values(n);

//     cout << "Enter the weights of items:\n";
//     for (int i = 0; i < n; ++i) {
//         cin >> weights[i];
//     }

//     cout << "Enter the values of items:\n";
//     for (int i = 0; i < n; ++i) {
//         cin >> values[i];
//     }

//     cout << "Enter the maximum weight capacity: ";
//     cin >> W;

//     int maxValue = knapsack(W, weights, values, n);
//     cout << "Maximum value that can be obtained: " << maxValue << endl;

//     return 0;
// }














// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
// //     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

// //     for (int i = 1; i <= n; ++i) {
// //         for (int w = 1; w <= W; ++w) {
// //             if (weights[i - 1] <= w) {
// //                 dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
// //             } else {
// //                 dp[i][w] = dp[i - 1][w];
// //             }
// //         }
// //     }

// //     return dp[n][W];
// // }

// // int main() {
// //     int n, W;
// //     cout << "Enter the number of items: ";
// //     cin >> n;

// //     vector<int> weights(n), values(n);

// //     cout << "Enter the weights of items:\n";
// //     for (int i = 0; i < n; ++i) {
// //         cin >> weights[i];
// //     }

// //     cout << "Enter the values of items:\n";
// //     for (int i = 0; i < n; ++i) {
// //         cin >> values[i];
// //     }

// //     cout << "Enter the maximum weight capacity: ";
// //     cin >> W;

// //     int maxValue = knapsack(W, weights, values, n);
// //     cout << "Maximum value that can be obtained: " << maxValue << endl;

// //     return 0;
// // }
