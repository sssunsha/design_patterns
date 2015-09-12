/*
 * 将一个请求封装为一个对象,从而使你可用不同的请求对客户进行参数化;对请求排队或记录请求日志,以及支持可撤消的操作。
 *
 */

/*

 1) 命令角色(Command):声明执行操作的接口。有 java 接口或者抽象类来实现。
 2) 具体命令角色(Concrete Command):将一个接收者对象绑定于一个动作;调用接收者相应的操作,以实现命令角色声明的执行操作的接口。
 3) 客户角色(Client):创建一个具体命令对象(并可以设定它的接收者)。
 4) 请求者角色(Invoker):调用命令对象执行这个请求。
 5) 接收者角色(Receiver):知道如何实施与执行一个请求相关的操作。任何类都可能作为一个接收者。


 */

#include "command.h"
using namespace std;

void command_setup()
{
	cout << endl;
	cout << "welcome to the demo for command design pattern ..."<< endl;
	cout << endl;
}
void command_clean()
{
	cout << "first creat the controller to control the TV" << endl;
	control* c = new control();
	cout << endl;
	cout << "turn on the TV" << endl;
	c->turn_on_tv();
	cout << endl;
	cout << "turn off the TV" << endl;
	c->turn_off_tv();
	cout << endl;
	cout << "change channel the TV" << endl;
	c->change_channel_tv();

	delete c;
	c = NULL;

}
void command_run()
{

}

// demo codes for command design pattern

// concerete command

turn_on_command::turn_on_command(TV* tv){
	this->_tv = tv;
}

void turn_on_command::execute(){
	this->_tv->tv_turn_on();
}

turn_off_command::turn_off_command(TV* tv){
	this->_tv = tv;
}

void turn_off_command::execute(){
	this->_tv->tv_turn_off();
}

change_channel_command::change_channel_command(TV* tv){
	this->_tv = tv;
}

void change_channel_command::execute(){
	this->_tv->tv_change_channel();
}



// receiver
void TV::tv_turn_on(){
	cout << endl;
	cout << "turn on the TV ..."<< endl;
	cout << endl;
}

void TV::tv_turn_off(){
	cout << endl;
	cout << "turn off the TV ..."<< endl;
	cout << endl;
}

void TV::tv_change_channel(){
	cout << endl;
	cout << "change channel ..." << endl;
	cout << endl;
}

// invoker
control::control(){
	this->_tv = new TV();
	this->turn_on = new turn_on_command(this->_tv);
	this->turn_off = new turn_off_command(this->_tv);
	this->change = new change_channel_command(this->_tv);
}

control::~control(){
	delete this->turn_on;
	this->turn_on = NULL;
	delete this->turn_off;
	this->turn_off = NULL;
	delete this->change;
	this->change = NULL;
	delete this->_tv;
	this->_tv = NULL;
}

void control::change_channel_tv(){
	this->change->execute();
}

void control::turn_on_tv(){
	this->turn_on->execute();
}


void control::turn_off_tv(){
	this->turn_off->execute();
}
