/*
Write a program to generate a syntax tree for the sentence a+b*c with the following 
grammar: E —> E+E|E-E|E*E|E/E|(E)|a|b|c 
*/

#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '/' || op == '*') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix_prime(string s) {
    stack<char> stk;
    string p = "";
    for (auto ch: s) {
        if (isalnum(ch)) {
            p += ch;
        }
        else if (ch == '(') {
            stk.push(ch);
        }
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

struct node {
    char val;
    node *left, *right;

    node(char ch) {
        this->val = ch;
        this->left = NULL;
        this->right = NULL;
    }
};

node *perser(string s) {
    stack<node*> stk;
    for (auto ch: s) {
        if (isalnum(ch)) {
            node *n = new node(ch);
            stk.push(n);
        }
        else {
            node *n = new node(ch);
            n->right = stk.top();
            stk.pop();
            n->left = stk.top();
            stk.pop();
            stk.push(n);
        }
    }
    return stk.top();
}

void print(node *root, int space = 0, int indent = 4) {
    if (root == NULL) return;
    space += 4;
    print(root->right, space);
    cout << '\n';
    for (int i = 0; i < space - 4; i++) {
        cout << ' ';
    }
    cout << root->val;
    print(root->left, space);
}

int32_t main() {
    string s;
    getline(cin, s);
    s = infixToPostfix_prime(s);
    node *tree = perser(s);
    print(tree);
    return 0;
}
