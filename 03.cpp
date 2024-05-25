// The program will abbreviates the subject code

#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<map>

using namespace std;

int main() {
    string s; getline(cin, s); // sample = CSE-3141
    int n = s.size();
    map<string, string> abbr;
    abbr["CSE"] = "Computer Science & Engineering";
    abbr["ICE"] = "Information & Communication Engineering";
    abbr["1"] = "Software Engineering";
    abbr["2"] = "Database Management System";
    abbr["3"] = "Web Engineering";
    abbr["4"] = "Compiler Design";
    abbr["5"] = "Engineering Ethics and Environment Protection";
    abbr["61"] = "Communication Engineering";
    abbr["62"] = "Mobile Application Development";

    string tmp = s.substr(0, 3);
    cout << abbr[tmp] << ", ";

    if (s[4] == '1') cout << "1st ";
    else if (s[4] == '2') cout << "2nd ";
    else if (s[4] == '3') cout << "3rd ";
    else cout << "4th ";
    cout << "year, ";
    
    if (s[5] == '1') cout << "1st ";
    else if (s[5] == '2') cout << "2nd ";
    else if (s[5] == '3') cout << "3rd ";
    else cout << "4th ";
    cout << "semester, ";

    tmp = s[6];
    if (tmp == "6") tmp += s[7];
    cout << abbr[tmp] << ", ";

    if (s[7] == '1') cout << "Theory.\n";
    else cout << "Lab.\n";

    return 0;
}
