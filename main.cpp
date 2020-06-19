#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    cout << "Выполнил студент группы 9005 Басилая Андрей Карлович"<<endl;
    cout << "Введите текст"<<endl;
    int size = 100;
    char str[size];
    cin.getline(str, size - 1);
    MyString* str1 = new MyString(str);
    str1->toUpper();
    cout << "Полученный текст:"<<endl;
    cout << str1->word << endl;

    return 0;
}