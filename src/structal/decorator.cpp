/*
 * 装饰模式(Decorator)也叫包装器模式(Wrapper)。GOF 在《设计模式》一书中给出
	的定义为:动态地给一个对象添加一些额外的职责。就增加功能来说,Decorator 模式相比生成子类更为灵活。
 *
 */

/*
 * 	1) 抽象构件角色(Component):定义一个抽象接口,以规范准备接收附加责任的对象。
	2) 具体构件角色(Concrete Component):这是被装饰者,定义一个将要被装饰增加功能的类。
	3) 装饰角色(Decorator):持有一个构件对象的实例,并定义了抽象构件定义的接口。
	4) 具体装饰角色(Concrete Decorator):负责给构件添加增加的功能。
 *
 */

/*
 * 整个装饰模式的结构是按照组合模式来实现的——两者都有类似的结构图 , 都基于递归组合来组织可变数目的对象 。但是两者的目的是截然不同的 ,
 * 组合(Composite)模式侧重通过递归组合构造类,使不同的对象、多重的对象可以“一视同仁”;而装饰(Decorator)模式仅仅是借递归组合来达到定义中的目的。
 *
 */

#include "decorator.h"
using namespace std;

void decorator_setup()
{
	cout << endl;
	cout << "welcome to decorator(wrapper) design pattern ..." << endl;
	cout << endl;
}

void decorator_clean()
{

}

void decorator_run()
{
	// create a new alarm door based on the normal door
	cout << endl;
	cout << "create a new alarm door based on the normal door" << endl;
	cout << endl;
	door* normal_door = new normalDoor();
	alarmDoorDecorator* alarm_door = new alarmDoor(normal_door);

	cout << "open the door please:"<< endl;
	alarm_door->open();
	cout << "close the door please:" << endl;
	alarm_door->close();
	cout << "press the ring one the door please:" << endl;
	alarm_door->alarm();

	//
	// here we can not use the new added function alarm in normal_door
	//

	delete alarm_door;
	alarm_door = NULL;
}

// demo codes for decorator (wrapper) design pattern


void normalDoor::close(){
	cout << endl;
	cout << "door is [closed] ." << endl;
	cout << endl;
}

void normalDoor::open(){
	cout << endl;
	cout << "door is [opened] ." << endl;
	cout << endl;
}




void alarmDoorDecorator::open(){
	if(this->_door)
	{
		this->_door->open();
	}
}

void alarmDoorDecorator::close(){
	if(this->_door)
	{
		this->_door->close();
	}
}

alarmDoorDecorator::~alarmDoorDecorator()
{
	delete this->_door;
	this->_door = NULL;
}

alarmDoorDecorator::alarmDoorDecorator(door* d){
	this->_door = d;
}




alarmDoor::alarmDoor(door* d):alarmDoorDecorator(d){

}

void alarmDoor::alarm(){
	cout << endl;
	cout<< "door is [alarm] ." << endl;
	cout << endl;
}
