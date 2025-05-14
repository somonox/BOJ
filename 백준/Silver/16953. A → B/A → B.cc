// 그리디 해법
// #include<iostream>
// #include<vector>
// #include<climits>

// using namespace std;

// vector<int> dp;
// bool flag = true;
// unsigned long long n, m, c;
// unsigned long long i;

// int main() {
//     cin >> n >> m;

//     for (i = m; i >= n; i--) {
//         if (m == n) {
//             flag = false;
//             break;
//         }

//         if (m % 10 == 1)
//             m /= 10;
//         else if (m % 2 == 0)
//             m /= 2;
        
//         c++;
//     }
//     if (flag)
//         cout << "-1" << endl;
//     else
//         cout << c + 1 << endl;

//     return 0;
// }

// 그래프
#include<iostream>
#include<queue>
#include<map>

using namespace std;

queue<pair<unsigned long long, unsigned long long>> q;
map<unsigned long long, bool> ch;
unsigned long long a, b;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> a >> b;
    q.push({a, 1});
    while (!q.empty()) {
        unsigned long long fr = q.front().first;
        unsigned long long cnt = q.front().second;
        q.pop();

        if (fr == b) {
            cout << cnt << endl;
            return 0;
        }
        if(fr > b)
            continue;
        
        q.push({fr * 2, cnt + 1});
        q.push({fr * 10 + 1, cnt + 1});
    }

    cout << -1 << endl;

    return 0;
}