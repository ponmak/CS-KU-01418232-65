#include<iostream>
#include<vector>
#include <iomanip>
#include <climits>

using namespace std;

int main(){

    int n;
    while (cin >> n){
        vector<string> codes;

        for (int i = 0; i <= n; i++){
            string x; cin >> x;
            codes.push_back(x);
        }

        int m = n + 1;

        vector<int> dist(m, INT_MAX);
        vector<bool> used(m, false);

        dist[0] = 0;   
        long long ans = 0;

        for (int i = 0; i < m; i++){
            int u = -1;
            for(int j = 0; j < m; j++){
                if(!used[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            used[u] = true;
            ans += dist[u];

            for (int j = 0; j < m; j++){
                if(!used[j]){
                    int cost = 0;

                    for(int k = 0; k < codes[u].size(); k++){
                        int d = abs(codes[u][k] - codes[j][k]);
                        cost += min(d, 10 - d);
                    }

                    if(cost < dist[j]) dist[j] = cost;
                }
            }
        }

        ans %= 100000;
        cout << setw(5) << setfill('0') << ans << endl;
    }

    return 0;
}
