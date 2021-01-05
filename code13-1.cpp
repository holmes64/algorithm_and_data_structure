#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector< vector<int> >; // グラフ型

// グラフGにおいて、頂点sを始点とした探索を行う
// 幅優先探索

void search(const Graph &G, int s){
    int N = (int)G.size(); // グラフの頂点数

    // グラフ探索のためのデータ構造
    vector<bool> seen(N, false); // 全頂点を未訪問に初期化する
    queue<int> todo; // 空の状態 (深さ優先探索の場合はstack<int>)

    // 初期条件
    seen[s] = true; // sは探索済みとする
    todo.push(s); // todoがｓのみを含む状態とする

    // todoが空になるまで探索を行う
    while(!todo.empty()) {
        // todoから頂点を取り出す
        int v = todo.front();
        todo.pop();

        // vからたどれる頂点をすべて調べる
        for(int x: G[v]) {
            // すでに発見済みの頂点は探索しない
            if(seen[x]) continue;

            // 新たな頂点xを探索済みとしてtodoに挿入
            seen[x] = true;
            todo.push(x);
        }
    }
}

int main(){
    int N; cin >> N;
}

