/*
    Write a program to implement a shift reducing parsing.
*/

// #include <bits/stdc++.h>
// using namespace std;

// class ShiftReduceParser {
// private:
//     unordered_map<string, vector<vector<string>>> grammar; // Grammar rules
//     deque<string> stack; // Parsing stack
//     vector<string> input; // Input tokens

//     // Check if the top of the stack matches a production rule
//     bool canReduce(string &reducedTo) {
//         for (const auto &rule : grammar) {
//             for (const auto &body : rule.second) {
//                 if (stack.size() >= body.size()) {
//                     // Check if the top of the stack matches the rule body
//                     bool match = true;
//                     for (size_t i = 0; i < body.size(); ++i) {
//                         if (stack[stack.size() - body.size() + i] != body[i]) {
//                             match = false;
//                             break;
//                         }
//                     }
//                     if (match) {
//                         // Perform reduction
//                         for (size_t i = 0; i < body.size(); ++i) stack.pop_back();
//                         stack.push_back(rule.first);
//                         reducedTo = rule.first;
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }

// public:
//     ShiftReduceParser() {
//         // Define grammar rules
//         grammar["E"] = {{"E", "+", "E"}, {"E", "*", "E"}, {"id"}};
//     }

//     void parse(vector<string> tokens) {
//         input = tokens;
//         cout << "Stack               Input               Action" << '\n';

//         while (true) {
//             // Display the current stack and input
//             string stackStr, inputStr;

//             // Constructing stackStr
//             for (const auto &s : stack) stackStr += s + " ";

//             // Constructing inputStr
//             for (const auto &s : input) inputStr += s + " ";

//             // Manually format output to simulate setw(20)
//             int stackWidth = 20, inputWidth = 20;
//             while (stackStr.length() < stackWidth) stackStr += " ";
//             while (inputStr.length() < inputWidth) inputStr += " ";

//             cout << stackStr << inputStr;

//             // Try to reduce the stack
//             string reducedTo;
//             if (canReduce(reducedTo)) {
//                 cout << "REDUCE " << reducedTo << endl;
//                 continue;
//             }

//             // If reduction is not possible, try to shift
//             if (!input.empty()) {
//                 stack.push_back(input.front());
//                 input.erase(input.begin());
//                 cout << "SHIFT" << endl;
//             } else {
//                 // If input is empty, check for acceptance or error
//                 if (stack.size() == 1 && stack.front() == "E") {
//                     cout << "ACCEPT" << endl;
//                 } else {
//                     cout << "ERROR" << endl;
//                 }
//                 break;
//             }
//         }
//     }
// };

// int main() {
//     // Tokens for the expression: id + id * id
//     vector<string> tokens = {"id", "+", "id", "*", "id"};

//     // Create the parser
//     ShiftReduceParser parser;

//     // Parse the tokens
//     parser.parse(tokens);

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

map<string, string> rules;
string stk = "", input;

void reduce() {
    for (auto rule: rules) {
        if (stk.find(rule.first) != -1) {
            int position = stk.find(rule.first);
            stk.erase(position); // Remove the right side of the production
            stk += rule.second; // Add the left side of the production
            cout << left << setw(20) << "$" + stk << left << setw(15) << input + "$" << right << setw(10) << "REDUCE " << rule.second << "->" << rule.first << '\n';
            reduce();
        }
    }
}

int main() {
    freopen("10_input.txt", "r", stdin);

    // n = number od production rules
    int n; cin >> n;

    string production;
    cin.ignore();
    for (int i = 0; i < n; i++) { // Read the grammar
        getline(cin, production);
        // cout << production << '\n';
        // cout << production.substr(3) << ' ' << production[0] << '\n';
        rules[production.substr(3)] = production[0]; // Left side = production key, Right side = Value
    }

    getline(cin, input); // a+a*(a+a)+a

    cout << "Stack               Input               Action\n";
    cout << left << setw(20) << "$" + stk << right << setw(12) << input + "$" << '\n';

    while (!input.empty()) {
        stk += input[0]; // Push the terminal into stack
        input.erase(0, 1); // Remove the first character from input
        cout << left << setw(20) << "$" + stk << setw(15) << input + "$" << right << setw(10) << "SHIFT " << stk.back() << '\n';
        reduce();
    }

    if (stk == "E") cout << "ACCEPTED\n";
    else cout << "REJECTED\n";

    return 0;
}
