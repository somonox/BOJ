#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> v;
int ch[120044];
int nuguabujimohasino[100224];
int num;
int i;

int main() {
    cin >> num;
    v.resize(num + 1);

    for (i = 0; i < num - 1; i++) {
        int tmp1, tmp2;
        scanf("%d%d", &tmp1, &tmp2);
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    queue<int> q;
    q.push(1);
    ch[1] = 1;

    while(!q.empty()) {
        int aq = q.front();
        q.pop();

        for (int i : v[aq]) {
            if (ch[i] == 1)
                continue;
            q.push(i);
            ch[i] = 1;
            nuguabujimohasino[i] = aq;
        }
    }

    for (i = 2; i <= num; i++) {
        printf("%d\n", nuguabujimohasino[i]);
    }

    

    return 0;
}