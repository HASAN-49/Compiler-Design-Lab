// Lexical analyzer of a regular expression

#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main() {
    freopen("04_input.txt", "r", stdin);
    string word;

    while (getline(cin, word)) {
        string ans = "InvalidInputOrUndefined";
        bool is_valid = true;
        int n = word.length();
        char ch = tolower(word[0]);
        if (ch >= 'i' && ch <= 'n') {
            for (int i = 0; i < n; i++) {
                ch = tolower(word[i]);
                if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                    continue;
                }
                else {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) ans = "IntegerNumber";
        }
        else if (ch >= '1' && ch <= '9') {
            int cnt = 1;
            for (int i = 0; i < n; i++) {
                ch = word[i];
                if (ch >= '0' && ch <= '9') {
                    cnt++;
                }
                else {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                if (cnt <= 4) ans = "ShortIntNumber";
                else ans = "LongIntNumber";
            }
        }
        else {
            is_valid = false;
        }
        cout << ans << endl;
    }

    return 0;
}
