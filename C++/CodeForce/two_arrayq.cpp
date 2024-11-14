#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        unordered_map<int, int> count_dict;
        int max_length = 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> c;
            c.push_back(a[i]);
            c.push_back(b[i]);

            count_dict[a[i]]++;
            count_dict[b[i]]++;

            max_length = max(max_length, count_dict[a[i]]);
        }

        cout << max_length << endl;
    }

    return 0;       
}
