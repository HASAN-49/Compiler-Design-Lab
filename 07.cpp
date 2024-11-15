/*
    Write a program to recognize C++
    i) Keyword ii) Identifier iii) Operator iv) Constant
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

vector<string> operators = {
    "+", "-", "*", "/", "%",                                           // Arithmetic Operators
    "==", "!=", "<", ">", "<=", ">=",                                  // Relational Operators
    "&&", "||", "!",                                                   // Logical Operators
    "&", "|", "^", "~", "<<", ">>",                                    // Bitwise Operators
    "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", // Assignment Operators
    "++", "--",                                                        // Increment and Decrement Operators
    "?", ":",                                                          // Conditional Operator
    ",",                                                               // Comma Operator
    ".", "->",                                                         // Member Access Operators
    "::"                                                               // Scope Resolution Operator
};

void print(string s, string ans) {
    cout << s << ": " << ans << '\n';
}

int main() {
    freopen("07_input.txt", "r", stdin);
    string s;
    while (getline(cin, s)) {
        int n = s.size();
        bool isValid = true;
        if (find(keywords.begin(), keywords.end(), s) != keywords.end()) {
            print(s, "Keywords");
        }
        else if (find(operators.begin(), operators.end(), s) != operators.end()) {
            print(s, "Operator");
        }
        else if (s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
            for (int i = 1; i < n; i++) {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] <= 'Z') || isdigit(s[i])) continue;
                isValid = false;
                break;
            }
            if (isValid) print(s, "Identifier");
        }
        else if (s[0] == '"' && s[n-1] == '"') print(s, "Constant");
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
            if (isValid) print(s, "Constant");
        }
        else isValid = false;
        if (!isValid) print(s, "InvalidInput");
    }
}
