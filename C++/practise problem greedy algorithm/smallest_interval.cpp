#include <iostream>
using namespace std;
struct Interval
{
    double start;
    double end;
};

void findSmallestIntervals(double points[], int n, Interval intervals[], int &intervalCount)
{
    intervalCount = 0;
    int i = 0;

    while (i < n)
    {
        Interval interval;
        interval.start = points[i];
        interval.end = points[i] + 1.0;
        intervals[intervalCount++] = interval;

        // Skip points within the current interval
        while (i < n && points[i] <= interval.end)
        {
            i++;
        }
    }
}

void printIntervals(const Interval intervals[], int intervalCount)
{
    cout << "Smallest set of unit-length intervals: " << endl;
    for (int i = 0; i < intervalCount; i++)
    {
        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    double points[n];
    cout << "Enter the points in increasing order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    Interval intervals[n];
    int intervalCount;

    findSmallestIntervals(points, n, intervals, intervalCount);
    printIntervals(intervals, intervalCount);

    return 0;
}
