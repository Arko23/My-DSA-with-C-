#include <iostream>

using namespace std;

int max(int **arr, int mx, int i, int j, int row, int col)
{
    if (i == row + 1)
        return mx;
    if (i < row)
    {
        if (j == col + 1)
            return mx;
        if (j < col)
        {
            if (arr[i][j] > mx)
            {
                mx = arr[i][j];
                return max(arr, mx, i, j + 1, row, col);
            }
            else
                return max(arr, mx, i, j + 1, row, col);
        }
        return max(arr, mx, i + 1, 0, row, col);
    }
    return max(arr, mx, i + 1, 0, row, col);
}
int main()
{
    int row, col;
    cout << " enter row and column together :";
    cin >> row >> col;

    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    cout << max(arr, arr[0][0], 0, 0, row, col);
}