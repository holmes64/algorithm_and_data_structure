#include <iostream>
using namespace std;

int GCD(int m, int n){
    // base case
    if(n == 0) return m;

    // 再帰呼び出し
    return GCD(n, m % n);
}

int main(){
    cout << GCD(51, 15) << endl;
    cout << GCD(15, 51) << endl;
}
