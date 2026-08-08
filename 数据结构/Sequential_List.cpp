#include<bits/stdc++.h>
using namespace std;
#define eleType int
struct sequentialList{
    eleType* elements;
    int size;
    int capacity;
};
void initializeList(sequentialList* List,int capacity)//初始化
{
    List->elements = new eleType[capacity];
    List->size = 0;
    List->capacity = capacity;
}

void destoryList(sequentialList* List)//删除分配的内存
{
    delete[] List->elements;
}

void insert(sequentialList* List,int index,eleType element)//插入表中元素
{
    if(index<0 || index > List->size)
    {
        throw std::invalid_argument("Invalid index");//？？？？？？
    }
    if(List->size == List->capacity)
    {
        int newcapacity = List->capacity * 2;
        eleType* newelements = new eleType[List->capacity * 2];
        for(int i = 0;i<List->size;++i)
        {
            newelements[i] = List->elements[i];
        }
        delete[] List->elements;
        List->elements = newelements;
        List->capacity = newcapacity;
    }
    for(int i = List->size;i > index;--i)
    {
        List->elements[i] = List->elements[i-1];
    }
    List->elements[index] = element;
    List->size++;
}

void deleteElement(sequentialList* List,int index)//删除该索引元素
{
    if(index<0 || index >= List->size)
    {
        throw std::invalid_argument("Invalid index");//？？？？？？
    }
    for(int i = index;i<List->size-1;++i)
    {
        List->elements[i] = List->elements[i+1]; 
    }
    List->size--;
}
void swapElement(sequentialList* List,int index,int swap_value)//替换其中的值
{
    if(index<0 || index >= List->size)
    {
        throw std::invalid_argument("Invalid index");//？？？？？？
    }
    else
    {
     List->elements[index] = swap_value;   
    }
}
int main()
{
    cout <<"hello"; 
    return 0;
}
