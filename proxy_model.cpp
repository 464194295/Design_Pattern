




//
// proxy model.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//得到名字
class girl
{
public:
    girl(string name) :myname(name) {}
    string mynames() { return myname; }
private:
    string myname;
};

//代理接口
class interface
{
public:
    virtual void givedool() = 0;
    virtual void giveshirt() = 0;
    virtual void giveflower() = 0;
    virtual ~interface() {}
};

//追求者类，送东西
class pursuit:public interface
{
public:
    pursuit(girl mmgirl) :mygirl(mmgirl) {}
    ~pursuit() { cout << "destroy pursuit" << endl; }
    void givedool() { cout << mygirl.mynames()<<"give a dool for you" << endl; }
    void giveshirt() { cout << mygirl.mynames() << "give a shirt for you" << endl; }
    void giveflower() { cout << mygirl.mynames() << "give a flower for you" << endl; }
private:
    girl mygirl;
};

//代理类
class proxy:public interface
{
public:
    pursuit* betterman;

    proxy(girl mygirl) { betterman = new pursuit(mygirl); }
    virtual ~proxy() { delete betterman; }
    void givedool() { betterman->givedool(); }
    void giveshirt() { betterman->giveshirt(); }
    void giveflower() { betterman->giveflower(); }
};

int main()
{
    string lili = "lili";
    girl mygirl(lili);
    proxy* xiaoshuai = new proxy(mygirl);
    xiaoshuai->givedool();
    xiaoshuai->giveflower();
    xiaoshuai->giveshirt();
    delete xiaoshuai;

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