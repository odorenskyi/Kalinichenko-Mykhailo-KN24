#include <iostream>
#include <Windows.h>
#include <limits>
#include "ModulesKalinichenko.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	bool isRunning = true;

    while (isRunning) {
        int choice;
        bool validInput = false;
        while (!validInput) {
            cout << u8"Виберіть завдання або напишіть \"0\" для виходу \nЗавдання 10.";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Помилка: введіть ціле число!\n";
            } else {
                validInput = true;
            }
        }

        if (choice == 1) task10_1();
        else if (choice == 2) task10_2();
        else if (choice == 3) task10_3();
        else if (choice == 0) isRunning = false;
        else cout << "Такого завдання не існує.\n\n";
        // ...existing code...
    }
    return 0;
}
