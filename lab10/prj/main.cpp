#include <iostream>
#include <Windows.h>
#include "ModulesKalinichenko.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	bool isRunning = true;

    while (isRunning) {
        int choice;
        cout << "������� �������� ��� �������� \"0\" ��� ������ \n�������� 10.";
        cin >> choice;

        if (choice == 1) task10_1();
        else if (choice == 2) task10_2();
        else if (choice == 3) task10_3();
		else if (choice == 0) isRunning = false;
        else cout << "������ �������� �� ����.\n\n";
    }
    return 0;
}
