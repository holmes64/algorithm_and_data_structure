#include <iostream>
#include <vector>
using namespace std;

// linear search

int main(){
    // input processing
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for(int i=0; i < N; i++) cin >> a[i];

    // liner search
    bool exist = false; // 初期値はfalse
    for(int i=0; i < N; ++i){
        if(a[i] == v){
            exist = true; // if found, set flag True
        }
    }

    // output
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}

