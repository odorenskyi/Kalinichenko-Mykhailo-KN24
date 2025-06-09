#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

double s_calculation(double x, double y, double z){
    return x + y + z;
}

int CountCharactersInFile(ifstream& file) {
    if (file.is_open()) {
        int count = 0;
        char character;
        while (file.get(character)) {
            count++;
        }
        file.clear();
        file.seekg(0, ios::beg);
        return count;
    }
    return 0;
}

bool isContainsWord(ifstream& file, const string& target) {
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл";
        return false;
    }

    string word;
    while (file >> word) {
        if (word == target) {
            file.clear();
            file.seekg(0, ios::beg);
            return true;
        }
    }
    file.clear();
    file.seekg(0, ios::beg);
    return false;
}

string IntToBinaryString(unsigned int n)
{
    string buffer;
    buffer.reserve(numeric_limits<unsigned int>::digits);
    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);
    return string(buffer.crbegin(), buffer.crend());
}

void task10_1()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!outfile.is_open()) return;

    outfile << "Звіт: лабораторна робота" << endl;
    outfile << "ПІБ/група: Калініченко Михайло KN-24" << endl;
    outfile << "Варіант: індивідуальний" << endl;
    outfile << "Тема: файли" << endl;
    outfile << "Рік виконання: 2025" << "\n\n";
    outfile << "У цьому файлі " << to_string(CountCharactersInFile(infile)) << " символів." << endl;

    // Перевірка наявності слів у файлі
    string targetwords[] = { "файл", "робота", "завдання", "індивідуальний"};
    for (const string& word : targetwords) {
        bool found = isContainsWord(infile, word);
        if (found) {
            outfile << "Слово \"" << word << "\" є у файлі." << endl;
        } else {
            outfile << "Слова \"" << word << "\" немає у файлі." << endl;
        }
    }

    cout << "Звіт було записано у файл output.txt\n\n";
}

void task10_2()
{
    ofstream file("input.txt", ios::app);

    if (file.is_open()) {
        file << "Завдання 10.2\n";

        // Додаємо довільний текст
        file << "Додаємо довільний текст у файл для перевірки 20 символів:\n";
        file << "- перший рядок\n";
        file << "- другий рядок\n";
        file << "- третій рядок\n";

        // Додаємо поточну дату і час
        time_t now = time(0);
        char* dt = ctime(&now);
        file << "Дата і час запису: " << dt << endl;
        file.close();

        cout << "Дані було записано у файл input.txt\n\n";
    }
}

void task10_3()
{
    ofstream file("input.txt", ios::app);

    file << "Завдання 10.3\n";

    int x, y, z;
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;

    file << "Результат функції s_calculation: " << s_calculation(x, y, z) << "." << endl;

    // Перевід b у двійкову систему
    int b;
    cout << "Введіть b: ";
    cin >> b;

    file << "Число " << b << " у двійковій системі: " << IntToBinaryString(b) << ".\n\n";

    file.close();

    cout << "Дані було записано у файл input.txt\n\n";
}
