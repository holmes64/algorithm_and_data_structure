#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 20000000;

int main(){

    // input
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int i=0; i<N; ++i) cin >> b[i];

    // 暫定最小値を格納する変数
    int min_value = INF;

    // bをソートする
    sort(b.begin(), b.end());

    // aを固定して解く　
    for(int i=0; i<N; ++i){
        // bの中で、K - a[i] 以上の範囲での最小値を示すイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // イテレータの示す値を取り出す
        int val = *iter;

        // min_valueと比較する
        if(a[i] + val < min_value){
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}
