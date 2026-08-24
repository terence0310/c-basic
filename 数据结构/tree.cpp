#include<iostream>
using namespace std;
template <typename T>
struct ListNode{
    T date;
    ListNode* next;
    ListNode(T element):date(element),next(NULL){}
};
template <typename T>
class TreeNode{
public:    
    T date;
    ListNode<TreeNode<T>*>* Childhead;
    TreeNode():date(T()),Childhead(NULL){}
    void AddChild(TreeNode<T>* Node){
        ListNode<TreeNode<T>*>* childnode = new ListNode<TreeNode<T>*>(Node);
        if(Childhead == NULL){
            Childhead = childnode;
        }
        else{
            childnode->next = Childhead;
            Childhead = childnode;
        }
    }
};
template<typename T>
class Tree{
private:
    TreeNode<T>* node;
    TreeNode<T>* root;
public:
    Tree();
    Tree(int nums);
    ~Tree();
    TreeNode<T>* GetNode(int id);
    void setroot(int id);
    void insert(int parentid,int sonid);
    void update(int id,T num);
    void print(TreeNode<T>* node = NULL);
};

template<typename T>
Tree<T>::Tree(){
    node = new TreeNode<T>[10];
    root = NULL;
};

template<typename T>
Tree<T>::Tree(int nums){
    node = new TreeNode<T>[nums];
    root = NULL;
};

template<typename T>
Tree<T>::~Tree(){
    delete[] node;
}

template<typename T>
TreeNode<T>* Tree<T>::GetNode(int id){
    return &node[id];
}

template<typename T>
void Tree<T>:: setroot(int id){
    root = GetNode(id);
}

template<typename T>
void Tree<T>::insert(int parentid,int sonid){
    TreeNode<T>* p = GetNode(parentid);
    TreeNode<T>* s = GetNode(sonid);
    p->AddChild(s);
}

template<typename T>
void Tree<T>::update(int id,T num){
    GetNode(id)->date = num;
}

template<typename T>
void Tree<T>::print(TreeNode<T>* node){
    if(node == NULL){
        node = root;
    }
    cout<<node->date;
    ListNode<TreeNode<T>*>* tmp = node->Childhead;
    while (tmp) {
        print(tmp->date);
        tmp = tmp->next;
    }
}
int main(){
    Tree<char> t(9);
    t.setroot(0);
    t.update(0,'a');
    t.update(1,'b');
    t.update(2,'c');
    t.update(3,'d');
    t.update(4,'e');
    t.update(5,'f');
    t.update(6,'g');
    t.update(7,'h');
    t.update(8,'i');
    t.insert(0,2);
    t.insert(0,1);
    t.insert(1,3);
    t.insert(3,8);
    t.insert(3,7);
    t.insert(3,6);
    t.insert(2,5);
    t.insert(2,4);
    t.print();
    return 0;
}