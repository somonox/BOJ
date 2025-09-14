#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge {
    double weight;
    int to;
    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }
};

double calc_dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

vector<pair<double,double>> stars;
vector<vector<Edge>> graph;
vector<bool> inMST;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
double totalWeight = 0.0;
int picked = 0;
int n;
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    stars.resize(n);
    graph.resize(n);

    for (i = 0; i < n; i++)
        cin >> stars[i].first >> stars[i].second;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double d = calc_dist(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
            graph[i].push_back({d, j});
            graph[j].push_back({d, i});
        }
    }

    inMST.resize(n);

    pq.push({0.0, 0});

    while (!pq.empty() && picked < n) {
        auto [w, u] = pq.top();
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;
        picked++;
        totalWeight += w;

        for (auto &e : graph[u])
            if (!inMST[e.to])
                pq.push(e);
    }

    cout << fixed << setprecision(2) << totalWeight;
    return 0;
}
