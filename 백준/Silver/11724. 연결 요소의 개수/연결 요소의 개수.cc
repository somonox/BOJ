#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> graph;
int num, vertex;
int gaesiu;
int ch[1024];
int i;

int main() {
    cin >> vertex >> num;
    graph.resize(vertex + 1);

    for (i = 0; i < num; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    for (i = 1; i <= vertex; i++) {
        if (ch[i] == 1)
            continue;
        gaesiu++;

        queue<int> q;
        q.push(i);
        ch[i] = 1;

        while (!q.empty()) {
            int qpv = q.front();
            q.pop();


            for (int j : graph[qpv]) {
                if (ch[j] == 1)
                    continue;
                q.push(j);
                ch[j] = 1;
            }
        }
    }

    cout << gaesiu << endl;

    return 0;
}