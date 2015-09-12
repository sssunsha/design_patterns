/*

 使多个对象都有机会处理请求,从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链,并沿着这条链传递该请求,直到有一
个对象处理它为止。

呵呵,从定义上可以看出,责任链模式的提出是为了“解耦”,以应变系统需求的变更和不明确性。

责任链模式由两个角色组成:
1) 抽象处理者角色(Handler) 它定义了一个处理请求的接口。当然对于链子的不同实现,也可以在这个角色中实现后继链。
2) 具体处理者角色(Concrete Handler):实现抽象角色中定义的接口,并处理它所负责的请求。如果不能处理则访问它的后继者。




 */

#include "cr.h"

void cr_setup()
{
	cout << endl;
	cout << "welcome to the demo of chain of responsibility" << endl;
	cout << endl;
}

void cr_run()
{
	cout << "create the three task handler "<< endl;
	task_handler* name =  new name_handler();
	task_handler* job = new job_handler();
	task_handler* partment = new partment_handler();
	cout << "make the three task handler as a chain" << endl;
	name->set_next(job);
	job->set_next(partment);
	cout << "create a namecard"<< endl;
	namecard* card = new namecard();
	cout << "start to handler the task for name card"<< endl;
	name->handle(card);
	cout << "print the name card after finish work"<< endl;
	cout << endl;
	card->get_data();

	delete name; name = NULL;
	delete job; job = NULL;
	delete partment; partment = NULL;
	delete card; card = NULL;
}

void cr_clean()
{

}


// demo codes for chain of Responsibility
namecard::~namecard()
{
}

void namecard::get_data(){
	cout << endl;
	cout << "name = "<< this->_name << ", job = " << this->_job << ", partment = " << this->_partment << endl;
	cout << endl;
}

void namecard::set_job(string str){
	this->_job = str;
}

void namecard::set_name(string str){
	this->_name = str;
}

void namecard::set_partment(string str){
	this->_partment = str;
}


void name_handler::handle(namecard* nc){
	nc->set_name("will");
	cout << endl;
	cout << "finish partment work, send to next handler"<< endl;
	nc->get_data();

	if(this->next)
	{
		this->next->handle(nc);
	}
}

void name_handler::set_next(task_handler* h){
	if(h)
	{
		this->next = h;
	}
}

void job_handler::handle(namecard* nc){
	nc->set_job("developer");
	cout << endl;
	cout << "finish partment work, send to next handler"<< endl;
	nc->get_data();

	if(this->next)
	{
		this->next->handle(nc);
	}
}

void job_handler::set_next(task_handler* h){
	if(h)
	{
		this->next = h;
	}
}

void partment_handler::handle(namecard* nc){
	nc->set_partment("app framework");
	cout << endl;
	cout << "finish partment work, send to next handler"<< endl;
	nc->get_data();

	if(this->next)
	{
		this->next->handle(nc);
	}
}

void partment_handler::set_next(task_handler* h){
	if(h)
	{
		this->next = h;
	}

}
