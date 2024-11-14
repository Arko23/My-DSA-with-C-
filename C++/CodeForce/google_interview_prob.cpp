// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, Target;
//     cout << "size : ";
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Take input : ";
//         cin >> arr[i];
//     }
//     cout << "Print Array : ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " "; //"Take input : ";
//                                // cin >> arr[i];
//     }
//     cout << endl;
//     // int Target;
//     cout << "Targated sum of subarray : ";
//     cin >> Target;

//     for (int j = 0; j < n; j++)
//     {
//         for (int k = j + 1; k < n; k++)
//         {
//             int sum = 0;
//             sum = arr[j] + arr[k];
//             if (sum == Target)
//             {
//                 cout << "//Target found in the Array by sum of subarrays//" << endl;
//                // cout << "Sum is : " << sum;
//             }
//             else
//             {
//                 cout << "//Target Not found by sum of subarrays//";
//                // cout << "Non targated sum is : " << sum;
//             }
//         }
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
void findSubarrayWithTargetSum(int arr[], int n, int target)
{
    int start = 0;
    int currentSum = 0;

    for (int end = 0; end < n; end++)
    {

        currentSum += arr[end];

        while (currentSum > target)
        {
            currentSum -= arr[start];
            start++;
        }

        if (currentSum == target)
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "No subarray found with the target sum." << endl;
}

int main()
{
    int arr[] = {1, 3, 2, 9};
    int target = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    findSubarrayWithTargetSum(arr, n, target);

    return 0;
}
