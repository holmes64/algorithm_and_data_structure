#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

// キューの実装

int qu[MAX]; // キューを表す配列
int tail = 0, head = 0; // キューの要素区間を表す変数

// キューを初期化する
void init(){
    head = tail = 0; // キューの添字を初期位置に
}

// キューが空かどうかを判定する
bool isEmpty(){
    return (head == tail); // キューサイズが0かどうか
}

// キューが満杯かどうかを判定する
bool isFull(){
    return (head == (tail + 1) % MAX); // キューサイズがMAXかどうか
}

// enqueue 
void enqueue(int x){
    if(isFull()){
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail] = x; // xを格納して
    ++tail; // topをすすめる
    if(tail == MAX) tail = 0; // リングバッファの終端に来たら0に
}

// dequeue
int dequeue(){
    if(isEmpty()){
        cout << "error: queue is empty." << endl;
        return -1;
    }
    int res = qu[head];
    ++head;
    if(head == MAX) head = 0; // リングバッファの終端に来たら0に
    return res;
}

int main(){
    init(); // キューを初期化

    enqueue(3); // キューに3を挿入する
    enqueue(5); // キューに5を挿入する
    enqueue(7); // キューに7を挿入する

    cout << dequeue() << endl;
    cout << dequeue() << endl;

    enqueue(9);
}

