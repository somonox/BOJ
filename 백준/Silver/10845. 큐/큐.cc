#include<iostream>
#include<queue>

using namespace std;

queue<int> s;
int num;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if (cmd == "pop") {
            if (s.empty())
                cout << -1 << endl;
            else {
                cout << s.front() << endl;
                s.pop();
            }
        }
        else if (cmd == "front") {
            if (s.empty())
                cout << -1 << endl;
            else 
                cout << s.front() << endl;
        }
        else if(cmd == "back") {
            if (s.empty())
                cout << -1 << endl;
            else 
                cout << s.back() << endl;
        }
        else if(cmd == "size")
            cout << s.size() << endl;
        else if(cmd == "empty")
            cout << s.empty() << endl;
    }

    return 0;
}