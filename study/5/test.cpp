#include <iostream>
#include <vector>
using namespace std;
// 5. stl为什么需要迭代器
// 迭代器最基本的作用,就是连接容器和算法的桥梁


template<typename T>
// struct 与 class 最大的区别就是struct默认是public, class 默认是private
struct List_Node{
    List_Node<T>* prev;
    List_Node<T>* next;
    T val;
};

template<typename T>
struct List_iterator{
    typedef List_iterator<T> iterator;
    typedef T value;
    typedef T& ref;
    List_Node<T>* node;

    List_iterator(List_Node<T>* node): node(node){}
    List_iterator(): node(nullptr){}

    // ++i 前缀
    iterator& operator++(){
        node = node->next;
        return *this;
    }

    // i++ int 占位 后缀
    iterator& operator++(int){
        iterator tmp = *this;
        node = node->next;
        return tmp;
    }

    iterator& operator--(){
        node = node->prev;
        return *this;
    }

    iterator& operator--(int){
        iterator tmp = *this;
        node = node->prev;
        return tmp;
    }

    bool operator==(iterator& other){
        return this->node == other->node;
    }

    bool operator!=(iterator& other){
        return this->node != other->node;
    }

    iterator* operator->(){
        return this->node;
    }

    ref operator*(){
        return node->val;
    }

};

// 循环双向链表
template<typename T>
struct MyList
{
    /* data */
    typedef List_Node<T>* pointer;
    typedef List_iterator<T> iterator;
    
    MyList(){
        node = new List_Node<T>;
        node->next = node;
        node->prev = node;
    }

    // c++ 隐式实现了 函数传入和传出都运行了构造函数
    iterator begin(){
        return node->next;
    }

    iterator end(){
        return node;
    }

    void insert(iterator position, T val){
        pointer tmp = new List_Node<T>;
        tmp->val = val;
        tmp->next = position.node->next;
        tmp->prev = position.node;
        position.node->next->prev = tmp;
        position.node->next = tmp;
    }

    void erase(pointer position){
        position->next->prev = position->prev;
        position->prev->next = position->next;
    }

    void push_back(T val){
        insert(node->prev, val);
    }

    pointer pop_back(){
        pointer tmp = node->prev;
        erase(node->prev);
        return tmp;
    }


private:
    pointer node; // 代表了该链表的结尾位置
};



template<typename T>
void printVec(T begin, T end){
    while (begin != end){
        cout << *begin << endl;
        begin++;
    }
}

template<typename T>
void printList(List_Node<T>* begin, List_Node<T>* end){
    while (begin != end){
        cout << begin->val << endl;
        begin = begin->next;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int v[5] = {1, 2, 3, 4, 5};
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    printList(list.begin(), list.end());
    cout << "--------" << endl;
    printVec(v, v+5);
    
    return 0;
}
