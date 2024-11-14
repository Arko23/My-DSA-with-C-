#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> v(N);
int dp[N];

int lis(int i)
{
    if(dp[i]!=-1)return dp[i];
    int ans=1;
    for(int j=0;j<i;j++)
    {
        if(v[i]>v[j])
        {
            ans=max(ans,lis(j)+1);
        }
    }
    return dp[i]=ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
       ans=max(ans,lis(i));
    }
    cout<<ans;
}





// #include <iostream>
// #include <vector>
// #include <algorithm>

// int secondHighestLIS(const std::vector<int> &sequence) {
//     int n = sequence.size();
//     std::vector<int> lis(n, 1);
//     std::vector<int> lisRev(n, 1);

//     // Calculate LIS from left to right
//     for (int i = 1; i < n; ++i) {
//         for (int j = 0; j < i; ++j) {
//             if (sequence[i] > sequence[j]) {
//                 lis[i] = std::max(lis[i], lis[j] + 1);
//             }
//         }
//     }

//     // Calculate LIS from right to left
//     for (int i = n - 2; i >= 0; --i) {
//         for (int j = n - 1; j > i; --j) {
//             if (sequence[i] > sequence[j]) {
//                 lisRev[i] = std::max(lisRev[i], lisRev[j] + 1);
//             }
//         }
//     }

//     int secondHighest = 0;
//     for (int i = 0; i < n; ++i) {
//         // Exclude the current element from both LIS
//         // and then check if the sum of LIS on the left and
//         // right of the element is the second highest.
//         secondHighest = std::max(secondHighest, lis[i] + lisRev[i] - 1);
//     }

//     return secondHighest;
// }

// int main() {
//     int numElements;
//     std::cout << "Enter the number of elements: ";
//     std::cin >> numElements;

//     std::vector<int> sequence(numElements);
//     std::cout << "Enter the elements:" << std::endl;
//     for (int i = 0; i < numElements; ++i) {
//         std::cin >> sequence[i];
//     }

//     int secondHighestLISLength = secondHighestLIS(sequence);

//     std::cout << "Second Highest LIS Length: " << secondHighestLISLength << std::endl;

//     return 0;
// }
