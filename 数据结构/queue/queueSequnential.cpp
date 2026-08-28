#include<iostream>
using namespace std;
template<typename T>
class Queue{
private:
    struct ListNode{
        T data;
        ListNode* next;
        ListNode(T data):data(data),next(NULL){}
    };
    ListNode* front;
    ListNode* rear;
    int size;
public:
    Queue():front(NULL),rear(NULL),size(0){}
    ~Queue();
    void enQueue(T element);
    void deQueue();
    T getQueue();
    int getsize();
};

template<typename T>
Queue<T>::~Queue(){
    while(front){
        ListNode* temp = front;
        front = front->next;
        delete temp;
    }
}

template<typename T>
void Queue<T>::enQueue(T element){
    if(rear == NULL){
        rear = new ListNode(element);
        front = rear;
    }
    else{
        rear->next = new ListNode(element);
        rear = rear->next;
    }
    size++;
}

template<typename T>
void Queue<T>::deQueue(){
    if(front){
        ListNode* temp = front;
        front = front->next;
        delete temp;
        size--;
    }
}

template<typename T>
T Queue<T>::getQueue(){
    return front->data;
}

template<typename T>
int Queue<T>::getsize(){
    return size;
}
int main(){
}