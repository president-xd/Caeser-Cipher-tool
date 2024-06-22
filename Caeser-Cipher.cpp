#include <iostream>
#include <string>

using namespace std;

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

    cout << "Welcome to President's Caesar Cipher" << endl;
    cout << "Choice e for encryption." << endl;
    cout << "Choice d for decryption." << endl;

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
        cout << "Invalid option. Please enter 'e' or 'd'.";
        return 1;
    }
    else if (option == 'e') {
        cout << "Encrypted text: " << caesarCipher(text, shift, option) << endl;
    }
    else if (option == 'd') {
        cout << "Decrypted text: " << caesarCipher(text, shift, option) << endl;
    }


    return 0;
}
