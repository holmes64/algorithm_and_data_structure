#include <iostream>
#include <vector>
using namespace std;

// linear search for index

int main(){
    // input
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for(int i=0; i < N; i++) cin >> a[i];

    // linear search
    int found_id = -1;
    for(int i=0; i < N; i++){
        if(a[i] == v){
            found_id = i; // if found, record the index
            break; // break loop
        }
    }

    // output result
    cout << found_id << endl;

}
