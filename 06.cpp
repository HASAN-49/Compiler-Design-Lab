/*
Program for Building a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)* 
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise
*/

#include <iostream>
#include <string>
using namespace std;

bool is_ok(char ch) {
    if (isdigit(ch)) return true;
    ch = tolower(ch);
    if (ch >= 'a' && ch <= 'z') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("05_input.txt", "r", stdin);
    string word;

    while (getline(cin, word)) {
        int n = word.size();
        bool is_valid = true;
        if (word[0] == 'c') {
            if (word[1] == 'h' && word[2] == '_') {
                int cnt = 0;
                for (int i = 3; i < n; i++) {
                    if (!is_ok(word[i])) {
                        is_valid = false;
                        break;
                    }
                    cnt++;
                }
                if (is_valid && cnt >= 1) cout << "Character variable\n";
                else is_valid = false;
            }
            else is_valid = false;
        }
        else if (word[0] == 'b') {
            if (word[1] == 'n' && word[2] == '_') {
                int cnt = 0;
                for (int i = 3; i < n; i++) {
                    if (!is_ok(word[i])) {
                        is_valid = false;
                        break;
                    }
                    cnt++;
                }
                if (is_valid && cnt >= 1) cout << "Binary variable\n";
                else is_valid = false;
            }
            else is_valid = false;
        }
        else if (word[0] == '0') {
            int binary_digit_counter = 0;
            for (int i = 1; i < n; i++) {
                if (word[i] == '0' || word[i] == '1') {
                    binary_digit_counter++;
                }
                else {
                    is_valid = false;
                    break;
                }
            }
            if (binary_digit_counter == 0) is_valid = false;
            if (is_valid) cout << "Binary Number\n";
        }
        else {
            is_valid = false;
        }
        if (!is_valid) cout << "Invalid Input or Undefined\n";
    }

    return 0;
}
