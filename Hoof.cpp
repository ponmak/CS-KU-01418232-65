#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int s, d;
    cin >> s >> d;

    int N = (1 << 20);
    vector<vector<pair<int,int>>> adj(N);

    int u, v, w;
    while (cin >> u >> v >> w) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(N, INT_MAX);
    vector<int> cnt(N, 0);        
    vector<int> parent(N, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[s] = 0;
    cnt[s] = 1;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            int newDist = dist[u] + w;
            int newCnt  = cnt[u] + 1;

            if (newDist < dist[v] || (newDist == dist[v] && newCnt > cnt[v])) {
                dist[v] = newDist;
                cnt[v] = newCnt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[d] == INT_MAX) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    for (int cur = d; cur != -1; cur = parent[cur])
        path.push_back(cur);

    for (int l = 0, r = path.size() - 1; l < r; l++, r--) {
        int tmp = path[l];
        path[l] = path[r];
        path[r] = tmp;
    }

    for (int x : path)
        cout << x << " ";
}
