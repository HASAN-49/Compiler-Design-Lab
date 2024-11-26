/*
Write a program to build a lexical analyzer implementing the following regular 
expressions. It takes a text as input from a file (e.g. input.txt) and display output in 
console mode: E -> EAE|(E)|ID 
              A -> + | - | * | /
              ID -> any valid identifier | any valid integer 
*/

#include<bits/stdc++.h>
using namespace std;

bool isInteger(string s) {
    for (auto x: s) {
        if (x < '0' || x > '9') return false;
    }
    return true;
}

bool isValidIdentifier(string s) {
    // cout << s << "= ";
    if (s.size() == 0 || (!isalpha(s[0]) && s[0] != '_')) return false;
    for (auto ch: s) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    vector<string> keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "const_cast",
        "continue", "co_await", "co_return", "co_yield", "decltype", "default", "delete",
        "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern",
        "false", "float", "for", "friend", "goto", "if", "inline", "int", "long",
        "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator",
        "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
        "requires", "return", "short", "signed", "sizeof", "static", "static_assert",
        "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };
    if (find(keywords.begin(), keywords.end(), s) != keywords.end()) return false;
    return true;
}

int32_t main() {
    string inp;
    while (getline(cin, inp)) {
        bool isValid = true;
        int operators = 0;
        vector<string> operands;
        string operand;
        stack<char> stk;
        for (char ch: inp) {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (operand.size()) operands.push_back(operand);
                operand = "";
                operators++;
            }
            else {
                if (ch == '(') {
                    if (operand.size()) { // a(b+c) = invalid
                        isValid = false;
                        break;
                    }
                    stk.push(ch);
                }
                else if (ch == ')') {
                    if (!stk.empty() && operand.size()) {
                        stk.pop();
                    }
                    else {
                        isValid = false;
                        break;
                    }
                }
                else {
                    operand += ch;
                }
            }
        }

        if (operand.size()) operands.push_back(operand);

        for (auto operand: operands) {
            if (!isInteger(operand) && !isValidIdentifier(operand)) {
                isValid = false;
                break;
            }
        }
        // cout << operands.size() << ' ' << operators << "= ";

        if (isValid && operands.size() == operators + 1 && stk.empty()) {
            cout << inp << ": Valid\n";
        }
        else cout << inp << ": Invalid\n";
    }
    return 0;
}
