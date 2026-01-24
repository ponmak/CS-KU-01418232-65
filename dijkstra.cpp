#include<iostream>
#include <vector>
#include<queue>

using namespace std;

int main(){
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(adj.size(), INT_MAX);
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();

        if (du > dist[u]) continue;

        for (auto &p : adj[u]){
            int v = p.first; 
            int w = p.second; 


            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
                pq.emplace(dist[v], v);
            }
        }
    }

    if (dist[u] == INT_MAX){
        cout << "impos"
        return 0;
    }



    
}