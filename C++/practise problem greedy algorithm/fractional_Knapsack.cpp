#include <bits/stdc++.h>
using namespace std;
struct item
{
    int id;
    int v;
    int w;
};
bool comp(item a1, item a2)
{
    return a1.v / a1.w > a2.v / a2.w;
}
float knap(item arr[], int n, int W)
{
    sort(arr, arr + n, comp);
    int k = W;
    float profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].w <= k)
        {
            cout << "Item# : " << i + 1 << endl;
            profit += arr[i].v;
            k -= arr[i].w;
        }
        else
        {
            float x = k * 1.0 / arr[i].w;
            cout << "Item# : " << i + 1 << " Ratio " << x << endl;
            profit += arr[i].v * x;
            break;
        }
        // return profit;
    }
    return profit;
}
int main()
{
    int n, W;
    cin >> n;
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Item# : " << i + 1 << endl;
        arr[i].id = i + 1;
        cin >> arr[i].v >> arr[i].w;
    }
    cin >> W;
    cout << "Profit : " << knap(arr, n, W);
}
