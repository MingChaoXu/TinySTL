#include <iostream>
using namespace std;

template<typename T>
class MyVector{
public:
    typedef T value;
    typedef T* iterator; // vector 的 iterator 本质就是一个指针
    typedef T& reference;

public:
    MyVector(int len=0):
        m_len(len), m_Data(nullptr), start(nullptr), pos(0)
    {
        if (len > 0){
            // 创建一个数组
            // 创建堆空间的内存在析构的时候需要释放掉
            m_Data = new value[len];
        }
    }
    ~MyVector(){
        
    }

protected:
    iterator m_Data;
    iterator start;
    int m_len;
    int pos;

};