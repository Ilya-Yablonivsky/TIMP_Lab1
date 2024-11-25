#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>

using namespace std;

class TableCipher
{
private:
    wstring numAlpha = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //алфавит по порядку
    map <wchar_t,int> alphaNum; //ассоциативный массив "номер по символу"
    int newkey;
    
public:
    TableCipher()=delete; //Запрет конструктора без параметров
    TableCipher(const int& key) :newkey(key) {}; //Конструктор для ключа

    wstring encrypt(const wstring& open_text);//зашифрование
    wstring decrypt(const wstring& cipher_text);//расшифрование
};
