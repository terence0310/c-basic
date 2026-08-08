#include<iostream>//顺序表
#include<stdexcept>
using namespace std;
template <typename T>
class stack{
private:    
    T* date;
    int size;
    int capacity;
    void resize();
public:
    ~stack();
    void push(T num);
    void pop1();
    void print();
    stack():date(new T[capacity]),size(0),capacity(10){}
    void getsize();
};
template <typename T>
void stack<T>::resize()
{
    if(size == capacity){
        int newcapacity = capacity*2;
        T* newdate = new T[newcapacity];
        for(int i = 0;i<size;i++){
            newdate[i] = date[i];
        }   
        delete[]date;
        date = newdate;
        capacity = newcapacity;
    }
}

template <typename T>
stack<T>::~stack(){
    delete[]date;
}

template <typename T>
void stack<T>::push(T num){
    if(size == capacity) resize();
    date[size] = num;
    size++;
}

template <typename T>
void stack<T>::pop1()
{
    size--;
    cout<<date[size]<<endl;
}

template <typename T>
void stack<T>::print(){
    for(int i = size-1;i>= 0;i--){
        cout<< date[i] <<" ";
    }
}

template <typename T>
void stack<T>::getsize(){
    cout<<size<<endl;
}
int main()
{

    return 0;
}
