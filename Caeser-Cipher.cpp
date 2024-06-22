#include <iostream>
#include <string>

using namespace std;

// ANSI color codes for text formatting
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

string caesarCipher(const string& text, int shift, char option) {
    string result = "";

    shift = shift % 26;
    if (shift < 0) {
        shift += 26;
    }

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted_char = static_cast<char>((c - base + shift) % 26 + base);

            if (option == 'd') {
                encrypted_char = static_cast<char>((c - base - shift + 26) % 26 + base);
            }

            result += encrypted_char;
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    cout << BLUE << "===> Caesar Cipher" << RESET << endl;
    cout << YELLOW << "Choice 'e' for encryption." << endl;
    cout << "Choice 'd' for decryption." << RESET << endl;

    string text;
    cout << "Enter text: ";
    getline(cin, text);

    int shift;
    cout << "Enter shift: ";
    cin >> shift;

    char option;
    cout << "Enter your choice: ";
    cin >> option;

    if (option != 'e' && option != 'd') {
        cout << RED << "Invalid option. Please enter 'e' or 'd'." << RESET << endl;
        return 1;
    }
    else if (option == 'e') {
        cout << GREEN << "Encrypted text: " << caesarCipher(text, shift, option) << RESET << endl;
    }
    else if (option == 'd') {
        cout << GREEN << "Decrypted text: " << caesarCipher(text, shift, option) << RESET << endl;
    }

    return 0;
}
