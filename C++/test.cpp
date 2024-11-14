#include <bits/stdc++.h>
using namespace std;
struct V
{
    int start;
    int end;
};
bool comp(V a1, V a2)
{
    return a1.end < a2.end;
}
vector<V> T;
vector<V> activity(vector<V> vec)
{
    int f_st = vec[0].start;
    int f_end = vec[0].end;
    cout << f_st << " to " << f_end << endl;
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].start >= f_end)
        {
            cout << vec[i].start << " to " << vec[i].end << endl;
            f_end = vec[i].end;
        }
        else
            T.push_back(vec[i]);
    }
    return T;
}
int main()
{
    int n, count = 0;
    cin >> n;
    vector<V> vec;
    V temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp.start >> temp.end;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), comp);
    // for (auto x : vec)
    //     cout << x.end << " ";
    while (vec.size() != 0)
    {
        cout << "\nperson " << count + 1 << ":" << endl;
        vec = activity(vec);
        T.clear();
        count++;
    }
    cout << "\ntotal people : " << count << endl;
}