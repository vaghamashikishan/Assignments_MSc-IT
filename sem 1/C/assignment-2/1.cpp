#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n1 = 0b10111001;
    ll n2 = 0b10010110;
    cout << "Decimal = " << (n1 & n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 & n2) << "\n";

    n1 = 0b11011110;
    n2 = 0b11000101;
    cout << "Decimal = " << (n1 & n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 & n2) << "\n";

    n1 = 0b01111101;
    n2 = 0b10111110;
    cout << "Decimal = " << (n1 | n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 | n2) << "\n";

    n1 = 0b11000110;
    n2 = 0b11011100;
    cout << "Decimal = " << (n1 | n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 | n2) << "\n";

    n1 = 0b10111001;
    n2 = 0b11110110;
    cout << "Decimal = " << (n1 ^ n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 ^ n2) << "\n";

    n1 = 0b11000010;
    n2 = 0b00000101;
    cout << "Decimal = " << (n1 ^ n2) << "\n";
    cout << "Binary  = " << bitset<8>(n1 ^ n2) << "\n";

    n1 = 0b1011100110010110;
    cout << "Binary  = " << bitset<16>(~n1) << "\n";

    n1 = 11011110;
    n2 = 11000101;
    cout << "Binary  = " << bitset<8>(~n1 & n2) << "\n";

    cout << bitset<8>(1 << 7) << "\n";

    ll num = pow(2, 7);
    cout << bitset<8>(num >> 4) << "\n";
}