#include<iostream>
#include<queue>

using namespace std;

priority_queue<unsigned long long> pq;
int num;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        unsigned long long tmp;
        scanf("%lld", &tmp);

        if (tmp == 0) {
            if (pq.empty()) {
                printf("0\n"); 
                continue;
            } 

            printf("%lld\n", pq.top());
            pq.pop();
        } else 
            pq.push(tmp);
    }

    return 0;
}