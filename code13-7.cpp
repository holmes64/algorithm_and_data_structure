#include <iostream>
#include <vector>
using Graph = vector<vector<int>>;

// 根なし木の走査の実装の基本形

// 木上の探索
// v: 現在探索中の頂点、p: vの親(vが根のときはp = -1)
void dfs(const Graph &G, int v, int p = -1){
    for(auto c : G[v]){
        if(c == p) continue; // 探索が親方向へ逆流するのを防ぐ

        // cはvの各子頂点を動く、このときcの親はvとなる
        dfs(G, c, v);
    }
}
