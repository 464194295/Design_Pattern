







// zhongjianzhe_mode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>

using namespace std;

class country;

class unitedStatus
{
public:  
    virtual void Declare(string message, country *count) = 0;
};

//在国家里面调用联合国的declare，然后有收到通知的函数打印出收到通知了
class country
{
public:
    //country(unitedStatus* middle) { middle_mechanism = middle; }
    unitedStatus *middle_mechanism;
    virtual void declure(string message) = 0;
    virtual void getmessage(string message) = 0;

};

class France : public country
{
public:
    France() = default;
    France(unitedStatus* middle) { middle_mechanism = middle; }

    void declure(string message) {
        middle_mechanism->Declare(message, this);
    }

    void getmessage(string message) {
        cout << "France获取对方的信息" << message << endl;
    }
};

class Germany : public country
{
public:
    Germany(unitedStatus* middle) { middle_mechanism = middle; }

    void declure(string message) {
        middle_mechanism->Declare(message, this);
    }

    void getmessage(string message) {
        cout << "Germany获取对方的信息" << message << endl;
    }
};

//中间者的一个子类
class unitedStatus_one : public unitedStatus
{
private:
    France *fran;
    Germany *germ;
public:
    void getf(France *ff) { fran = ff; }
    void getG(Germany* gg) { germ = gg; }

    virtual void Declare(string message, country *count) {
        if (count == fran) {
            fran->getmessage(message);
        }
        else if (count == germ) {
            germ->getmessage(message);
        }
        else {
            cout << "invalid country" << endl;
            return;
        }
    }
};





int main()
{
    unitedStatus_one* one = new unitedStatus_one();
    France* france1 = new France(one);
    Germany* germany1 = new Germany(one);

    one->getf(france1);
    one->getG(germany1);

    france1->declure("this is france");
    germany1->declure("this is germany");

    delete one;
    one = nullptr;
    delete france1;
    france1 = nullptr;
    delete germany1;
    germany1 = nullptr;

    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

