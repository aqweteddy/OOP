#include <iostream>
#include <string>
#include "Bag.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "-------Test for Basic-------" << endl;
    Bag<string> a;              //印Bag constructor
    cout << a.empty() << endl;  //是否為空//印1
    cout << a.ended() << endl;  //若手指還未指向任和東西則回傳true//印1

    cout << "-------Test for finger-------" << endl;
    cout << a.currentValue() << endl;  //輸出Please start finger和空白行
    a.next();   //還未將手指初始化就呼叫next()//印Please initializes
    a.start();  //初始化手指，指到其中一個物品上//若包包為空，印Please input
                // item程式不能壞掉
    a.insert("a1");  //"a1"放入包包
    a.insert("a2");  //"a2"放入包包
    //走訪背包時可以是任意順序，可以是放入順序，也可以不是。
    //但是要一直next()到底，背包得所有項目都有被走訪。
    a.start();  //初始化手指，指到其中一個物品上
    cout << a.currentValue() << endl;  //印a1或a2
    a.next();                          //手指指到下一個物品
    cout << a.currentValue()
         << endl;  //如果前面是印a1，這裡就該印a2;如果前面是印a2，這裡就該印a1;
    cout << a.currentCount() << endl;  //指到第幾個物品//印2
    a.next();                          //若已經指到底//手指指到NULL
    cout << "-------Test for self-assign--------" << endl;
    a = a;
    cout << a.size() << endl;
    cout << "-------Test for Copy Constructor-------" << endl;
    Bag<string> a_copy = a;  // Copy constructor:複製a//印Bag copy constructor
    cout << a_copy.size() << endl;  //印2
    a.insert("a3");
    cout << a_copy.size() << endl;  //還是印2

    Bag<string> a_assignment;  // Bag constrcucted
    a_assignment.insert("assignment1");
    a_assignment = a;
    //把a指派給a_assignment，a_assignment原來的舊有值不該存在/Bag
    // assignment operator/印
    cout << a_assignment.size() << endl;  //印3
    a_assignment.start();
    cout << a_assignment.currentValue() << endl;  //印a1
    a_assignment.next();
    cout << a_assignment.currentValue() << endl;  //印a2
    a_assignment.next();
    cout << a_assignment.currentValue() << endl;  //印a3

    Bag<int> b;  //印Bag constructor
    b.insert(10);
    b.insert(20);
    b.insert(20);
    b.insert(20);
    b.insert(30);
    b.insert(10);
    b.insert(90);

    cout << b.size() << endl;        //包包中物品總數//印7
    cout << b.uniqueSize() << endl;  //包包中相異物品數//印4
    cout << b.erase(10) << endl;  //刪除(10)，回傳是第幾個物品//印1
    cout << b.erase(90) << endl;  //印6
    cout << b.size() << endl; //印5
    cout << b.eraseAll(20) << endl;  //刪除所有(20)，回傳刪除的總數//印3
    cout << b.contains(20) << endl;  //包包中是否包含(20)//印0
    cout << b.count(10) << endl;     //包包中(10)的數量//印1

    cout << "-------Test for combine and subtract-------" << endl;
    Bag<string> c1, c2, c_result;
    c1.insert("duck");
    c1.insert("duck");
    c1.insert("goose");
    c1.insert("chicken");
    c1.insert("chicken");

    c2.insert("duck");
    c2.insert("goose");
    c2.insert("goose");
    c2.insert("chicken");
    c2.insert("chicken");
    
    // c_result中
    // 要有c1與c2中所有物品，在這裡就沒有規定順序，只要物品數量正確即可
    // c_result中要有3個"duck", 3個"goose", 4個"chicken"
    combine(c1, c2, c_result);
    cout << "duck: " << c_result.count("duck") << endl;
    cout << "goose: " << c_result.count("goose") << endl;
    cout << "chichen: " << c_result.count("chicken") << endl;

    c_result.clear();

    //在這裡就沒有規定順序，只要物品數量正確即可
    // c_result中要有1個"duck", 0個"goose", 0個"chicken"
    subtract(c1, c2, c_result);
    cout << "duck: " << c_result.count("duck") << endl;
    cout << "goose: " << c_result.count("goose") << endl;
    cout << "chichen: " << c_result.count("chicken") << endl;

    //測試c1, c_result 為同物的狀況
    combine(c1, c2, c1);
    cout << "duck: " << c1.count("duck") << endl;//3
    cout << "goose: " << c1.count("goose") << endl;//3
    cout << "chichen: " << c1.count("chicken") << endl;//4
    
    subtract(c1, c2, c1);
    cout << "duck: " << c1.count("duck") << endl;//5
    cout << "goose: " << c1.count("goose") << endl;//4
    cout << "chichen: " << c1.count("chicken") << endl;//6
    c_result.clear();

    return 0;  //毀掉幾個就印幾次Bag destructor//印七次Bag constructor
}