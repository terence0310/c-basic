# 基本使用
 front()代表第一个元素，back()代表最后一个元素，而begin()指向第一个元素地址，end()指向end()后的迭代器。
   `vector<int> v ={1,2,3,4,5};`
    `int capacity = v.capacity();//获取当前容量`
    `v.push_back(7);//添加元素`
    

#   创建
- 
         `for(vector<int>::iterator it = v.begin();it!=v.end();it++){`
            `cout<<(*it)<<" ";//iterator是个类型`
        `}`
- 同理和c的数组一样定义。
- `vector<int> v1({1,2,3,4,5,6,7,8,9});`//类似有参构造
- `vector<int> v2(c.begin(),c.end());//迭代器直接将c的元素复制到v2中`
- `vector<int> v3(6,1)//六个元素都是1`
- `vector<int> v4(v3)//直接拷贝`

# 赋值
1. `vector<int> v ={1,2,3,4,5}    vector<int> v1 = v;`
2. v2.assign(v1.begin(),v1.end())==只要针对已经创建的v2，替换新的数，旧的的值直接丢掉==
3. v2.assign({1,2,3,4,,5});
4. v2.assign(8,6);


# 插入(push_back()  && insert())

- `v.insert(v.begin(),123);//     v.begin()+12`

## 删除（pop_back()  &&  erase()）
    vector<int> v = {1, 2, 3, 4, 5};
    v.pop_back();
    cout<< v.back() << endl;
    v.erase(v.begin());//该返回被删除元素的下一个元素的迭代器iterator
    cout<< v.front() << endl;
    v.clear();//清空容器，容器大小变为0，但不改变容器的容量

# jkl
































