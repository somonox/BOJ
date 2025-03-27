#include<iostream>
#include<stack>

using namespace std;

int num;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        stack<char> s;
        string str;
        cin >> str;
        bool flag = true;

        for (char c : str) {
            if (c == '(')
                s.push(c);
            else if (c == ')') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                s.pop();
            }
        } 
        
        if (s.empty() && flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}