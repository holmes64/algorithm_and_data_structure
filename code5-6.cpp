#include <iostream>
#include <vector>
using namespace std;

// メモ化再帰を用いたFrog問題を解いた場合

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

const long long INF = 1LL << 60;

int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i){
    // DPの値が更新されていたらそのままリターン
    if(dp[i] < INF) return dp[i];

    // basecase: 足場0のコストは0
    if(i == 0) return 0;

    // 答えを出す変数をINFで初期化する
    long long res = INF;

    // 足場 i - 1　から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 足場 i - 2　から来た場合
    if(i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

    // 結果をメモしながら返す
    return dp[i] = res;
}


int main(){
    // input
    cin >> N;
    h.resize(N);
    for(int i=0; i<N; ++i) cin >> h[i];

    // initialize
    dp.assign(N, INF);

    // answer
    cout << rec(N - 1) << endl;
}
