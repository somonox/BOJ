#include<iostream>
#include<vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<pair<long long, long long>> v;
long long num, sum;
int i;

int main() {
    fastio;
    cin >> num;

    for (i = 0; i < num; i++) {
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (i = 0; i < v.size(); i++) {
        sum += v[i].first * v[(i + 1) % v.size()].second;
        sum -= v[i].second * v[(i + 1) % v.size()].first;
    }
    sum = abs(sum);
    long double area = (long double)sum / 2;
    printf("%.1Lf", area);

    return 0;
}