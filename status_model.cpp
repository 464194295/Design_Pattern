
//状态模式
// status model.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;


class Work;
class status
{
public:
    virtual void lifestatus(Work* w) = 0;
};

class Work
{
public:
    Work(status* mms) :s(mms) {}
    void setStatus(status* my_s);
    void wirteDoingSomething();
    int time;
    status* s;
};

void Work::setStatus(status* my_s)
{
    s = my_s;
    return;
}

void Work::wirteDoingSomething()
{
    //if (s == nullptr)
      //  return;
    s->lifestatus(this);
}

class Afternoonstatus :public status
{
public:
    virtual void lifestatus(Work* w) {
        if (w->time >= 15 && w->time <= 18) {
            cout << "this is time for work" << endl;
        }
    }
};

class lunchhour :public status
{
public:
    virtual void lifestatus(Work* w) {
        if (w->time >= 13 && w->time <= 14) {
            cout << "this is time for sleep" << endl;
        }
        else {
            w->setStatus(new Afternoonstatus());
            w->wirteDoingSomething();
        }
    }
};

class mooning :public status
{
public:
    virtual void lifestatus(Work* w) {
        if (w->time >= 8 && w->time <= 11) {
            cout << "this is time for work" << endl;
        }
        else {
            w->setStatus(new lunchhour());
            w->wirteDoingSomething();
        }
    }
};





int main()
{
    status* mms = new mooning();
    Work* w = new Work(mms);
    w->time = 8;
    w->wirteDoingSomething();
    w->time = 10;
    w->wirteDoingSomething();
    w->time = 13;
    w->wirteDoingSomething();
    w->time = 15;
    w->wirteDoingSomething();

    delete w;
    delete mms;

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