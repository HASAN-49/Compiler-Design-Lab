// The program counts the  number of words, letters, digits and other characters. It also separates letters, digits and other characters

#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main() {
    string s; getline(cin, s); // sample = Md. Tarek Zaman, Part-3, 2011
    int n = s.size();
    vector<char> ch, dig, oth;
    cout << s << endl;
    int words = 0, cnt = 0, letters = 0, digits = 0, others = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            cnt++;
            letters++;
            ch.push_back(s[i]);
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            digits++;
            dig.push_back(s[i]);
        }
        else if (s[i] == ' ') {
            if (cnt > 0) {
                words++;
            }
            cnt = 0;
        }
        else {
            others++;
            oth.push_back(s[i]);
        }
    }
    cout << words << ' ' << letters << ' ' << digits << ' ' << others << '\n';
    for (auto x: ch) cout << x << ' '; cout << '\n';
    for (auto x: dig) cout << x << ' '; cout << '\n';
    for (auto x: oth) cout << x << ' '; cout << '\n';

    return 0;
}
