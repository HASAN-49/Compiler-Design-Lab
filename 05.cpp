/* Lexical analyzer of a regular exprssion :
   Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
   Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
   Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
   Invalid Input or Undefined = Otherwise
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("05_input.txt", "r", stdin);
    string word;

    while (getline(cin, word)) {
        bool is_valid = true;
        int n = word.size();
        char ch = tolower(word[0]);
        if ((ch >= 'a' && ch <= 'h') || (ch >= 'o' && ch <= 'z')) {
            for (int i = 1; i < n; i++) {
                ch = tolower(word[i]);
                if ((ch >= 'a' && ch <= 'z') || (isdigit(ch))) continue;
                else {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) cout << "Float Variable\n";
        }
        else if (isdigit(ch)) {
            int dot_count = 0, digit_after_dot = 0;
            for (int i = 1; i < n; i++) {
                if (dot_count == 1) digit_after_dot++;
                if (word[i] == '.') dot_count++;
                if (dot_count == 2 || (!isdigit(word[i]) && word[i] != '.')) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                if (digit_after_dot == 2) cout << "Float Number\n";
                if (digit_after_dot > 2) cout << "Double Number\n";
                else is_valid = false;
            }
        }
        else {
            is_valid = false;
        }
        if (!is_valid) cout << "Invalid Input or Undefined\n";
    }
}
