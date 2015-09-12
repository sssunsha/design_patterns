
/*
 * 为其他对象提供一种代理以控制对这个对象的访问。说白了就是,在一些情况下客户不想或
 者不能直接引用一个对象,而代理对象可以在客户和目标对象之间起到中介作用,去掉客户不能看到的内容和服务或者增添客户需要的额外服务。
 *
 */

/*
 * 代理模式中的“代理商”要想实现代理任务,就必须和被代理的“厂商”使用共同的接口(你可以想象为产品)。于是代理模式就有三个角色组成了:
	1) 抽象主题角色:声明了真实主题和代理主题的共同接口。
	2) 代理主题角色:内部包含对真实主题的引用,并且提供和真实主题角色相同的接口。
	3) 真实主题角色:定义真实的对象。
 *
 */

#include "proxy.h"
using namespace std;


void proxy_setup()
{
	cout << endl;
	cout << "start to show proxy design pattern"<< endl;
	cout << endl;
}

void proxy_clean()
{

}

void proxy_run()
{
	// create the forumproxy to use
	cout << "create a forum with forumProxy to use"<< endl;
	forum* f = new forumProxy();
	cout << endl;
	cout << "set as login permission to add a new subject." << endl;
	cout << endl;
	f->add_subject(ELOGIN);
	cout << "read a subject as login permission"<< endl;
	cout << endl;
	f->read_subject(ELOGIN);
	cout<< "set as non login permission to add a new subject." << endl;
	cout << endl;
	f->add_subject(ENOLOGIN);
	cout << "read a subject as non-login permission" << endl;
	cout << endl;
	f->read_subject(ENOLOGIN);
	delete f;
	f = NULL;
}

// demo codes for proxy desgin pattern


void myForum::add_subject(EPERMISSION e){
	if(e == 0)
	{
		// did not login, so can not add a new subject
		cout<< "did not login, so can not add a new subject" << endl;
		cout << endl;
	}
	else
	{
		cout << "add new subject succeed !" << endl;
		cout << endl;
	}
}

void myForum::read_subject(EPERMISSION e){
	cout << "read a subject ... " << endl;
	cout << endl;
}


forumProxy::forumProxy(){
	this->real_forum = new myForum();
}

forumProxy::~forumProxy(){
	delete this->real_forum;
	this->real_forum = NULL;
}

void forumProxy::add_subject(EPERMISSION e){
	if(this->real_forum)
	{
		this->real_forum->add_subject(e);
	}
}

void forumProxy::read_subject(EPERMISSION e){
	if(this->real_forum)
	{
		this->real_forum->read_subject(e);
	}
}
