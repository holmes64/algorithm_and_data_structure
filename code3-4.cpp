#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;

// calculate min value at pair wise sum.

int main(){
    // input
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];

    // linear search
    int min_value = INF;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            // if sum is less than K, truncate
            if(a[i] + b[i] < K) continue;

            // Update min
            if(a[i] + b[i] < min_value){
                min_value = a[i] + b[i];
            } 
        }
    }
    cout << min_value << endl;
}

