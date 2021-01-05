#include <iostream>
#include <vector>
using namespace std;

// フォード・ファルカーソン法

struct Graph{
    // 辺を表す構造体
    // rev: 逆辺(to, from)がG[to]の中で何番目の要素か
    // cap: 辺(from. to)の容量
    struct Edge{
        int rev, from, to, cap;
        Edge(int r, int f, int t, int c) : rev(r), from(r), to(t), cap(c){}
    };

    // 隣接リスト
    vector<vector<Edge>> list;

    // N: 頂点数
    Graph(int N = 0) : list(N) {}

    // グラフの頂点数取得
    size_t size(){
        return list.size();
    }

    // GraphインスタンスをGとして
    // G.list[v]をG[v]とかけるようにしておく
    vector<Edge> &operator [] (int i){
        return list[i];
    }

    // 辺 e = (u, v) の逆辺(v, u)を取得する
    Edge& redge(const Edge &e){
        return list[e.to][e.rev];
    }

    // 辺 e = (u, v)に流量fのフローを流す
    // e = (u, v) の流量がfだけ減少する
    // このとき逆辺 (v, u) の流量を増やす
    void run_flow(Edge &e, int f){
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点 from から頂点 to へ容量capの辺をはる
    // このときtoからfromへも容量0の辺を貼っておく
    void addedge(int from, int to, int cap){
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge(torev, from, to, cap));
        list[to].push_back(Edge(fromrev, to, from, 0));
    }
};


struct FordFulkerson{
    static const int INF = 1 << 30;
    vector<int> seen;

    FordFulkerson() {}

    // 残余グラフ上でs-tパスを見つける(深さ優先探索)
    // 返り値はs-tパス上の容量の最小値（見つからなかったら0)
    // f: sからvへ到達した過程の各辺の容量の最小値
    int fodfs(Graph &G, int v, int t, int f){
        // 終端tに到達したらリターン
        if(v == t) return f;

        // 深さ優先探索
        seen[v] = true;
        for(auto &e : G[v]){
            if(seen[e.to]) continue;

            // 容量0の辺は実際には存在しない
            if(e.cap == 0) continue;

            // s-tパスを探す
            // 見つかったらflowはパス上の最小容量
            // 見つからなかったら f = 0
            int flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-tパスが見つからなかったら辺を試す
            if(flow == 0) continue;

            // 辺eに容量flowのフローを流す
            G.run_flow(e, flow);

            // s-tパスを見つけたらパス上最小容量を返す
            return flow;
        }

        // s-tパスが見つからなかったことを示す
        return 0;
    }

    // グラフGのs-t間の最大流量を求める
    // ただしリターン時にGは残余グラフになる
    int solve(Graph &G, int s, int t){
        int res = 0;

        // 残余グラフにs-tパスがなくなるまで反復
        while(true){
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            // s-tパスが見つからなかったら終了
            if(flow == 0) return res;

            // 答えを加算
            res += flow;
        }

        // no reach
        return 0;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; ++i){
        int u, v, c;
        cin >> u >> v >> c;

        // 容量cの辺(u, v)を張る
        G.addedge(u, v, c);
    }

    // フォード・ファルカーソン法
    FordFulkerson ff;
    int s = 0, t= N - 1;
    cout << ff.solve(G, s, t) << endl;
}
