#include<iostream>
#include<stdexcept>
using namespace std;
class stack{
    struct Node{
        int date;
        Node* next;
        Node(int num):date(num),next(NULL){}
    };
    private:
        Node* head;
        int size;
    public:
        ~stack();
        void push(int num);
        void pop();
        stack():head(NULL),size(0){}
        void allp();
};

stack:: ~stack(){
    Node* curr = head;
    while(curr){
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void stack :: push(int num){
    Node* newNode = new Node(num);
    newNode->next = head;
    head = newNode;
    size++;
}
void stack::pop(){
    Node* temp = head;
    cout<< temp->date;
    head = head->next;
    delete temp;
    size--;
}
void stack::allp(){
    Node* curr = head;
    for(int i = 0;i<size;i++){
        cout<<curr->date<<" ";
        curr = curr->next;
    }
}
int main(){
    stack tt;
    tt.push(1);
    tt.push(2);
    tt.push(6);
    tt.push(9);
    tt.allp();
    tt.push(4);
    cout<<endl;
    tt.allp();
    tt.pop();
    tt.allp();
    return 0;
}