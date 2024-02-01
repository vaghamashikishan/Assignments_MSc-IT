#include <bits/stdc++.h>
using namespace std;

vector<int> pendingOrders;

void placeOrder()
{
    int orderNumber = 1 + pendingOrders.size();
    pendingOrders.push_back(orderNumber);
    cout << "=================================\n";
    cout << "Your order is placed. Order Number:- " << orderNumber << "\n";
    cout << "=================================\n";
    cin.ignore();
}

void displayPendingOrders()
{
    cout << "=================================\n";
    cout << "Pending orders:- "
         << "\n";
    for (int orderNumber : pendingOrders)
    {
        cout << "=> Order Number: " << orderNumber << "\n";
    }
    cout << "Total pending orders:- " << pendingOrders.size() << "\n";
    cout << "=================================\n";
}

void serveOrder()
{
    cout << "=================================\n";
    cout << "Pending orders:\n";
    for (int orderNumber : pendingOrders)
    {
        cout << "=> Order Number: " << orderNumber << "\n";
    }

    cout << "\nPick order: ";
    int pickedOrder;
    cin >> pickedOrder;

    auto it = find(pendingOrders.begin(), pendingOrders.end(), pickedOrder);
    if (it != pendingOrders.end())
    {
        pendingOrders.erase(it);
        cout << "Order " << pickedOrder << " has been served.\n";
    }
    else
    {
        cout << "Invalid order number.\n";
    }
    cin.ignore();
    cout << "=================================\n";
}

int main()
{
    int choice{0};
    bool exit = false;
    while (1)
    {
        if (exit)
            break;

        cout << "1) Place order\n2) Pending orders\n3) Serve order\n4) Exit\nEnter your pick: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            placeOrder();
            break;

        case 2:
            displayPendingOrders();
            break;

        case 3:
            serveOrder();
            break;

        case 4:
            exit = true;
            break;

        default:
            cout << "Please enter valid choice."
                 << "\n";
            break;
        }
    }

    return 0;
}
