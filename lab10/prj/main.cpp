#include <iostream>
#include <Windows.h>
#include <limits>
#include "ModulesKalinichenko.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	bool isRunning = true;

    while (isRunning) {
        int choice;
        bool validInput = false;
        while (!validInput) {
            cout << "Виберіть завдання або напишіть \"0\" для виходу \nЗавдання 10.";
            cin >> choice;z
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
