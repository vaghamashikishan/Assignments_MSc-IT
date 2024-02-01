#include <bits/stdc++.h>
using namespace std;

int main()
{
    double arr[5];
    double value = 1.1;

    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = value;
        // cout << value << "\n";
        value += 0.1;
    }

    for (size_t i = 5; i > 0; i--)
    {
        cout << arr[i - 1] << " ";
    }

    return 0;
}