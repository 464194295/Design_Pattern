//这个是组合模式，将对象组合树形数据结构表示部分和整体的层次概念，使得单个对象和组合对象的使用具有一致性
//

#include <iostream>
#include <list>
using namespace std;

class company
{
public:
    company(string my_name) :name(my_name) {}

    virtual void add(company* c) = 0;
    virtual void remove(company* c) = 0;
    virtual void display(int depth) = 0;
    virtual void lineofduty() = 0;

    string name;
};

class concretecompany :public company
{
public:
    concretecompany(string my_name) :company(my_name) {}

    void add(company* c) {
        children.push_back(c);
    }

    void remove(company* c) {
        auto i = find(children.begin(), children.end(), c);
        children.erase(i);
    }

    void display(int depth) {
        string henggang = "-";
        for (int i=0;i<depth;i++)
            henggang += '-';
        cout << henggang << name << endl;

        for (auto i : children) {
            i->display(depth+2);
        }
    }

    void lineofduty() {
        for (auto i : children) {
            i->lineofduty();
        }
    }

    list<company*> children;
};

class HR :public company
{
public:
    HR(string my_name) :company(my_name) {}

    virtual void add(company* c) {}
    virtual void remove(company* c) {}
    virtual void display(int depth) {
        string henggang = "-";
        for (int i = 0; i < depth; i++)
            henggang += '-';
        cout << henggang << name << endl;
    }
    virtual void lineofduty() {
        cout << name << "员工培训" << endl;
    }
};

class finane :public company
{
public:
    finane(string my_name) :company(my_name) {}

    virtual void add(company* c) {}
    virtual void remove(company* c) {}
    virtual void display(int depth) {
        string henggang = "-";
        for (int i = 0; i < depth; i++)
            henggang += '-';
        cout << henggang << name << endl;
    }
    virtual void lineofduty() {
        cout << name << "负责财务" << endl;
    }
};

int main()
{
    concretecompany* root = new concretecompany("北京总公司");
    root->add(new HR("总公司人力"));
    root->add(new finane("总公司财务"));

    concretecompany* shanghai_root = new concretecompany("上海分公司");
    shanghai_root->add(new HR("上海公司人力"));
    shanghai_root->add(new finane("上海公司财务"));

    root->add(shanghai_root);

    root->display(1);
    root->lineofduty();

    return 0;
}

