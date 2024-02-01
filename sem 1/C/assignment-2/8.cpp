#include <iostream>
#include <bitset>
using namespace std;

int seats[16];
const int totalRow = 16;
const int totalSeatInRow = 20;
const char seatBooked{'X'};
const char seatAvailale{'.'};

void setInitialData()
{
    for (size_t i = 0; i < totalRow; i++)
    {
        seats[i] = 0;
    }
}

void display()
{
    char rowName = 'A';
    for (size_t i = 0; i < totalRow; i++)
    {
        bitset<20> row(seats[i]);
        for (size_t i = 0; i < row.size(); i++)
        {
            if (row[i] == 1)
            {
                cout << seatBooked;
            }
            else
            {
                cout << seatAvailale;
            }
        }
        cout << "   <=== " << rowName++;
        cout << "\n";
    }
    cout << "VVVVVVVVVVVVVVVVVVVV   Screeen this way\n";
}

void buyTicket()
{
    char rowName{};
    int row{0}, col{0};
    cout << "Enter row:- ";
    cin >> rowName;
    cout << "Enter seat number:- ";
    cin >> col;
    row = (rowName >= 'A' && rowName <= 'P') ? (rowName - 'A') : ((rowName >= 'a' && rowName <= 'p') ? (rowName - 'a') : -1);

    if (row != -1)
    {
        if (col > 0 && col <= totalSeatInRow)
        {
            bitset<20> temp = bitset<20>(seats[row]);
            if (temp[col - 1] == 0)
            {
                temp[col - 1] = 1;
                seats[row] = static_cast<int>(temp.to_ulong());
                cout << rowName << "-" << col << " has been booked successfully.\n";
            }
            else
            {
                cout << "Sorry, this seat is already booked.\n";
            }
        }
        else
        {
            cout << "Seat number you entered is not valid.\n";
        }
    }
    else
    {
        cout << "Please enter vaild seat name.\n";
    }
}

void cancelTicket()
{
    char rowName{};
    int row{0}, col{0};
    cout << "Enter row:- ";
    cin >> rowName;
    cout << "Enter seat number:- ";
    cin >> col;
    row = (rowName >= 'A' && rowName <= 'P') ? (rowName - 'A') : ((rowName >= 'a' && rowName <= 'p') ? (rowName - 'a') : -1);

    if (row != -1)
    {
        if (col > 0 && col <= totalSeatInRow)
        {
            bitset<20> temp = bitset<20>(seats[row]);
            if (temp[col - 1] == 1)
            {
                temp[col - 1] = 0;
                seats[row] = static_cast<int>(temp.to_ulong());
                cout << "Your ticket " << rowName << "-" << col << " has been cancelled successfully.\n";
            }
            else
            {
                cout << "Please recheck again, this seat is not booked.\n";
            }
        }
        else
        {
            cout << "Seat number you entered is not valid.\n";
        }
    }
    else
    {
        cout << "Please enter vaild row name.\n";
    }
}

int main()
{
    int choice{0};
    display();
    bool exit = false;
    while (1)
    {
        if (exit)
            break;

        cout << "1) Buy a ticket \n2) Cancel a ticket \n3) Exit";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "===============================\n";
            buyTicket();
            cout << "===============================\n";
            display();
            break;

        case 2:
            cout << "===============================\n";
            cancelTicket();
            cout << "===============================\n";
            display();
            break;

        case 3:
            exit = true;
            break;

        default:
            cout << "Please enter valid choice\n";
            break;
        }
    }
}