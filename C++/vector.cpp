#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        a.push_back(v);
    }
    for (auto el : a)
    {
        cout << el << endl;
    }
}