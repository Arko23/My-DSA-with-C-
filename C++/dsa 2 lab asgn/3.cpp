#include <bits/stdc++.h>

using namespace std;
static int schedule[11];

struct Task
{
    char id;
    int end;
    int dur;
    int pay;
};

bool compare(Task t1, Task t2)
{
    return ((t1.pay / t1.dur) >= (t2.pay / t2.dur));
}

void fillSchedule(int schedule[], int start, int end)
{
    for (int i = start; i <= end; i++)
        schedule[i] = 1;
}

int selectTasks(Task tasks[], int n, int schedule[])
{
    int profit = 0;
    int count = 0;
    int endTime;

    fillSchedule(schedule, tasks[0].end - tasks[0].dur + 1, tasks[0].end);
    profit += tasks[0].pay;

    cout << tasks[0].id << endl;

    for (int i = 1; i < n; i++)
    {
        count = 0;
        for (int hour = tasks[i].end; hour >= 1; hour--)
        {
            if (schedule[hour] == -1)
            {
                count++;

                if (count == tasks[i].dur)
                {
                    endTime = hour;
                    break;
                }
            }
        }

        if (count == tasks[i].dur)
        {
            cout << tasks[i].id << endl;
            profit += tasks[i].pay;
            fillSchedule(schedule, endTime, tasks[i].end);
        }
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;

    Task tasks[n];
    memset(schedule, -1, sizeof(schedule));

    for (int i = 0; i < n; i++)
    {
        cout << "T" << i + 1 << ": ";
        cin >> tasks[i].id;
        cin >> tasks[i].end >> tasks[i].dur >> tasks[i].pay;
    }
    sort(tasks, tasks + n, compare);

    int totalProfit = selectTasks(tasks, n, schedule);
    cout << "Total Profit: " << totalProfit;

    return 0;
}
