#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll bit = 0b10101110101010110101110100111011;

    cout << "1)\n";
    // set 16th bit
    bitset<32> result(bit | (1 << 15));
    cout << result << "\n";

    cout << "2)\n";
    // set 28th bit
    result = bitset<32>(bit & ~(1 << 27));
    cout << result << "\n";

    bitset<16> oddBit;
    bitset<16> evenBit;
    ll temp{bit};

    int i = 0;
    while (temp << 1 != 0)
    {
        oddBit[i++ / 2] = (temp & 1);
        temp = temp >> 1;
        evenBit[i++ / 2] = (temp & 1);
        temp = temp >> 1;
    }
    cout << "3)\n";
    cout << "Odd Bit  : " << oddBit << "\n";
    cout << "Even Bit : " << evenBit << "\n";

    cout << "4)\n";
    bitset<32> tempBit(bit);
    int n = 3; // 3rd nibble
    for (size_t i = 4 * (n - 1); i < 4 * n; i++)
    {
        tempBit[i] = ~tempBit[i];
    }
    cout << tempBit << "\n";
    return 0;
}