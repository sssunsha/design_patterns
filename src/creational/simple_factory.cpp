/*
 * 简单工厂模式

有三个部分组成：

1）工厂类角色： 含有一定的商业逻辑和判断，往往由一个具体类实现

2） 抽象类角色： 一般是具有产品继承的父类或者接口， 一般由接口或者抽象类来实现。

3） 具体产品角色： 由一个具体的类来实现，一般生成的产品就是这个类的实例。

三者之间的关系是：

本模式实现了简单的工厂方法，但缺点还是很明显的，每次改动都要重新更新工厂类的逻辑判断，并且所有的构造工作都是由一个单一的工厂类来负责
 *
 */

#include "simple_factory.h"
#include "string.h"
using namespace std;

void simple_factory_setup()
{
	cout << endl;
	cout << "start to show the simple factory design pattern"<< endl;
	cout << endl;
}

void simple_factory_run()
{
	customer1::getcar();
}

void simple_factory_clean()
{

}

/*
 * demo codes for simple factory
 */


/*
 * detail car product
 */
void benz1::drive(){
	cout << "driving Benz ... " << endl;
}

void bmw1::drive(){
	cout << "driving BMW ... " << endl;
}

void audi1::drive(){
	cout << "driving Audi ..." << endl;
}


/*
 *  driver, I am the man to get the car customer want
 */
Car1* driver1::drive(const char* car_name){

	if(strcmp("benz", car_name) == 0)
	{
		// drive the benz car please
		return new benz1();
	}

	if(strcmp("bmw", car_name) == 0)
	{
		// drive the bmw car please
		return new bmw1();
	}

	if(strcmp("audi", car_name) == 0)
	{
		// drive the audi car please
		return new audi1();
	}
	return NULL;
}


// I am the customer I just want a car ,I do not care how it create
void customer1::getcar(){
	cout << "I am the customer ..." << endl;

	cout << endl;
	cout << "I want the BMW ..." << endl;
	// get the BMW
	const char* car_name_bmw = "bmw";
	const char* car_name_audi = "audi";
	const char* car_name_benz = "benz";
	Car1* car = driver1::drive(car_name_bmw);
	if(car){
		car->drive();
		delete car;
		car = NULL;
	}

	cout << endl;
	cout << "I want the Benz ..." << endl;
	// get the Benz
	car = driver1::drive(car_name_benz);
	if(car){
		car->drive();
		delete car;
		car = NULL;

	}

	cout << endl;
	cout << "I want the audi ..." << endl;
	// get the Audi
	car = driver1::drive(car_name_audi);
	if(car){
		car->drive();
		delete car;
		car = NULL;
	}

}

/*
 * 下面我们从开闭原则(对扩展开放;对修改封闭)上来分析下简单工厂模式。当暴发户
增加了一辆车的时候,
只要符合抽象产品制定的合同,
那么只要通知工厂类知道就可以被客
户使用了。所以对产品部分来说,它是符合开闭原则的;但是工厂部分好像不太理想,因为
每增加一辆车,
都要在工厂类中增加相应的业务逻辑或者判断逻辑,
这显然是违背开闭原则
的。可想而知对于新产品的加入,工厂类是很被动的。对于这样的工厂类(在我们的例子中
是为司机师傅)
,我们称它为全能类或者上帝类。
我们举的例子是最简单的情况,
而在实际应用中,
很可能产品是一个多层次的树状结构。
由于简单工厂模式中只有一个工厂类来对应这些产品,所以这可能会把我们的上帝累坏了,
也累坏了我们这些程序员:(
于是工厂方法模式作为救世主出现了。
 *
 */
