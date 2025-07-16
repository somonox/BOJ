#include<iostream>
#include<set>

using namespace std;

char cmd;
int t, v, value;
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;

    for (i = 0; i < t; i++) {
        multiset<int> dpq;
        cin >> v;
        for (j = 0; j < v; j++) {
            cin >> cmd;
            cin >> value;
            if (cmd == 'I') {
                dpq.insert(value);
            } else {
                if (dpq.empty())
                    continue;
                if (value == -1)
                    dpq.erase(dpq.begin());
                else
                    dpq.erase(prev(dpq.end()));
            }
        }
        if (dpq.empty())
            cout << "EMPTY" << '\n';
        else
            cout << *prev(dpq.end()) << " " << *dpq.begin() << '\n';
    }

    return 0;
}