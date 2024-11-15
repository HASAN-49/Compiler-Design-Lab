/*
Write a program which converts a word of C++ program to its equivalent token.
RESULT:
Input: 646.45
Output: Float
Input: do
Output: Keyword
Input: 554
Output: Integer
Input: abc
Output: Identifier
Input: +
Output: Arithmetic Operator
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> keywords = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
                     "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
                     "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
                     "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
                     "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
                     "false", "float", "for", "friend", "goto", "if", "import", "inline", "include", "int",
                     "long", "module", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
                     "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
                     "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
                     "static_assert", "static_cast", "struct", "switch", "synchronized", "template",
                     "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename",
                     "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while",
                     "xor", "xor_eq"};

vector<string> arithmetic_operators = {"+", "-", "*", "/", "%"};
vector<string> relational_operators = {"==", "!=", "<", ">", "<=", ">="};
vector<string> logical_operators = {"&&", "||", "!"};
vector<string> bitwise_operators = {"&", "|", "^", "~", "<<", ">>"};
vector<string> assignment_operators = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};
vector<string> increment_decrement_operators = {"++", "--"};

void print(string s, string ans) {
    cout << s << " : " << ans << '\n';
}

int main() {
    freopen("08_input.txt", "r", stdin);
    string s;
    while (getline(cin, s)) {
        int n = s.size();
        bool isValid = true;
        if (find(keywords.begin(), keywords.end(), s) != keywords.end()) {
            print(s, "Keywords");
        }
        else if (find(arithmetic_operators.begin(), arithmetic_operators.end(), s) != arithmetic_operators.end()) {
            print(s, "Arithmatic Operator");
        }
        else if (find(relational_operators.begin(), relational_operators.end(), s) != relational_operators.end()) {
            print(s, "Relational Operator");
        }
        else if (find(logical_operators.begin(), logical_operators.end(), s) != logical_operators.end()) {
            print(s, "Logical Operator");
        }
        else if (find(bitwise_operators.begin(), bitwise_operators.end(), s) != bitwise_operators.end()) {
            print(s, "Bitwise Operator");
        }
        else if (find(assignment_operators.begin(), assignment_operators.end(), s) != assignment_operators.end()) {
            print(s, "Assignment Operator");
        }
        else if (find(increment_decrement_operators.begin(), increment_decrement_operators.end(), s) != increment_decrement_operators.end()) {
            print(s, "Increment or Decrement Operator");
        }
        else if (s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
            for (int i = 1; i < n; i++) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] <= 'Z') || isdigit(s[i])) continue;
                isValid = false;
                break;
            }
            if (isValid) print(s, "Identifier");
        }
        else if (s[0] == '"' && s[n-1] == '"') print(s, "String Literal");
        else if (isdigit(s[0]) || s[0] == '.') {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (isdigit(s[i])) continue;
                if (!cnt && s[i] == '.') {
                    cnt++;
                    continue;
                }
                isValid = false;
                break;
            }
            if (isValid) {
                if (!cnt) print(s, "Integer");
                else print(s, "Float");
            }
        }
        else isValid = false;
        if (!isValid) print(s, "InvalidInput");
    }
}
