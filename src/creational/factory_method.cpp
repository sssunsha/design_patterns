/*
 * 工厂方法模式

工厂方法模式去掉了简单工厂模式中工厂方法的静态属性，使得它可以被子类继承。这样在简单工厂模式里集中在工厂方法上的压力可以由工厂方法模式里不同的工厂子类来分担。

相比之前，工厂方法模式有四个部分组成：

1）抽象工厂角色：这是工厂方法模式的核心，它与应用程序无关。是具体工厂角色必须实现的接口或者必须继承的父类。一般由接口或者抽象类来实现。

2） 具体工厂角色：它含有和具体业务逻辑有关的代码。由应用程序调用以创建对应的具体产品的对象。

3） 抽象产品角色：它是具体产品继承的父类或者是实现的接口

4） 具体产品角色：具体工厂角色所创建的对象就是此角色的实例

!!! 注意和简单工程模式在 1） 和 2）上的区别！！！！！！！！！！！！！！！！！！！！！！！！！！！！
 */

#include "factory_method.h"
using namespace std;

void factory_method_setup()
{
	cout << endl;
	cout << "start to show the factory method design pattern"<< endl;
	cout << endl;

}

void factory_method_clean()
{

}

void factory_method_run()
{
	customer2::getcar();
}

// demo codes for factory method

// car part
void benz2::drive(){
	cout << "driving Benz ..." << endl;
}

void bmw2::drive(){
	cout << "driving BMW ..." << endl;
}

void audi2::drive(){
	cout << "driving Audi ..." << endl;
}

// driver part
Car2* benzDriver2::drive(){
	return new benz2();
}

Car2* bmwDriver2::drive(){
	return new bmw2();
}

Car2* audiDriver2::drive(){
	return new audi2();
}

// customer part (the factory method user)
void customer2::getcar(){

	cout << "I am the customer ..." << endl;
	Driver2* d = NULL;
	Car2* car = NULL;

	// get the BMW
	cout << endl;
	cout << "I want the BMW ..." << endl;
	cout << endl;

	d = new bmwDriver2();
	if(d)
	{
		car = d->drive();
		if(car)
		{
			car->drive();
			delete car;
			car = NULL;
		}
		delete d;
		d = NULL;
	}

	// get the benz
	cout << endl;
	cout << "I want the Benz ..." << endl;
	cout << endl;

	d = new benzDriver2();
	if(d)
	{
		car = d->drive();
		if(car)
		{
			car->drive();
			delete car;
			car = NULL;
		}
		delete d;
		d = NULL;
	}

	// get the audi
	cout << endl;
	cout << "I want the audi ..." << endl;
	cout << endl;

	d = new audiDriver2();
	if(d)
	{
		car = d->drive();
		if(car)
		{
			car->drive();
			delete car;
			car = NULL;
		}
		delete d;
		d = NULL;
	}
}

/*
 * 可以看出工厂方法的加入,使得对象的数量成倍增长。当产品种类非常多时,会出现大
量的与之对应的工厂对象,这不是我们所希望的。因为如果不能避免这种情况,可以考虑使
用简单工厂模式与工厂方法模式相结合的方式来减少工厂类:即对于产品树上类似的种类
(一般是树的叶子中互为兄弟的)使用简单工厂模式来实现。
 *
 */
