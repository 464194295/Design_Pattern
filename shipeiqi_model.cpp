//适配器模式
// shipeiqi_model.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

class player
{
public:
    player(string my_name) :name(my_name) {};
    virtual ~player() {};
    virtual void attack() = 0;
    virtual void defense() = 0;
    string name;
};

class forward:public player
{
public:
    forward(string my_name) :player(my_name) {};
    virtual void attack() {
        cout << "前锋" << name << "进攻" << endl;
    }
    virtual void defense() {
        cout << "前锋" << name << "防守" << endl;
    }
};

class center :public player
{
public:
    center(string my_name) :player(my_name) {};
    virtual void attack() {
        cout << "中锋" << name << "进攻" << endl;
    }
    virtual void defense() {
        cout << "中锋" << name << "防守" << endl;
    }
};

class guards :public player
{
public:
    guards(string my_name) :player(my_name) {};
    virtual void attack() {
        cout << "后卫" << name << "进攻" << endl;
    }
    virtual void defense() {
        cout << "后卫" << name << "防守" << endl;
    }
};

class foreigncenter :public player
{
public:
    foreigncenter(string my_name) :player(my_name) {};
    virtual void attack() {
        cout << "外籍中锋" << name << "进攻" << endl;
    }
    virtual void defense() {
        cout << "外籍中锋" << name << "防守" << endl;
    }
};

class translter :public player
{
public:
    translter(string my_name) :player(my_name) {
        foreginpointer = new foreigncenter(name);
    };
    virtual void attack() {
        foreginpointer->attack();
    }
    virtual void defense() {
        foreginpointer->defense();
    }

private:
    foreigncenter* foreginpointer ;
};


int main()
{
    shared_ptr<player> my_play (new guards("geffer"));
    my_play->attack();
    shared_ptr<player> tr(new translter("yaoyao"));
    
    tr->attack();
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