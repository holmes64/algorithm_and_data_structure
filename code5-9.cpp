#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T&a, T b){
    if(a > b){
        a = b;
    }
}

const long long INF = 1LL << 60;

int main(){
    // input
    int N; cin >> N;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            cin >> c[i][j];
        }
    }

    // DP table definition
    vector<long long> dp(N+1, INF);

    // DP initialize
    dp[0] = 0;

    // DP loop
    for(int i=0; i<=N; ++i){
        for(int j=0; j<=N; ++j){
            chmin(dp[i], dp[j] + c[i][j]);
        }
    }

    // output
    cout << dp[N] << endl;
}

