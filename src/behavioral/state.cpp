/*

 状态模式和策略模式很相似，状态模式在具体实现上留下了可变换的余地。
状态模式的定义： 允许一个对象在其内部状态改变时改变它的行为。能让程序在外部情况不同的时候做出不同的响应，
最直接的方法是使用if else. 但if else容易产生错误，并且会显得杂乱无章。 而状态模式是讲不同条件下的行为封装在一个类里面，在给这些类一个统一的父类来约束他们。

结构：
1） 使用环境 （context）角色：客户程序是通过它来满足自己的需求， 它定义了客户程序需要的接口，并且维护一个具体状态角色的实例，这个实例来决定当前的状态。

2） 状态（state）角色：定义一个接口以封装与使用环境角色的一个特定状态相关的行为。

3） 具体状态(concrete state)角色： 实现状态角色定义的接口。

 */

#include "state.h"
using namespace std;

void state_setup()
{
	cout << endl;
	cout << "welcome to the demo for state design pattern ..." <<endl;
	cout << endl;
}

void state_run()
{
	cout << "new the book object ..."<< endl;
	book* b = new book(new state_ready());
	cout << "start to borrow the book" << endl;
	b->request();
	b->request();
	b->request();
	b->request();
	delete b;
	b = NULL;
}

void state_clean()
{

}

// demo codes for state design pattern

book::book(state* s){
	this->_state = s;
}

book::~book(){
	if(this->_state)
	{
		delete this->_state;
		this->_state = NULL;
	}
}

void book::changeState(state* s){

	cout << endl;
	cout << "change state ..." << endl;
	cout << "original state = " << this->_state->getState() << endl;
	if(this->_state)
	{
		delete this->_state;
		this->_state = NULL;
	}

	this->_state = s;

	cout << "changed state = " << this->_state->getState() << endl;
	cout << endl;
}

void book::request(){
	if(this->_state)
	{
		this->_state->handle(this);
	}
}

void state_ready::handle(book* b){
	cout << endl;
	cout << "the book is ready";
	cout << endl;
	b->changeState(new state_requested());
}

string state_ready::getState(){
	string str = "ready";
	return str;
}

void state_requested::handle(book* b){
	cout << endl;
	cout << "the book is borrowing";
	cout << endl;
	b->changeState(new state_reading());

}

string state_requested::getState(){
	string str = "borrowing";
	return str;
}


void state_reading::handle(book* b){
	cout << endl;
	cout << "the book is borrowed";
	cout << endl;
	b->changeState(new state_return());
}

string state_reading::getState(){
	string str = "borrowed";
	return str;
}

void state_return::handle(book* b){
	cout << endl;
	cout << "the book is returning";
	cout << endl;
	b->changeState(new state_ready());
}

string state_return::getState(){
	string str = "returning";
	return str;

}
