#include <iostream>
using namespace std;

// フィボナッチ数列を求める再帰関数の再帰呼び出しの様子

int fibo(int N){
    // 再帰関数を呼び出したことを報告する
    cout << "fibo(" << N << ") を呼び出しました." << endl;

    // basecase
    if(N == 0) return 0;
    else if(N == 1) return 1;

    // 再帰的に答えを求めて出力する
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << " 項目 = " << result << endl;

    return result;
}

int main(){
    fibo(6);
}
