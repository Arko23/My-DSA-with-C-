#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int id;
    int w;
    int v;
};
bool comp(Item a1, Item a2)
{
    return a1.v / a1.w > a2.v / a2.w;
}
float knapsack(Item a[], int n, int W)
{
    sort(a, a + n, comp);
    int knap = W;
    float profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        // a[0]
        /// If we can pick the whole item
        if (a[i].w <= knap)
        {
            cout << "Item #" << i + 1 << endl;
            profit += a[i].v;
            knap -= a[i].w;
        }
        else
        {
            float xi = knap * 1.0 / a[i].w;
            cout << "Item #" << i + 1 << "Ratio: " << xi << endl;

            profit += a[i].v * xi;
            break;
        }
    }
    return profit;
}
int main()
{
    int n, W;
    cin >> n;
    Item a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Item #" << i + 1 << endl;
        a[i].id = i + 1; /// item id: 1,2,3...n
        cin >> a[i].v >> a[i].w;
    }
    cin >> W;
    cout << "Profit: " << knapsack(a, n, W);

    return 0;
}
