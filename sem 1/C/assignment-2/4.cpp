#include <bits/stdc++.h>
using namespace std;

// 0 - Tablet Mode
// 1 - WiFi
// 2 - Mute
// 3 - Airplane Mode
// 4 - Auto Hide Taskbar

const vector<string> settingNames = {
    "Tablet Mode",
    "WiFi",
    "Mute",
    "Airplane Mode",
    "Auto Hide Taskbar"};

void display(bitset<5> &settings)
{
    cout << "\n=================================\n";
    for (size_t i = 0; i < settings.size(); i++)
    {
        if (settings[i])
        {
            cout << settingNames[i];
            cout << " is *ON*\n";
        }
        else
        {
            cout << settingNames[i];
            cout << " is OFF\n";
        }
    }
    cout << "=================================\n";
}

void takeInput(bitset<5> &settings)
{
    cout << "\n=>Select option to toggle<=\n";
    for (size_t i = 0; i < settingNames.size(); i++)
    {
        cout << i + 1 << ") " << settingNames[i] << "\n";
    }
    int input;
    cin >> input;

    if (input >= 1 && input <= 5)
    {
        settings[input - 1] = ~settings[input - 1];
    }
    else
    {
        cout << "Invalid input\n";
    }
    display(settings);
}

int main()
{
    bitset<5> settings(00000);
    int input;
    bool isExist = false;
    display(settings);
    while (1)
    {
        if (isExist)
            break;

        cout << "Select one of the option...\n";
        cout << "1) Display the settings\n";
        cout << "2) Change the settings\n";
        cout << "3) EXIT\n";
        cin >> input;

        switch (input)
        {
        case 1:
            display(settings);
            break;

        case 2:
            takeInput(settings);
            break;

        case 3:
            isExist = true;
            break;

        default:
            cout << "Please provide valid response\n";
            break;
        }
    }
}