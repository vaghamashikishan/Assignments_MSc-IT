#include <iostream>
#include <cstring>
#include <string.h>
#include <cctype>

using namespace std;

int main()
{
    char chArrayA[100]{""}, chArrayB[100]{""};

    // a
    cin >> chArrayA >> chArrayB;
    cout << "a) \n";
    cout << "Firstname:- " << chArrayA << "\n"
         << "Lastname :- " << chArrayB << "\n";

    // b
    strcat(chArrayA, " ");
    strcat(chArrayA, chArrayB);
    cout << "b) \n";
    cout << chArrayA << "\n";

    // c
    cin.ignore();
    cin.getline(chArrayA, 90);
    cout << "c) \n";
    cout << chArrayA << "\n";

    // d
    int lastLocA = strlen(chArrayA) - 1;
    int lastLocB = 0;
    for (int i = lastLocA; i > 0; i--)
    {
        chArrayB[lastLocB++] = chArrayA[i];
    }
    cout << "d) \n";
    cout << chArrayB << "\n";

    // e
    char temp[100][100];
    int row{0}, col{0};
    temp[0][col++] = ' ';

    for (size_t i = 0; i < strlen(chArrayA); i++)
    {
        if (chArrayA[i] == ' ')
        {
            row++;
            col = 0;
        }
        temp[row][col++] = chArrayA[i];
    }

    lastLocB = 0;
    for (size_t I = row + 1; I > 0; I--)
    {
        int i = I - 1;
        for (size_t j = 0; j < strlen(temp[i]); j++)
        {
            chArrayB[lastLocB++] = temp[i][j];
        }
    }
    cout << "e) \n";
    cout << chArrayB << "\n";

    // f
    cin.getline(chArrayA, 100);
    lastLocB = 0;
    for (int i = 0; i < strlen(chArrayA); ++i)
    {
        if (std::isalpha(chArrayA[i]))
        {
            chArrayB[lastLocB++] = chArrayA[i];
        }
    }
    cout << chArrayB << "\n";
    return 0;
}