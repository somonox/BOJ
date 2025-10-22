#include<bits/stdc++.h>

using namespace std;


queue<pair<int, int>> q;
int visited[100001];
int n, k, lowest = INT_MAX, cnt;

int main() {
    cin >> n >> k;
    q.push(make_pair(n, 0));

    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        visited[x] = 1;

        if(lowest < y) break;

        if(x == k) {
            lowest = y;
            cnt++;
            continue;
        }


        if(x+1<=100000 && !visited[x+1]) q.push({x+1, y+1});
        if(x*2<=100000 && !visited[x*2]) q.push({x*2, y+1});
        if(x-1>=0 && !visited[x-1]) q.push({x-1, y+1});
    }
    cout << lowest << endl;
    cout << cnt;

    return 0;
}