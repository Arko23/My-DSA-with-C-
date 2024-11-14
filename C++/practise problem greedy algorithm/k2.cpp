#include <bits/stdc++.h>

using namespace std;

struct S
{
    int id;
    int start;
    int finish;
};

bool comp(S item1, S item2)
{
    return item1.finish < item2.finish;
}

vector<S> activity_selecion(vector<S> V)
{
    int n = V.size();
    vector<S> soln;
    soln.push_back(V[0]);
    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        if (V[i].start >= (V[curr].finish + 1))
        {
            soln.push_back(V[i]);
            curr = i;
        }
    }
    return soln;
}

int main()
{
    int m;
    cin >> m;

    int n;
    cin >> n;

    vector<S> V(n);
    S temp;
    for (int i = 0; i < n; i++)
    {
        cout << "task " << i + 1 << endl;
        temp.id = i + 1;
        cin >> temp.start >> temp.finish;
        V.push_back(temp);
    }
    sort(V.begin(), V.end(), comp);

    vector<S> X = activity_selecion(V);

    cout << X.size() * m << endl;

    for (auto x : X)
        cout << x.id << endl;
}