/*
 * 将抽象部分与它的实现部分分离,使它们都可以独立地变化。
	这里的抽象部分和实现部分不是我们通常认为的父类与子类、接口与实现类的关系,而是组合关系。也就是说,实现部分是被抽象部分调用,以用来完成(实现)
抽象部分的功能。

在《Thinking in Patterns with Java》一书中,作者将抽象部分叫做“front-end”(权且翻译为“前端”),而实现部分叫做“back-end”(后端)
。这种叫法要比抽象实现什么的好理解
多了。


1) 抽 象 ( Abstraction ) 角 色 : 它 定 义 了 抽 象 类 的 接 口 而 且 维 护 着 一 个 指 向 实 现(Implementor)角色的引用。
2) 精确抽象(RefinedAbstraction)角色:实现并扩充由抽象角色定义的接口。
3) 实现(Implementor)角色:给出了实现类的接口,这里的接口与抽象角色中的接口可以不一致。
4) 具体实现(ConcreteImplementor)角色:给出了实现角色定义接口的具体实现。

 *
 */




//Bridge模式将继承关系转换为组合关系，从而降低了系统间的耦合，减少了代码编写量。

#include "bridge.h"

void bridge_setup()
{
	cout << endl;
	cout << "start to show bridge design pattern"<< endl;
	cout << endl;

}

void bridge_clean()
{
// I first want a ibm pc with linux system
	cout << "I first want a ibm pc with linux system" << endl;
	cout << endl;
	pc* p_pc = new ibm();
	os* p_os = new Linux();
	p_pc->install(p_os);
	delete p_pc;
	p_pc = NULL;
	delete p_os;
	p_os = NULL;

	cout << endl;
	cout << "I then want a dell pc with windows system" << endl;
	p_pc = new dell();
	p_os = new Windows();
	p_pc->install(p_os);
	delete p_pc;
	p_pc = NULL;
	delete p_os;
	p_os = NULL;


}

void bridge_run()
{

}

// demo codes for bridge design pattern

void hp::install(os* system){
	if(system)
	{
		cout << " HP -->";
		system->run();
	}
}

void dell::install(os* system){
	if(system)
	{
		cout << " Dell -->";
		system->run();
	}
}

void ibm::install(os* system){
	if(system)
	{
		cout << " IBM -->";
		system->run();
	}
}

