#include<stack>
#include<queue>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string a;
string formated;
queue<string> tag;
queue<string> reved;
int i;

int main() {
    getline(cin,a);

    for (i = 0; i < a.length(); i++) {
        string tagy;
        string backticks;
        if (a[i] == '<') {
            while (a[++i] != '>') {
                tagy.push_back(a[i]);
            }
            tagy = '<' + tagy + '>';
            tag.push(tagy);
            formated += '~';
        } else {
            formated += '`';
            while (i < a.length() && a[i] != '<') {
                backticks.push_back(a[i]);
                i += 1;
                if (a[i] == ' ') {
                    backticks.insert(backticks.begin(),' ');
                    i += 1;
                    break;
                }
            }
            i--;
            reverse(backticks.begin(), backticks.end());
            reved.push(backticks);
        }
    }

    for (char a: formated) {
        if (a == '`') {
            cout << reved.front();
            reved.pop();
        } else {
            cout << tag.front();
            tag.pop();
        }
    }

    return 0;
}