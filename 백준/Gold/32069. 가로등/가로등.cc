#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<climits>

using namespace std;
using ull = unsigned long long;

priority_queue<ull> bests;
unordered_map<ull,ull> visited;
ull l, n, k;
ull i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> l >> n >> k;
    queue<pair<ull, ull>> q;

    for (i = 0; i < n; i++) {
        ull tmp;
        cin >> tmp;
        q.push({tmp, 0});
        visited[tmp] = 0;
    }

    for (i = 0; i < k; i++) {
        bests.push(ULLONG_MAX);
    }

    while (!q.empty()) {
        pair<ull, ull> front = q.front();
        if (front.second > k) {
            break;
        }
        q.pop();
        
        if (visited.contains(front.first) && visited[front.first] < bests.top()) {
            bests.push(visited[front.first]);
            if (bests.size() > k)
                bests.pop();
        }
        
        if (!visited.contains(front.first + 1) && front.first < l) {
            q.push({front.first + 1, front.second + 1});
            visited[front.first + 1] = visited[front.first] + 1;
        }
      
        if (!visited.contains(front.first - 1) && front.first > 0) {
            q.push({front.first - 1, front.second + 1});
            visited[front.first - 1] = visited[front.first] + 1;
        }
    }

    stack<ull> rev;
    while (!bests.empty()) {
        if (bests.top() != ULLONG_MAX) {
            rev.push(bests.top());
        }
        bests.pop();
    }

    while (!rev.empty()) {
        cout << rev.top() << "\n";
        rev.pop();
    }

    return 0;
}