/*
Write a program that converts the C++ statement to an intermediate code of 
Post-fix notation form.
*/

#include<bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '/' || ch == '*') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> stk;
    string p = "";

    for (auto ch: s) {
        if (isalnum(ch)) p += ch;
        else if (ch == '(') stk.push(ch);
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                p += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (!stk.empty() && precedence(stk.top()) >= precedence(ch)) {
                p += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        p += stk.top();
        stk.pop();
    }

    return p;
}

string solve(string s) {
    stack<string> stk;
    string tmp = "", ans = "";

    for (auto ch: s) {
        if (ch != ' ') {
            tmp += ch;
        }
        else {
            if (tmp == "then") {
                tmp = "";
                continue;
            }
            if (tmp == "if" || tmp == "else") {
                stk.push(tmp);
                tmp = "";
            }
            else {
                ans += infixToPostfix(tmp);
                while (!stk.empty() && stk.top() == "else") {
                    ans += '?';
                    stk.pop();
                    stk.pop();
                }
                tmp = "";
            }
        }
    }

    return ans;
}

int32_t main() {
    string str;
    getline(cin, str);
    str += ' ';
    string ans = solve(str);
    cout << ans << '\n';
    return 0;
}
