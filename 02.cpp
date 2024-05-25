// This program will counts the number of vowels and consonants, will find which voewels and consonants are existed. It will alse devide into two strings where one will contains the word started with vowels and another will contains the word contains with consonant

#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<set>

using namespace std;

bool is_vowel(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
    return false;
}

int main() {
    string s; getline(cin, s); // sample = Munmun is the student of Computer Science & Engineering
    int n = s.size();
    cout << s << endl;
    int vowel = 0, consonant = 0;
    set<char> ch, vow, cons;
    vector<string> vw, cw;
    string tmp = "";
    for (int i = 0; i < n; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            tmp += s[i];
            char si = tolower(s[i]);
            if(is_vowel(si)) {
                vowel++;
                vow.insert(si);
            }
            else {
                consonant++;
                cons.insert(si);
            }
        }
        else {
            if (tmp.size() > 0) {
                if (is_vowel(tolower(tmp[0]))) vw.push_back(tmp);
                else cw.push_back(tmp);
            }
            tmp = "";
        }
    }
    if (tmp.size() > 0) {
        if (is_vowel(tolower(tmp[0]))) vw.push_back(tmp);
        else cw.push_back(tmp);
    }

    cout << vowel << ' ' << consonant << '\n';
    for (auto x: vow) cout << x << ' '; cout << '\n';
    for (auto x: cons) cout << x << ' '; cout << '\n';

    for (auto x: vw) cout << x << ' '; cout << '\n';
    for (auto x: cw) cout << x << ' '; cout << '\n';

    return 0;
}
