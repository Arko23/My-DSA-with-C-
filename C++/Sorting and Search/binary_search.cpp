#include <iostream>
using namespace std;
int BinarySearch(int nums[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int target;
    cout << "enter target : ";
    cin >> target;
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = BinarySearch(nums, 0, n - 1, target);
    if (result == -1)
    {
        cout << "elment not found";
    }
    else
    {
        cout << "element exists at index: " << result << " ";
    }
    cout << endl;
    return 0;
}