#include <iostream>
using namespace std;
// 再帰関数を用いてFibonacci数列を求める

int fibo(int N){
    // basecase
    if(N == 0) return 0;
    else if(N == 1) return 1;

    // 再帰呼び出し
    return fibo(N - 1) + fibo(N - 2);
}


int main(){
    fibo(5);

    return 0;
}
