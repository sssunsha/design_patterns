/*
 * 为子系统中的一组接口提供一个一致的界面, Facade模式定义了一个高层接口,这个接口使得这一子系统更加容易使用。
 *
 *1)门面角色(facade):这是门面模式的核心。它被客户角色调用,因此它熟悉子系统的
	功能。它内部根据客户角色已有的需求预定了几种功能组合。这样就减少了客户程序和子系统之间的耦合,增加了可维护性。
	很明显,门面模式有三个角色组成:
  2)子系统角色:实现了子系统的功能。对它而言,facade角色就和客户角色一样是未知的,它没有任何facade角色的信息和链接。
  3)客户角色:调用facade角色来完成要得到的功能。
 *
 *
 *
 *
 *
 *
 * Facade 模式的一个典型应用就是进行数据库连接。一般我们在每一次对数据库进行访问,都要进行以下操作:先得到 connect 实例,然后打开 connect 获得连接,得到一个
	statement,执行 sql 语句进行查询,得到查询结果集。我们可以将这些步骤提取出来,封装在一个类里面。这样,每次执行数据库访问只需要
	将必要的参数传递到这个类中就可以了。
 *
 */

#include "facade.h"
using namespace std;

void facade_setup()
{
	cout << endl;
	cout << "welcome to facade design pattern demo ..."<< endl;
	cout << endl;
}
void facade_run()
{
	// first create the computer
	cout << "first create the computer"<< endl;
	computer* pc = new computer();
	cout << endl;
	cout << "turn on the pc"<< endl;
	pc->computer_on();
	cout << "turn off the pc"<< endl;
	pc->computer_off();
	delete pc;
	pc = NULL;
}
void facade_clean()
{

}

// demo codes for facade design pattern
void screen::screen_off(){
	cout<< "screen turn [off]" << endl;
}

void screen::screen_on(){
	cout<< "screen turn [on]" << endl;
}

void mainboard::mainboard_on(){
	cout << "mainboard turn [on]" << endl;
}

void mainboard::mainboard_off(){
	cout << "mainboard turn [off]" << endl;
}

void fan::fan_on(){
	cout << "fan turn [on]" << endl;
}

void fan::fan_off(){
	cout << "fan turn [off]" << endl;
}

void otherDevices::otherDevices_on(){
	cout<< "other devices turn [on]" << endl;
}

void otherDevices::otherDevices_off(){
	cout << "other devices turn [off]" << endl;
}


// facade
computer::computer(){
	this->m_screen = new screen();
	this->m_mainboard = new mainboard();
	this->m_fan = new fan();
	this->m_otherDevices = new otherDevices();
}

computer::~computer(){
	delete this->m_screen;
	this->m_screen = NULL;
	delete this->m_mainboard;
	this->m_mainboard = NULL;
	delete this->m_fan;
	this->m_fan = NULL;
	delete this->m_otherDevices;
	this->m_otherDevices = NULL;
}

void computer::computer_on(){
	cout << endl;
	this->m_screen->screen_on();
	this->m_mainboard->mainboard_on();
	this->m_fan->fan_on();
	this->m_otherDevices->otherDevices_on();
	cout << endl;
}

void computer::computer_off(){
	cout << endl;
	this->m_screen->screen_off();
	this->m_mainboard->mainboard_off();
	this->m_fan->fan_off();
	this->m_otherDevices->otherDevices_off();
	cout << endl;
}
