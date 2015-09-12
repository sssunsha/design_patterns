/*
 * 模板方法(Template Method)模式： 定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。使得子类可以不改变一个算法的结构而重定义该算法的某些特定步骤。

 模板模式是为了巧妙解决变化对系统带来的影响而设计的。

结构：
	1） 抽象类： 定义一到多个抽象方法，让子类来实现，而且还要实现一个模板方法，来定义一个算法的骨架， 该模板方法不仅仅调用前面的抽象方法，
	也可以调用其他的操作，只要完成自身的使命。

	2） 具体类：实现父类中的抽象方法，完成算法中与特定子类相关的步骤。
 */


#include "template_method.h"
using namespace std;

void template_method_setup()
{
	cout << endl;
	cout << "welcome to the demo for template method design pattern"<< endl;
	cout << endl;

}
void template_method_run()
{
	cout << "start to create data, mom and son with family class"<< endl;
	family* daddy = new dad();
	family* mommy = new mom();
	family* me = new son();
	cout << endl;
	cout << "now father will start the supper"<< endl;
	daddy->super();
	cout << "now mother will start the supper"<< endl;
	mommy->super();
	cout << "now I will start the supper"<< endl;
	me->super();


	delete daddy;
	daddy = NULL;
	delete mommy;
	mommy = NULL;
	delete me;
	me = NULL;
}
void template_method_clean()
{

}

// demo codes for template_method design pattern
void family::super(){
	this->drink();
	this->eat();
}

void dad::drink(){
	cout << endl;
	cout << "Dad want some wine ..." << endl;
}

void dad::eat(){
	cout << "Dad want some beaf ..." << endl;
	cout << endl;
}

void mom::drink(){
	cout << endl;
	cout << "mom want some juice ... "<< endl;
}

void mom::eat(){
	cout << "mom eat nothing ..."<< endl;
	cout << endl;
}

void son::drink(){
	cout << endl;
	cout << "son drink some milk ..." << endl;
}

void son::eat(){
	cout << "son eat some vegetable ..." << endl;
	cout << endl;
}
