/*

 策略模式(Strategy)属于对象行为型设计模式,主要是定义一系列的算法,把这些算并且使它们之间可以互换。策略模式使这些算法
法一个个封装成拥有共同接口的单独的类,这里的算法不要狭义的理解为数据结构中算在客户端调用它们的时候能够互不影响地变化。法,可以理解为不同的业务处理方法。


1) 算法使用环境(Context)角色:算法被引用到这里和一些其它的与环境有关的操作一起来完成任务。
2) 抽象策略(Strategy)角色:规定了所有具体策略角色所需的接口。在 java 它通常由接口或者抽象类来实现。
3) 具体策略(Concrete Strategy)角色:实现了抽象策略角色定义的接口。策略模式各个角色之间关系的类图表示:

策略模式（Strategy）：它定义了一系列的算法，并将每一个算法封装起来，而且使它们还可以相互替换。策略模式让算法的变化不会影响到使用算法的客户。
（原文：The Strategy Pattern defines a family of algorithms,encapsulates each one,and makes them interchangeable.
Strategy lets the algorithm vary independently from clients that use it.）

 */

#include "strategy.h"

using namespace std;

void strategy_setup()
{
	cout << endl;
	cout << "welcome to the demo of strategy design pattern ..." << endl;
	cout << endl;
}

void strategy_run()
{
	cout << "create the father, mother and daughter with meat, vegetable, and vegetable..." << endl;
	guy* f = new father(new meat());
	guy* m = new mother(new vegetable());
	guy* d = new daughter(new vegetable());

	cout << endl;
	cout << "start to eat ..."<< endl;
	f->eat();
	m->eat();
	d->eat();

	delete f;
	f = NULL;
	delete m;
	m = NULL;
	delete d;
	d = NULL;

}

void strategy_clean()
{

}

// demo codes for strategy design pattern
void father::eat(){
	if(this->_food)
	{
		cout << endl;
		cout << "father start to eat ";
		this->_food->handle();
	}
}

father::father(food* f){
	if(f)
	{
		this->_food = f;
	}
}

father::~father(){
	if(this->_food)
	{
		delete this->_food;
		this->_food = NULL;
	}
}

void mother::eat(){
	if(this->_food)
	{
		cout << endl;
		cout << "mother start to eat ";
		this->_food->handle();
	}

}

mother::mother(food* f){
	if(f)
	{
		this->_food = f;
	}

}

mother::~mother(){
	if(this->_food)
	{
		delete this->_food;
		this->_food = NULL;
	}

}

void daughter::eat(){
	if(this->_food)
	{
		cout << endl;
		cout << "daughter start to eat ";
		this->_food->handle();
	}

}

daughter::daughter(food* f){
	if(f)
	{
		this->_food = f;
	}

}

daughter::~daughter(){
	if(this->_food)
	{
		delete this->_food;
		this->_food = NULL;
	}

}


void meat::handle(){
	cout << "meat "<< endl;
	cout << endl;
}

void vegetable::handle(){
	cout << "vegetable "<< endl;
	cout << endl;
}

