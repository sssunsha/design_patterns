/*
 * 单例模式的几个特点：
 * 1. 构造函数是private，禁止外部访问构造
 * 2. 声明一个静态的实例获取函数，一个静态的实例记录指针
 * 3. ...
 */
#include "singleton.h"
using namespace std;

void singleton_setup()
{
	cout << endl;
	cout << "start to show the singleton design pattern"<< endl;
	cout << endl;

}

void singleton_run()
{
	cout << "first get the instance of the singleton class" << endl;
	singleton* s = singleton::getInstance();
	cout << "show the number of the instance"<<endl;
	cout << "number is " << s->get_number() << endl;
	cout << "number plus" << endl; s->number_plus();
	cout << "number plus" << endl; s->number_plus();
	cout << "number is " << s->get_number() << endl;
	cout << "get another instance"<< endl;
	singleton* s1 = singleton::getInstance();
	cout << "number of the new instance is " << s1->get_number() << endl;
	cout << "delete the instance"<<endl;
	delete s;
	s = NULL;
	s1 = NULL;
	cout << "get the instance again"<< endl;
	s = singleton::getInstance();
	cout << "number of the new instance after delete is " << s->get_number() << endl;
//	delete s;
//	s = NULL;
}

void singleton_clean()
{

}


// demo codes for singleton design pattern
singleton* singleton::self = NULL;

singleton* singleton::getInstance()
{
	if(!singleton::self)
	{
		singleton::self = new singleton();
	}
	return singleton::self;
}

singleton::singleton(){
	number = 0;
}

void singleton::number_plus()
{
	this->number++;
}

int singleton::get_number()
{
	return this->number;
}
