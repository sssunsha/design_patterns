
/*

 观察者模式(Observer)又名发布-订阅模式。定义为： 定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变的时候，所有依赖于它的对象都得到通知并被自动更新。

结构：
1.抽象目标角色(Subject)：目标角色知道它的观察者,可以有任意多个观察者观察同一个目标。并且提供注册和删除观察者对象的接口。目标角色往往由抽象类或者接口来实现。

2. 抽象观察者角色(Observer):为那些在目标发生改变时需要获得通知的对象定义一个更新接口。抽象观察者角色主要由抽象类或者接口来实现。

3. 具体目标角色(Concrete Subject):将有关状态存入各个 Concrete Observer 对象。当它的状态发生改变时, 向它的各个观察者发出通知。

4. 具体观察者角色(Concrete Observer):存储有关状态,这些状态应与目标的状态保持一致。实现 Observer 的更新接口以使自身状态与目标的状态保持一致。
	在本角色内也 可以维护一个指向 Concrete Subject 对象的引用。

 */

#include "../include.h"
#include <vector>
using namespace std;

void observer_setup();
void observer_run();
void observer_clean();

// demo codes for observer design pattern

// observer
class observer{
public:
	virtual void update() = 0;
	virtual ~observer(){}
};

// subject
class subject {
public:
	virtual void notify() = 0;
	virtual ~subject(){}
	virtual void addListener(observer* o) = 0;
	virtual void removeListener(observer* o) = 0;
};

// concrete observer
class observer_a : public observer{
public:
	void update();
};

class observer_b : public observer{
public:
	void update();
};

class observer_c : public observer{
public:
	void update();
};
// concrete subject
class subject_a : public subject{
public:
	void notify();
	void addListener(observer* o);
	void removeListener(observer* o);
	~subject_a();
	subject_a();
private:
	vector<observer*>* observer_list;
};
