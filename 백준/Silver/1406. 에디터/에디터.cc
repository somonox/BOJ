#include<iostream>
#include<stack>
#include<queue>

using namespace std;

string str;
stack<char> left_hehe;
stack<char> right_hehe;
stack<char> tmp_hehe;
int qnum;
int i;

int main() {
    cin >> str;
    cin >> qnum;

    for (i = 0; i < str.length(); i++)
        left_hehe.push(str.at(i));

    for (i = 0; i < qnum; i++) {
        char cmd;
        char tmp;
        cin >> cmd;

        switch(cmd) {
            case 'L':
                if (left_hehe.empty())
                    continue;
                right_hehe.push(left_hehe.top());
                left_hehe.pop();
                break;
            case 'D':
                if (right_hehe.empty())
                    continue;
                left_hehe.push(right_hehe.top());
                right_hehe.pop();
                break;
            case 'B':
                if (left_hehe.empty())
                    continue;
                left_hehe.pop();
                break;
            case 'P':
                cin >> tmp;
                left_hehe.push(tmp);
                break;
        }
    }
    while(!left_hehe.empty()){
        tmp_hehe.push(left_hehe.top());
        left_hehe.pop();
    }

    while(!tmp_hehe.empty()){
        cout << tmp_hehe.top();
        tmp_hehe.pop();
    }

    while(!right_hehe.empty()){
        cout << right_hehe.top();
        right_hehe.pop();
    }



    return 0;
}