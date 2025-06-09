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
        cout << "�� ������� ������� ����";
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

    outfile << "���: ����������� ������" << endl;
    outfile << "ϲ�/�����: ��������� ������� KN-24" << endl;
    outfile << "������: �������������" << endl;
    outfile << "����: �����" << endl;
    outfile << "г� ���������: 2025" << "\n\n";
    outfile << "� ����� ���� " << to_string(CountCharactersInFile(infile)) << " �������." << endl;

    // �������� �������� ��� � ����
    string targetwords[] = { "����", "������", "��������", "�������������"};
    for (const string& word : targetwords) {
        bool found = isContainsWord(infile, word);
        if (found) {
            outfile << "����� \"" << word << "\" � � ����." << endl;
        } else {
            outfile << "����� \"" << word << "\" ���� � ����." << endl;
        }
    }

    cout << "��� ���� �������� � ���� output.txt\n\n";
}

void task10_2()
{
    ofstream file("input.txt", ios::app);

    if (file.is_open()) {
        file << "�������� 10.2\n";

        // ������ �������� �����
        file << "������ �������� ����� � ���� ��� �������� 20 �������:\n";
        file << "- ������ �����\n";
        file << "- ������ �����\n";
        file << "- ����� �����\n";

        // ������ ������� ���� � ���
        time_t now = time(0);
        char* dt = ctime(&now);
        file << "���� � ��� ������: " << dt << endl;
        file.close();

        cout << "��� ���� �������� � ���� input.txt\n\n";
    }
}

void task10_3()
{
    ofstream file("input.txt", ios::app);

    file << "�������� 10.3\n";

    int x, y, z;
    cout << "������ x: ";
    cin >> x;
    cout << "������ y: ";
    cin >> y;
    cout << "������ z: ";
    cin >> z;

    file << "��������� ������� s_calculation: " << s_calculation(x, y, z) << "." << endl;

    // ������ b � ������� �������
    int b;
    cout << "������ b: ";
    cin >> b;

    file << "����� " << b << " � ������� ������: " << IntToBinaryString(b) << ".\n\n";

    file.close();

    cout << "��� ���� �������� � ���� input.txt\n\n";
}
