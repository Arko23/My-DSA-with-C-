#include <bits/stdc++.h>
using namespace std;
int main()
{

    int sizeOf_bag = 20;
    double profit = 0.0;

    vector<pair<pair<double, int>, int>> pr;
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        double ratio;
        cout << "enter profit and weight : \n";
        cin >> x >> y;
        pr.push_back({{(double)x / (double)y, x}, y});
    }
    // for (auto x : pr)
    //     cout << x.first.first << " " << x.first.second << " " << x.second << endl;

    sort(pr.begin(), pr.end(), greater<pair<pair<double, int>, int>>());

    for (auto x : pr)
        cout << "\nprofit ratio : " << x.first.first << "\nvalue : "
             << x.first.second << "\nweight : " << x.second << endl
             << endl;

    auto it = pr.begin();

    while (it != pr.end())
    {
        if (sizeOf_bag > 0 && it->second <= sizeOf_bag)
        {
            sizeOf_bag = sizeOf_bag - it->second;
            profit += (double)it->second * (double)it->first.first;
        }
        else
            break;
        it++;
    }
    if (sizeOf_bag > 0)
    {
        int remain = it->second - sizeOf_bag;
        profit += (double)remain * (double)it->first.first;
    }

    cout << "total max profit he can earn : " << profit << endl;
}