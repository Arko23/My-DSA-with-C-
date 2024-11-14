#include <bits/stdc++.h>
using namespace std;
struct active
{
    int id;
    int s;
    int f;
};
bool comp(active b1, active b2)
{
    return b1.f < b2.f;
}
// input
// 5
// Item #1    // Activity 1 details
// 1 4        // Activity 1 start time, finish time
// Item #2    // Activity 2 details
// 3 5        // Activity 2 start time, finish time
// Item #3    // Activity 3 details
// 0 6        // Activity 3 start time, finish time
// Item #4    // Activity 4 details
// 5 7        // Activity 4 start time, finish time
// Item #5    // Activity 5 details
// 8 9
// output
// 1
// 4
// 5
vector<active> activity(vector<active> a)
{
    int x = a.size();
    vector<active> sol;
    sol.push_back(a[0]);
    int cur = 0;
    for (int i = 1; i < x; i++)
    {

        if (a[i].s >= a[cur].f + 2)
        {
            sol.push_back(a[i]);
            cur = i;
        }
    }
    return sol;
}
int main()
{
    int n;
    cin >> n;
    vector<active> a(n);
    active temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Item # " << i + 1 << endl;
        temp.id = i + 1;
        cin >> temp.s >> temp.f;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), comp);
    vector<active> result;
    result = activity(a);
    for (active i : result)
    {
        cout << "ID : " << i.id << endl;
    }
}
