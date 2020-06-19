#pragma once
#include <iostream>
#include <cstring>

class MyString
{
public:
    MyString(const char* source);
    char* word;
    int size;
    void clear();
    void toUpper();


};