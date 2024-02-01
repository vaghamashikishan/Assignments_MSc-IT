#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int main()
{
    int row, col;

    cin >> row >> col;
    char arr[MAX][MAX] = {0};
    bool flg = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = '*';
        }
    }
    int round = 0;
    row--, col--;
    while (1)
    {
        int col_limit = col - (round + 1), row_limit = row - (round + 1);
        int x1 = round, y1 = round, x2 = round, y2 = col - round, x3 = row - round, y3 = round, x4 = row - round, y4 = col - round;
        if (y1 > y2 || y3 > y4 || x1 > x3 || x2 > x4)
            break;
        while (y1 <= col_limit)
            arr[x1][y1++] = arr[x4][y4--] = '-';
        while (x2 <= row_limit)
            arr[x2++][y2] = arr[x3--][y3] = '-';
        round += 2;
    }
    if (row == col && (row % 4) == 0)
    {
        arr[row / 2][col / 2] = '-';
    }
    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j < col + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}