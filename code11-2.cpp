// 経路圧縮の工夫ありの場合の根取得

int root(int x){
    if(par[x] == -1) return x; // xが根の場合はxを直接返す
    else return par[x] = root(par[x]); // xの根par[x]を根に設定する
}


