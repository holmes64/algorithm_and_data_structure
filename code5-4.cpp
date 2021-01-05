#include <iostream>
#include <vector>
using namespace std;

// 配る遷移形式で問題を解いた場合

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

const long long INF = 1LL << 50;

int main(){
    // input
    int N; cin >> N;
    vector<long long> h(N);
    for(int i=0; i<N; i++) cin >> h[i];

    // initialize
    vector<long long> dp(N, INF);

    dp[0] = 0;

    // loop
    for(int i=0; i<N; ++i){
        if(i+1 < N){
            chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        }
        if(i+2 < N){
            chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
        }
    }

    cout << dp[N-1] << endl;
}



