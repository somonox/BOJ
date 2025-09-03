#include<iostream>
#include<stack>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    string str;
    while (getline(cin, str)) {
        if (str == ".")
            break;
        bool ok = true;
        stack<char> st;
        for (char c : str) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else if (c == ')' || c == '}' || c == ']') {
                if (st.empty() || st.top() != c) { ok = false; break; }
                st.pop();
            }
        }
        cout << ((ok && st.empty()) ? "yes" : "no") << '\n';
    }
    return 0;
}
