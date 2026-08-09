#include<iostream>
#include<stdexcept>
using namespace std;
#define elemtype int 
struct ListNode{
    elemtype date;
    ListNode* next;
    ListNode(elemtype num):date(num),next(NULL){}
}；

class LinkedList{
private:
    ListNode* head;
    int size;
public:
    LinkedList():head(NULL),size(1){}
    ~LinkedList();
    void insert(int i,elemtype num);
    void remove(int i);
    void update(int i,elemtype num); 
    void printfList();
};
LinkedList::~LinkedList(){
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
void LinkedList:: insert(int i,elemtype num){
    if(i<0||i>=size){
        throw std::invalid_argument("Invalid index");
    }
    ListNode* newNode = new ListNode(num);
    if(i == 0){
        newNode->next = head;
        head = newNode;
    }
    else{
        ListNode* curr = head;
        for(int j = 0;j<i-1;j++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    size++;
}

void LinkedList ::remove(int i)
{
    if(i < 0 || i>=size){
        throw std::invalid_argument("Invalid index");
    }
    if(i == 0){
        ListNode* temp = head;
        head = temp->next;
        delete temp ;
    }
    else{
        ListNode* curr = head;
        for(int j = 0;j<i-1;j++){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    size--;
}
void LinkedList::update(int i,elemtype num){
    if(i<0||i>=size){
        throw std::invalid_argument("Invalid index");
    }
    else{
        ListNode* curr = head;
        for(int j = 0;j<i;j++){
            curr = curr->next;
        }
        curr->date = num;
    }
}
void LinkedList::printfList(){
    ListNode* curr = head;
    while(curr){
        cout<<curr->date<<" ";
        curr = curr->next;
    }
}
int main()
{
    return 0;
}
