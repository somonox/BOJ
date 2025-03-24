#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
int num;
int i;

int main() {
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp == 0) {
            if (pq.empty())
                printf("0\n");
            else {
                printf("%d\n", -pq.top());
                pq.pop();
            }
        }else
            pq.push(-tmp);
    }

    return 0;
}