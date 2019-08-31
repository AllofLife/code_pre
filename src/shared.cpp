#include<iostream>
#include<boost/smart_ptr.hpp>
#include<boost/make_shared.hpp>
#include<boost/make_unique.hpp>
#include<memory>
#include<vector>

using namespace std;
// auto_ptr 已经被c++11 弃用了编译warning
void test_01(){

    // auto_ptr<int> p1(new int(10));
    //     // // 将p1指向的内存的控制权交给p2
    // auto_ptr<int> p2 = p1; //转移控制权
    // // crash 出错
    // // *p1 += 10;
    // // 不出错
    // *p2 += 10;
    // cout<<"the size of p1 "<<sizeof(p1)<<endl;
    // cout<<"the size of *p1 "<<sizeof(*p1)<<endl;


}
void test_02(){
    unique_ptr<int> up(new int(5));
    //auto up2 = up; // 编译错误
    auto up2 = move(up);
    // cout << *up << endl; //crash，up已经失效，无法访问其裸指针
    // no crash 输出5
    cout << *up2 << endl; 


}
void test_03(){
    //  静态数组，在编译时决定了数组大小
    // int arr[10];
    // 通过指针创建在堆上的数组，可在运行时动态指定数组大小，但需要手动释放内存
    // int *arr = new int[10];
    // 通过std::vector容器创建动态数组，无需手动释放数组内存
    // vector<int> arr(10);
    // 通过unique_ptr创建动态数组，也无需手动释放数组内存，比vector更轻量化
    unique_ptr<int[]> arr(new int[10]);
    cout<<" get "<<arr.get()<<endl;
    cout<<" 析构 "<<endl;
    arr.~unique_ptr();
    cout<<" get "<<arr.get()<<endl;
}
// 真正的智能指针
void test_04(){
    // auto_ptr和unique_ptr都有或多或少的缺陷，因此C++11还推出了shared_ptr，
    // 这也是目前工程内使用最多最广泛的智能指针，
    // 他使用引用计数（感觉有参考Objective-C的嫌疑），
    //实现对同一块内存可以有多个引用，在最后一个引用被释放时，指向的内存才释放，
    //这也是和unique_ptr最大的区别。
    
    // 使用裸指针赋值构造，不推荐，裸指针被释放后，shared_ptr就野了，
    // 不能完全控制裸指针的生命周期，失去了智能指针价值
    
    // 以下无法通过编译
    // int *p = new int(10);
    // shared_ptr<int> sp = p;
    // delete p; // sp将成为野指针，使用sp将crash


    // 将裸指针作为匿名指针传入构造函数，一般做法，让shared_ptr接管裸指针的生命周期，更安全
    shared_ptr<int>sp1(new int(10));


    // 使用make_shared，推荐做法，更符合工厂模式，可以连代码中的所有new，更高效；方法的参数是用来初始化模板类
    shared_ptr<int>sp2 = make_shared<int>(10);
}
// 禁止使用 
//禁止使用指向shared_ptr的裸指针，也就是智能指针的指针
void test_05(){
    shared_ptr<int>sp = make_shared<int>(10);
    cout << sp.use_count() << endl; //输出1
    shared_ptr<int> *sp1 = &sp;
    cout << (*sp1).use_count() << endl; //输出依然是1
    // 正常输出
    cout << *sp << endl; 
    (*sp1).reset(); //sp成为野指针
    cout << *sp << endl; //crash
}

void test_06(){
    auto p = make_shared<int>(42); // 指向的对象只有p一个引用者。
    cout<<"p's get "<<p.get()<<endl;
    auto p_first = p.get();
    cout<<"p's count "<<p.use_count()<<endl;
    auto q = make_shared<int>(56);// 指向的对象只有q一个引用者。
    cout<<"q 's count "<<q.use_count()<<endl;
    cout<<"---------afterAssin-----"<<endl;
    p = q;                        // p原来引用的对象经过赋值之后释放掉了，q引用的对象有了p和q两个引用。
    cout<<*p<<"=="<<*q<<endl;
    cout<<"p's count "<<p.use_count()<<endl;
    cout<<"q 's count "<<q.use_count()<<endl;
    // 上面二者都是2 说明两个指针都指向了同一个内存
    // 使用get()方法来查看
    cout<<"p's get "<<p.get()<<endl;
    cout<<"q 's get "<<q.get()<<endl;
    // 的确两者打印出来的都是相同的地址
    // 那么之前的内存呢
    cout<<"the before memory p_first "<<(*p_first)<<endl;
    // 打印出了42

}
template<typename T>
shared_ptr<T> make_shared_array(size_t size){

    return shared_ptr<T>(new T[size],default_delete<T[]>());
}
// 无法编译通过 可能是语法的问题
void test_07(){
    // shared_ptr<int> sp = make_shared_array(size_t(10));
    // sp.get()[0] = 100;
}

class A {
public:
    ~A() {
        cout << "dealloc A" << endl;
    }
};
class B : public A {
public:
    ~B() {
        cout << "dealloc B" << endl;
    }
};
void test_08(){
    A *a = new B();
    // 开辟一片B对象的内存 用A指针去接收 只能调用 A的析构方法
    delete a;
    // 同样的功能用智能指针和普通指针
    // 智能指针会把两个类的析构函数都调用
    shared_ptr<A> spa = make_shared<B>();
}
int main(){
    // auto_ptr 允许赋值
    // test_01();
    // unique_ptr 不允许赋值 采用move方法
    // 转移所有权
    // test_02();
    // 通过unique_ptr 创建动态数组 数组大小可变
    // 这个只能指针也是一个对象
    // test_03();
    // 智能指针的构造
    // test_04();
    // 智能指针的赋值和引用
    // test_05();
    // 智能指针的引用计数
    // test_06();
    // 使用shared_ptr 创建动态数组 
    // 注意创建的数组返回值是一个指针
    // test_07();
    // 用shared_ptr 实现多态
    // 类B 继承与类A 
    // test_08();


   




    return 0;
}
