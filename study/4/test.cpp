#include <iostream>
#include <vector>
using namespace std;
// 4. 右值引用和移动语义

// 左值: 有名字的内存中有自己地址的值
// 右值:　
// １．除了字符串之外的字面值，　比如　５，　ｔｒｕｅ　，　ｎｕｌｌｐｔｒ，　生命周期只在这一行
// ２．返回类型为非运用的函数调用 int return x+y
// 3.算数表达式 z=x+y

// 为什么要用右值引用
// 左值引用,本质是指针常量
// 左值引用就是一个不能变的指针,所以说在定义引用的时候就需要给他初始化,因为他之后就不能变了

// std::move 移动资源,节省内存空间 把左值变成右值

class Student{
public:
    char* name;
    int size;

    Student(int size = 0): size(size), name(nullptr){
        if(size > 0){
            name = new char[size];
            for (int i = 0; i < size; i++){
                name[i] = 'a';
            }
        }
        cout << "CONSTRUCTOR" << endl;
    }

    // 深拷贝 拷贝构造函数
    Student (const Student& stu){
        size = stu.size;
        name = new char[size];
        for (int i = 0; i<size; i++){
            name[i] = stu.name[i];
        }
        cout << "COPY CONSTRUCTOR" << endl;
    }
    // 浅拷贝 移动构造函数
    // 我和我需要拷贝的那个对象,我们一模一样
    // 带来指针悬挂问题
    Student (Student&& stu){
        size = stu.size;
        name = stu.name;
        stu.name = nullptr;
        cout << "MOVE CONSTRUCTOR" << endl;
    }

    ~Student(){
        delete name;
        cout << "DELETE" << endl;
    }
};

Student Create(){
    return Student(5);
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<Student> school;
    // Student stu(Create());
    school.push_back(Create());
    
    return 0;
}
