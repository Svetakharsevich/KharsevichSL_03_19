// Modul3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include<list>
#include <vector>
#include <algorithm>
class Sport {
public:
    string FIO;
    string Data;
    string Discharge;
    string Year;
};
void Display() {
    Sport sport1 = Sport();
    cout << "Введите ФИО" << endl;
    cin >> sport1.FIO;
    cout << "Введите год рождения" << endl;
    cin >> sport1.Data;
    cout << "Введите разряд" << endl;
    cin >> sport1.Discharge;
    cout << "Введите количество лет в спорте" << endl;
    cin >> sport1.Year;
    ofstream file("info.txt");
    if (file.is_open()) {
       cout << sport1.FIO +"\n" + sport1.Data +
           "\n" + sport1.Discharge +
           "\n" + sport1.Year + "\n";
        file.close();
    }
}
void Sort() {
    ifstream file("info.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            sort(line.begin(), line.end(), [](const Sport& a, const Sport& b) {
                return a.Year > b.Year;
                });
            cout << line << "\n";
        }
    }
        
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Вывод информации из файла" << endl;
    ifstream file("info.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << "Без сортировки" << "\n";
            cout << line<<"\n";
        }
        file.close();
    }
    cout << "Сортировка" << "\n";
    Sort();
}

