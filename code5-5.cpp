#include<iostream>
#include<vector>
using namespace std;

// Frog問題に対する再帰関数を用いる単純な全探索
// ただし、余計な計算を何回も行うため、指数的に計算時間が増加してしまうため良くない

// rec(i): 足場0から足場iに至るまでの最小コスト

template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}


const long long INF = 1LL << 60;

long long rec(int i){
    // 足場0のコストは0
    if(i == 0) return 0;

    // 答えを格納する変数をINFに初期化する
    long long res = INF;

    // 頂点i-1から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 頂点i - ２から来た場合
    if(i > 1) chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

    // 答えを返す
    return ans;

}
