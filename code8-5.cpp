#include<string>

// 双方向への自己参照構造体

struct Node{
    Node *prev, *next;
    string name; // ノードに付随している値

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) {}
};

