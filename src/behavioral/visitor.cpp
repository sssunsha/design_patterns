/*

 访问者模式就是表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。

 抽象访问者（Visitor）角色：声明了一个或者多个访问操作，形成所有的具体元素角色必须实现的接口。

具体访问者（ConcreteVisitor）角色：实现抽象访问者角色所声明的接口，也就是抽象访问者所声明的各个访问操作。

抽象节点（Element）角色：声明一个接受操作，接受一个访问者对象作为一个参量。

具体节点（ConcreteElement）角色：实现了抽象元素所规定的接受操作。

结构对象（ObiectStructure）角色：有如下的一些责任，可以遍历结构中的所有元素；如果需要，提供一个高层次的接口让访问者对象可以访问每一个元素；
如果需要，可以设计成一个复合对象或者一个聚集，如列（List）或集合（Set）。
 */

#include "visitor.h"

using namespace std;

void visitor_setup()
{
	cout << endl;
	cout << "welcome to the demo for visitor design pattern ..."<< endl;
}
void visitor_run()
{
	cout << "create the employee list first" << endl;
	employees* elist = new employees();

	cout << "create three employee and attache to the list"<< endl;
	elist->attach( new employee( "Tom", 25000.0, 14 ) );
	elist->attach( new employee( "Thomas", 35000.0, 16 ) );
	elist->attach( new employee( "Roy", 45000.0, 21 ) );

	cout << "create the income vacation and showall visitor"<< endl;
	income_visitor *v1 = new income_visitor();
	vaction_visitor *v2 = new vaction_visitor();
	showall_visitor* showall = new showall_visitor();
	cout << "first show all the element of the list"<< endl;
	cout << endl;
	elist->accept(showall);
	cout << endl;
	cout << "do the operation with the tow visitor"<< endl;

	elist->accept(v1);
	elist->accept(v2);

	delete elist;
	elist = NULL;

	delete v1;
	v1 = NULL;
	delete v2;
	v2 = NULL;
	delete showall;
	showall = NULL;
}
void visitor_clean()
{

}

// codes for the demo of visitor design pattern


