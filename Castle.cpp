#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> P(n+1);
    for(int i = 1; i <= n; i++){
        cin >> P[i];
    }

    if (n == 1){
        cout << P[1];
        return 0;
    }

    vector<long long> dp(n+1);
    dp[1] = P[1];
    dp[2] = max(P[1] + P[2], P[1] * P[2]);

    for (int i = 3; i <= n; i++){
        dp[i] = max(dp[i-1] + P[i], dp[i-2] + P[i-1] * P[i]);
    }

    cout << dp[n];

    return 0;
}