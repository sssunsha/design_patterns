/*

Mediator Pattern 中文译为“中介者模式”“调停者模式”、。其实都不是很好,由于现实生活中的“中介”是要和客户打交道,而省去客户原本繁琐的手续,
这一点和门面模式的初衷很相像;而在 Mediator Pattern 中 Mediator 是不可见的。“调停”也不好,因为 Mediator在程序中存在的初衷仅仅是规范信息传递的方式。
因此叫做“传递器模式”仿佛更能体贴一些,但是本文还是称其为“调停者模式”。

GOF 给调停者模式下的定义是:用一个调停对象来封装一系列的对象交互。调停者使各对象不需要显式地相互引用,从而使其耦合松散,而且可以独立地改变它们之间的交互。
简单点来说,将原来两个直接引用或者依赖的对象拆开,在中间加入一个“调停”对象,使得两头的对象分别和“调停”对象引用或者依赖。


1) 抽象调停者(Mediator)角色:抽象调停者角色定义统一的接口用于各同事角色之间的通信。
2) 具体调停者(Concrete Mediator)角色:具体调停者角色通过协调各同事角色实现协作行为。为此它要知道并引用各个同事角色。
3) 同事(Colleague)角色:每一个同事角色都知道对应的具体调停者角色,而且与其他的同事角色通信的时候,一定要通过调停者角色协作。

使用调停者模式最大的好处就是将同事角色解耦。这带来了一系列的系统结构改善:提高了原有系统的可读性、简化原有系统的通信协议——将原有的多对多变为一对多、提高了代码的可复用性......


 */

#include "mediator.h"
using namespace std;

void mediator_setup()
{
	cout << endl;
	cout << "welcome to the demo for mediator design pattern ..." << endl;
	cout << endl;
}
void mediator_run()
{
	cout << "first create the house mediator, and the host and client"<< endl;
	person* h = new host();
	person* c = new client();
	Mediator* m = new houseMediator();

	cout << "set the mediator to host and client"<< endl;
	h->set_mediator(m);
	c->set_mediator(m);

	cout << "set the host and client to the house mediator"<< endl;
	m->set_client(c);
	m->set_host(h);

	cout << "now send the message both from the host and client"<< endl;
	c->set_message("我是租客，我要租房");
	h->set_message("我是房东，我有房子要出租");

	delete m;
	m = NULL;


}
void mediator_clean()
{

}

// demo codes for mediator design pattern

// 租客
void client::get_message(string str)
{
	cout << endl;
	cout << "client (租客) get the message [ " << str << " ] " << endl;
	cout << endl;
}

void client::set_message(string str)
{
	this->_mediator->set_message(this, str);
}

void client::set_mediator(Mediator* m)
{
	this->_mediator = m;
}


// 房东
void host::get_message(string str)
{
	cout << endl;
	cout << "Host (房东) get the message [ " << str << " ] " << endl;
	cout << endl;
}

void host::set_message(string str)
{
	this->_mediator->set_message(this, str);
}


void host::set_mediator(Mediator* m)
{
	this->_mediator = m;
}

// 中介
void houseMediator::set_client(person* p)
{
	if(p)
	{
		this->_client = p;
	}
}

void houseMediator::set_host(person* p)
{
	if(p)
	{
		this->_host = p;
	}
}

void houseMediator::set_message(person* p, string str)
{
	if(this->_client == p)
	{
		// send from client, so send to host
		this->_host->get_message(str);
	}
	else if(this->_host == p)
	{
		// send from host, so send to client
		this->_client->get_message(str);
	}
	else
	{

	}
}

houseMediator::~houseMediator()
{
	if(this->_host)
	{
		delete this->_host;
		this->_host = NULL;
	}
	if(this->_client)
	{
		delete this->_client;
		this->_client = NULL;
	}
}
