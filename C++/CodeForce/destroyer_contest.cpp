#include <iostream>
#include <algorithm>

using namespace std;
// 5
// 6
// 0 1 2 0 1 0
// 9
// 0 0 0 0 1 1 1 2 2
// 3
// 0 0 2
// 1
// 99
// 5
// 0 1 2 3 4

bool canArrangeRobots(int reportedNumbers[], int n)
{
    sort(reportedNumbers, reportedNumbers + n); // Sort the reported numbers in ascending order

    for (int i = 0; i < n; i++)
    {
        if (reportedNumbers[i] > i)
        {
            return false;
        }
    }

    if (reportedNumbers[0] != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int reportedNumbers[n];
        for (int i = 0; i < n; i++)
        {
            cin >> reportedNumbers[i];
        }

        if (canArrangeRobots(reportedNumbers, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}