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
    wstring numAlpha = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alphabet in order
    map <wchar_t,int> alphaNum; // associative array "number by character"
    int newkey;
public:
    modAlphaCipher()=delete; //Запрет конструктора без параметров
    
    modAlphaCipher(const int& key) :newkey(key) {}; //Конструктор для ключа

    wstring encrypt(const wstring& open_text);

    wstring decrypt(const wstring& cipher_text);
};
