#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

// ナップサック問題に対する動的計画法

int main(){

    // input
    int N; long long W;
    cin >> N >> W;
    vector<long long> weight(N), value(N);
    for(int i=0; i<N; i++) cin >> weight[i] >> value[i];

    // DPテーブル
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    // DP loop
    for(int i=0; i<N; ++i){
        for(int w=0; w <= W; ++w){
            // i番目の品物を選ぶ場合
            if(w - weight[i] >= 0){
                chmax(dp[i+1][w], dp[i][w - weight[i]] + value[i]);
            }

            // i番目の品物を選ばない場合
            chmax(dp[i+1][w], dp[i][w]);
        }
    }

    // output
    cout << dp[N][W] << endl;

}

