#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void tarjanDFS(int u, vector<vector<int>>& g, vector<int>& disc, vector<int>& low, vector<bool>& inStack, 
    stack<int>& st, vector<int>& sccSize, int& timer) {

    disc[u] = low[u] = timer++;
    st.push(u);
    inStack[u] = true;

    for (int v : g[u]) {
        if (disc[v] == 0) {
            tarjanDFS(v, g, disc, low, inStack, st, sccSize, timer);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        int cnt = 0;
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            cnt++;
            if (v == u) break;
        }
        sccSize.push_back(cnt);
    }
}

void find_scc(vector<vector<int>>& g, int v) {
    vector<int> disc(v, 0), low(v, 0);
    vector<bool> inStack(v, false);
    stack<int> st;
    vector<int> sccSize;
    int timer = 0;

    for (int i = 0; i < v; i++) {
        if (disc[i] == 0) {
            tarjanDFS(i, g, disc, low, inStack, st, sccSize, timer);
        }
    }

    sort(sccSize.begin(), sccSize.end(), greater<int>());

    for (int i = 0; i < 5; i++) {
        if (i < sccSize.size())
            cout << sccSize[i];
        else
            cout << 0;

        if (i < 4) cout << ",";
    }
    cout << "\n";
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> g(v);

    for (int i = 0; i < e; i++) {
        int s, p;
        cin >> s >> p;
        
        g[s - 1].push_back(p - 1);
    }

    find_scc(g, v);
    return 0;
}
