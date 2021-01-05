#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 再帰関数を用いる深さ優先探索の実装の基本形

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true; // vを訪問済みにする

    // vから行ける各頂点next_vについて
    for(auto next_v : G[v]){
        if(seen[next_v]) continue; // next_vが探索済みならば探索しない
        dfs(G, next_v); // 再帰的に探索
    }
}

int main(){
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受付（ここではグラフを想定）
    Graph G(N);
    for(int i = 0; i < M; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false); // 初期状態では全頂点が未訪問
    for(int v = 0; v < N; ++v){
        if(seen[v]) continue; // すでに訪問済みなら探索しない
        dfs(G, v);
    }
}
