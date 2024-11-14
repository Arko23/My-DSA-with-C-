#include <bits/stdc++.h>
using namespace std;
string prefix(string left_P, string right_P)
{
    int mn = min(left_P.length(), right_P.length());
    string pre = "";
    for (int i = 0; i < mn; i++)
    {
        if (left_P[i] == right_P[i])
        {
            pre += left_P[i];
        }
        else
        {
            break;
        }
    }
    return pre;
}
string DC(vector<string> &w, int low, int high)
{
    if (low == high)
    {
        return w[low];
    }

    int mid = low + (high - low) / 2;
    string left_P = DC(w, low, mid);
    string right_P = DC(w, mid + 1, high);
    return prefix(left_P, right_P);
}
int main()
{
    int n;
    cout << "size = ";
    cin >> n;
    vector<string> w;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        w.push_back(s);
    }
    string result = DC(w, 0, n - 1);
    if (result.empty())
    {
        cout << "oops!,No common prefix " << endl;
    }
    else
    {
        cout << "we got the common prefix!!! ,it is = " << result << endl;
    }
    return 0;
}
