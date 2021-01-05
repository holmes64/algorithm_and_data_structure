#include <iostream>
using namespace std;

// 汎用的な二分探索のテンプレート

// xが条件を満たすかどうか
bool P(int x){

}

// P(x) = trueとなる最小の整数xを返す
int binary_search(){
    int left, right; // P(left) = false, P(riht) = trueとなるようにする。

    while(right - left > 1){
        int mid =left + (right - left) / 2;
        if(P(mid)) right = mid;
        else left = mid;
    }
    return right;
}
