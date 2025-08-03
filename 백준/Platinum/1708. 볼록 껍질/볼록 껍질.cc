#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> v;
stack<int> findst;
int vtxnum;
int i;

bool cmpy(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
}

long long powdist(pair<ll, ll> a, pair<ll, ll> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}


bool cmpAngle(pair<ll, ll> a, pair<ll, ll> b) {
    long long clockwise = ccw(v[0], a, b);
    if (clockwise) return clockwise > 0;
    return powdist(a, v[0]) < powdist(b, v[0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> vtxnum;

    for (i = 0; i < vtxnum; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), cmpy);
    sort(v.begin() + 1, v.end(), cmpAngle);

    findst.push(0);
    findst.push(1);

    for (i = 2; i < vtxnum; i++) {
        while (findst.size() > 1) {
            int second = findst.top();
            findst.pop();
            int first = findst.top();
            if (ccw(v[first], v[second], v[i]) > 0) {
                findst.push(second);
                break;
            }
        }
        findst.push(i);
    }

    cout << findst.size() << endl;


    return 0;
}