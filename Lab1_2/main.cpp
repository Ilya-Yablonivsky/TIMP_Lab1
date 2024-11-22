#include "modAlphaCipher.h"

using namespace std;

bool isValid(const wstring& s)
{
    for(const auto &c:s)
    {
        if (!iswalpha(c))
        {
            return false;
        }
    }
    return true;		
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    unsigned op;
    cout << "Input key: ";
    wcin >> key;
    if (!wcin.good()) {
        wcerr << "Error\n";
        return 1;
    }
    modAlphaCipher cipher(key);
    do {
        wcout << L"Enter the operation (1-encrypt, 2-decrypt, 0-exit): ";
        wcin >> op;

        if (op == 0) {
            break; // Выход из программы
        } else if (op > 2) {
            wcout << L"Error: Invalid operation. Please enter 1, 2 or 0.\n";
        } else if (op > 0) {
            wcout << L"Input text: ";
            wcin >> text;
            if (isValid(text)) {
                if (op == 1) {
                    wcout << L"Encrypt text:  " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Decrypt text: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Error: Invalid text. Only alphabetic characters are allowed.\n";
            }
        }
    } 
    while (true); // Бесконечный цикл, завершающийся при вводе 0
    return 0;
}
