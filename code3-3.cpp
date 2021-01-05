#include <iostream>
#include <vector>
using namespace std;
const int INF = 200000000; // please set a sufficient learge value.

// calculate min value using linear search.

int main(){

    // input
    int N; cin >> N;
    vector <int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    //linear search
    int min_value = INF;
    for(int i=0; i < N; i++){
        if(a[i] < min_value) min_value = a[i];
    }

    // output
    cout << min_value << endl;
}
