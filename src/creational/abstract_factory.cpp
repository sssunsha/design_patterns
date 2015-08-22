/*
 * 抽象工厂模式的用意为:给客户端提供一个接口,可以创建多个产品族中的产品对象
而且使用抽象工厂模式还要满足一下条件:
1) 系统中有多个产品族,而系统一次只可能消费其中一族产品。
2) 同属于同一个产品族的产品以其使用。
来看看抽象工厂模式的各个角色(和工厂方法的如出一辙)
:
1) 抽象工厂角色: 这是工厂方法模式的核心,它与应用程序无关。是具体工厂角色必须
实现的接口或者必须继承的父类。在 java 中它由抽象类或者接口来实现。
2) 具体工厂角色:
它含有和具体业务逻辑有关的代码。
由应用程序调用以创建对应的具体
产品的对象。在 java 中它由具体的类来实现。
3) 抽象产品角色:它是具体产品继承的父类或者是实现的接口。在 java 中一般有抽象类
或者接口来实现。
4) 具体产品角色:具体工厂角色所创建的对象就是此角色的实例。在 java 中由具体的类
来实现。
 *
 */

#include "abstract_factory.h"
using namespace std;

void abstract_factory_setup()
{
	cout << endl;
	cout << "start to show abstract factory design pattern"<< endl;
	cout << endl;

}

void abstract_factory_run()
{
	customer3::getcar();
}

void abstract_factory_clean()
{

}


// demo codes for abstract factory design pattern

// product part
void bmwSportCar::drive(){
	cout << "driving BMW sport car ..."<< endl;
}

void bmwBussinessCar::drive(){
	cout << "driving BMW bussiness car ..."<< endl;
}

void audiSportCar::drive(){
	cout << "driving Audi sport car ..."<< endl;
}

void audiBussinessCar::drive(){
	cout << "driving Audi bussiness car ..."<< endl;
}

// factory part
Car3* bmwDriver::driveBussinessCar(){
	return new bmwBussinessCar();
}

Car3* bmwDriver::driveSportCar(){
	return new bmwSportCar();
}

Car3* audiDriver::driveBussinessCar(){
	return new audiBussinessCar();
}

Car3* audiDriver::driveSportCar(){
	return new audiSportCar();
}

void customer3::getcar(){

	cout << "I am the customer ..." << endl;
	Driver3* d = NULL;
	Car3* car = NULL;

	// i want a audi sport car
	cout << endl;
	cout << "I want a Audi sport car"<<endl;
	cout << endl;
	d = new audiDriver();
	if(d)
	{
		car = d->driveSportCar();
		if(car)
		{
			car->drive();
			delete car;
			car = NULL;
		}
		delete d;
		d = NULL;
	}

	// i want a bmw bussines car
	cout << endl;
	cout << "I want a BMW bussiness car"<<endl;
	cout << endl;
	d = new bmwDriver();
	if(d)
	{
		car = d->driveBussinessCar();
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

