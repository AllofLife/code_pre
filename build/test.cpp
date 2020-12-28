#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<stdio.h>
using namespace std;
static int  counter = 0 ;
mutex lock_mutex;
void call(){
    lock_mutex.lock();
    counter ++;
    std::cout<< "thead" << counter << endl;
    lock_mutex.unlock();
}
class base{
    public: 
    int index;
    float num;
    base(){

    };
   
    int getIndex(){
        return index;
    };
    float getNum(){
        return num;
    };
};
int main(){
    // std::cout<< "size of base " << sizeof(base) << std::endl;
    //  base ba1;
    //  std::cout<< "addr of base " << &ba1 << std::endl;
    //  std::cout<< "size of base " << sizeof(ba1) << std::endl;
    // std::cout<< "size of base int " << sizeof(ba1.index) << std::endl;
    // std::cout<< "addr of base int " << &ba1.index << std::endl;
    // std::cout<< "size of base float " << sizeof(ba1.num) << std::endl;
    // std::cout<< "addr of base float " << &ba1.num << std::endl;
    // std::cout<< "size of base int fun " << sizeof(ba1.getIndex()) << std::endl;
    // ba1.index = 1;
    // ba1.num = 2.1;
    
    
    // thread t1(call);
    // thread t2(call);
    // t1.join();
    // t2.join();
    
    // // cout << std::thread::hardware_concurrency()<< endl;
    // // cout << std::this_thread::get_id() << endl;
    // uint8_t a = 134;
    // uint8_t  b = 246;
    // uint8_t c = b - a;
    //  bool b_a = a^1;
    // cout << " c " << a << endl;
    int16_t s1 = INT16_MIN ;
    printf("%X",s1);
    return 0;
}