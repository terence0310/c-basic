#include<iostream>
using namespace std;
template<typename T>
struct TreeNode{
    T val;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode():val(0),Left(NULL),Right(NULL){}
    TreeNode(T val):val(val),Left(NULL),Right(NULL){}
};

template<typename T>
class Tree{
private:
    TreeNode<T>* nodes;
    TreeNode<T>* root;
    size_t size;
    TreeNode<T>* Create(T a[], int size, int nodeId, T nullNode);
    void visit(TreeNode<T>* node);
    void preOrder(TreeNode<T>* node);
    /*void inOrder(TreeNode<T>* node);
    void postOrder(TreeNode<T>* node);*/
public:
    Tree();
    Tree(int max);
    ~Tree();
    TreeNode<T>* getTree(int id);
    void vistnode(int id);
    void CreatTree(T a[],int size,T nullNode);
    void preOrdertraver();
   /* void inOrdertraver();
    void postOdertraver();*/
};

template<typename T>
Tree<T>::Tree(){
    nodes = new TreeNode<T>[10];
    size = 10;
    root = NULL;
}

template<typename T>
Tree<T>::Tree(int max){
    nodes = new TreeNode<T>[max];
    size = max;
    root = NULL;
}

template<typename T>
Tree<T>::~Tree(){
    delete[] nodes;
}

template<typename T>
void Tree<T>::visit(TreeNode<T>* node){
    cout<<node->val;
}

template<typename T>
TreeNode<T>* Tree<T>:: getTree(int id){
    return &nodes[id];
}

template<typename T>
TreeNode<T>* Tree<T>::Create(T a[], int size, int nodeId, T nullNode){
    if(nodeId >= size||a[nodeId] == nullNode) return NULL;
    TreeNode<T>* node = getTree(nodeId);
    node->val = a[nodeId];
    node->Left = Create(a, size, nodeId * 2, nullNode);
    node->Right = Create(a, size, nodeId * 2 + 1, nullNode);
    return node;
}

template<typename T>
void Tree<T>::CreatTree(T a[],int size,T nullNode){
    root = Create( a,size,1,nullNode);
}

template<typename T>
void Tree<T>::preOrder(TreeNode<T>* node){
    if(node)
    {
        visit(node);
        preOrder(node->Left);
        preOrder(node->Right);
    }
}

template<typename T>
void Tree<T>::preOrdertraver(){
    preOrder(root);
}

int main(){
    Tree<char> t(7);
    const char nullNpde = '-';
    char p[8] = {nullNpde,'a','b','c','d','e','f','g'};
    t.CreatTree(p,8,nullNpde);
    t.preOrdertraver();
    return 0;
}