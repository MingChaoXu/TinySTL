// 3. 实现一个简单的vector
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
            start = m_Data;
        }
    }
    ~MyVector(){
        delete []m_Data;
    }

    void push_back(const value& v){
        if (m_len != pos){
            *(start + pos) = v;
            pos++;
        }
        else{
            cout << "越界了" << endl;
        }
        
    }
    inline value pop_back(){
        // --pos;
        return *(start + --pos);
    }
    int size(){
        return this->m_len;
    }
    iterator begin(){
        return this->start;
    }
    iterator end(){
        return this->start+pos;
    }
    // 传🚰回来才可以修改元素
    value& operator[](int n){
        if (n < pos){
            return *(start+n);
        }
        else{
            cout << "越界了" << endl;
        }
    }

protected:
    iterator m_Data;
    iterator start;
    int m_len;
    int pos;

};

template<typename T>
ostream& operator<<(ostream& cout, MyVector<T> vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return cout;
}

int main(int argc, char const *argv[])
{
    /* code */
    MyVector<int> vec(10);
    for(int i=0; i<vec.size(); i++){
        vec.push_back(i);
    }
    // for(MyVector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    //     cout << *it << endl;
    // }
    // cout << vec << endl;

    cout << vec.pop_back() << endl;
    cout << vec << endl;
    
    return 0;
}
