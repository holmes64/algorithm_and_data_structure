// 経路圧縮の工夫なしの場合の根取得

int root(itn x){
    if(par[x] == -1) return x; // xが根の場合はxを直接返す
    else return root(par[x]); // xが根でないなら再帰的に親へと進む
}
