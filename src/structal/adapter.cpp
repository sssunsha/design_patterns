/*
 * 将一个类的接口转换成客户希望的另外
一个接口。Adapter 模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。由
引子中给出的例子可知,这个定义描述的功能和现实中的适配器的功能是一致的。
 *
 *可以看出使用适配器模式是为了在面向接口编程中更好的复用。如果你的系统中没有使用
到面向接口编程,没有使用到多态,我想大概也不会使用到适配器模式。
 *
 *
 *下面来看看适配器模式的组成吧。
1) 目标(Target)角色:定义 Client 使用的接口。
2) 被适配(Adaptee)角色:这个角色有一个已存在并使用了的接口,而这个接口是需要我们适配的。
3) 适配器(Adapter)角色:这个适配器模式的核心。它将被适配角色已有的接口转换为目标角色希望的接口。
 *
 */
#include "adapter.h"

void adapter_setup()
{
	cout << endl;
	cout << "start to show adapter design pattern"<< endl;
	cout << endl;

}
void adapter_run()
{
	cout << "first create the target to use " << endl;
	target* t = new target();
	cout << endl;
	cout << "I want to draw a line ..."<< endl;
	t->draw_line();
	cout << "I want to draw a square ..."<< endl;
	t->draw_square();
	cout << "I want to draw a circle ..."<< endl;
	t->draw_circle();
	delete t;
	t = NULL;
}
void adapter_clean()
{

}


// demo codes for adapter design pattern
void circle::draw()
{
	if(this->circleHelp)
	{
		this->circleHelp->display(); //  这里就是适配转换的过程
	}
}


// 使用者
target::target()
{
	this->pcircle = new circle();
	this->pline = new line();
	this->psquare = new square();
}

target::~target()
{
	delete this->pcircle;
	this->pcircle = NULL;
	delete this->pline;
	this->pline = NULL;
	delete this->psquare;
	this->psquare = NULL;
}

void target::draw_circle(){
	this->pcircle->draw();
}

void target::draw_line(){
	this->pline->draw();
}

void target::draw_square(){
	this->psquare->draw();
}
