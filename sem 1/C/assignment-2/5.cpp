#include <iostream>
using namespace std;
typedef unsigned int uint;
void print(int num)
{
    cout << "\nValues Selected : \n\n";
    int temp = 0;
    while (temp < 12)
    {
        if ((temp + 1) == 1)
        {
            if (num & 1)
                cout << "Seat Covers";
        }
        else if ((temp + 1) == 2)
        {
            if (num & 1)
                cout << " : Beige ";
        }
        else if ((temp + 1) == 3)
        {
            if (num & 1)
                cout << " : Dark ";
        }
        else if ((temp + 1) == 4)
        {
            if (num & 1)
                cout << " : Dual Pattern ";
        }
        else if ((temp + 1) == 5)
        {
            if (num & 1)
                cout << "\n"
                     << "Alloys";
        }
        else if ((temp + 1) == 6)
        {
            if (num & 1)
                cout << "\n"
                     << "Colors ";
        }
        else if ((temp + 1) == 7)
        {
            if (num & 1)
                cout << " : Coffee Brown ";
        }
        else if ((temp + 1) == 8)
        {
            if (num & 1)
                cout << " : Pearl White";
        }
        else if ((temp + 1) == 9)
        {
            if (num & 1)
                cout << " : Marine Blue ";
        }
        else if ((temp + 1) == 10)
        {
            if (num & 1)
                cout << " : Ash Grey ";
        }
        else if ((temp + 1) == 11)
        {
            if (num & 1)
                cout << "\n"
                     << "Steering Cover";
        }
        else if ((temp + 1) == 12)
        {
            if (num & 1)
                cout << "\n"
                     << "Body Cover"
                     << "\n";
        }
        num = num >> 1;
        temp++;
    }
    cout << "\n\n";
}
void CarCompany()
{
    unsigned int num{0b0}, bcv = {0b1};
    bool select = 0;
    int ch;
    cout << "\n--- Welcome To Car Company---\n\n";
    cout << "Select for \"Seat Cover\" (0 for no / 1 for yes): ";
    cin >> select;
    if (select == 1)
    {
        num = num | bcv;
        cout << "\nSelect for Seat cover :- \n";
        cout << " 1) Beige\n";
        cout << " 2) Dark\n";
        cout << " 3) Dual Pattern\n";
        cout << "Enter Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            num = num | bcv << 1;
            break;
        case 2:
            num = num | bcv << 2;
            break;
        case 3:
            num = num | bcv << 3;
            break;
        default:
            break;
        }
    }
    cout << "\nDo you want \"Alloys\" (0 for no / 1 for yes): ";
    cin >> select;
    if (select == 1)
    {
        num = num | bcv << 4;
    }
    cout << "\nDo you want to Select for \"Colors\" (0 for no / 1 for yes): ";
    cin >> select;
    if (select == 1)
    {
        num = num | bcv << 5;
        cout << "\nSelect for Colors : \n";
        cout << " 1) Coffee Brown\n";
        cout << " 2) Pearl White\n";
        cout << " 3) Marine Blue\n";
        cout << " 4) Ash Grey\n";
        cout << "Enter Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            num = num | bcv << 6;
            break;
        case 2:
            num = num | bcv << 7;
            break;
        case 3:
            num = num | bcv << 8;
            break;
        case 4:
            num = num | bcv << 9;
            break;
        default:
            break;
        }
    }
    cout << "\nDo you want \"Steering Cover\" (0 for no / 1 for yes): ";
    cin >> select;
    if (select == 1)
    {
        num = num | bcv << 10;
    }
    cout << "\nDo you want \"Body Cover\" (0 for no / 1 for yes): ";
    cin >> select;
    if (select == 1)
    {
        num = num | bcv << 11;
    }
    print(num);
}

int main()
{
    CarCompany();
}