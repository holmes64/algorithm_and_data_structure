#include <iostream>
#include <vector>
// 緩和に用いる関数chmin

template<class T> bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }else{
        return false;
    }
}
