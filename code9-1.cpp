#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int st[MAX]; // スタックを表す配列
int top = 0; // スタックの先頭を表す添字

// スタックを初期化する
void init(){
    top = 0; // スタックの添字を初期位置に
}

// スタックが空かどうかを判定する
bool isEmpty(){
    return (top == 0); // スタックサイズが0かどうか
}

// スタックが満杯かどうかを判定する
bool isFull(){
    return (top == MAX); // スタックサイズがMAXかどうか
}

// push
void push(int x){
    if(isFull()){
        cout << "error: stack is full." << endl;
        return;
    }
    st[top] = x; // xを格納して
    ++top; // topをすすめる
}

// pop
int pop(){
    if(isEmpty()){
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top; // topをデクリメントして
    return st[top]; // topの位置にある要素を返す
}

int main(){
    init(); // スタックを初期化

    push(3); // スタックに3を挿入する
    push(5); // スタックに5を挿入する
    push(7); // スタックに7を挿入する

    cout << pop() << endl;
    cout << pop() << endl;

    push(9);
}

