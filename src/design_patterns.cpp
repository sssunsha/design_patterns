//============================================================================
// Name        : design_patterns.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "include.h"

#include "./creational/factory_method.h"
#include "./creational/simple_factory.h"
#include "./creational/abstract_factory.h"
#include "./creational/singleton.h"
#include "./creational/prototype.h"
#include "./creational/builder.h"

#include "./structal/adapter.h"
#include "./structal/bridge.h"
#include "./structal/composite.h"
using namespace std;

int main() {
	cout << endl;
	cout << "welcome to the demo design patterns" << endl;
	cout << endl;
	setup();
	return 0;
}

void setup()
{
	int index = 0;
	do{
		setup:
		cout << endl;
		cout << "please choose with the demo menu" << endl;
		cout << "simple factory（简单工厂模式）-------------------------------- 1" << endl;
		cout << "factory method (工厂方法模式) -------------------------------- 2"<< endl;
		cout << "abstract factory (抽象工厂模式) ------------------------------ 3"<< endl;
		cout << "singleton (单例模式) ----------------------------------------- 4"<<endl;
		cout << "prototype (原型模式) ----------------------------------------- 5" << endl;
		cout << "builder (建造者模式) ----------------------------------------- 6" << endl;
		cout << "adapter (适配器模式) ----------------------------------------- 7" << endl;
		cout << "bridge (桥梁模式) -------------------------------------------- 8" << endl;
		cout << "composite (组合模式) -------------------------------------------- 9" << endl;
		cout << "exit --------------------------------------------------------- 0"<< endl;
		cin >> index;
		switch(index)
		{
		case 0:
			break;
		case 1:
			cout << "start the simple factory design pattern show" << endl;
			simple_factory_setup();
			simple_factory_run();
			simple_factory_clean();
			break;
		case 2:
			cout << "start the factory method design pattern show" << endl;
			factory_method_setup();
			factory_method_run();
			factory_method_clean();
			break;
		case 3:
			cout << "start the abstract factory design pattern show" << endl;
			abstract_factory_setup();
			abstract_factory_run();
			abstract_factory_clean();
			break;
		case 4:
			cout << "start the singleton design pattern show" << endl;
			singleton_setup();
			singleton_run();
			singleton_clean();
			break;
		case 5:
			cout << "start the prototype design pattern show" << endl;
			prototype_setup();
			prototype_run();
			prototype_clean();
			break;
		case 6:
			cout << "start the builder design pattern show" << endl;
			builder_setup();
			builder_run();
			builder_clean();
			break;
		case 7:
			cout << "start the adapter design pattern show" << endl;
			adapter_setup();
			adapter_run();
			adapter_clean();
			break;
		case 8:
			cout << "start the bridge design pattern show" << endl;
			bridge_setup();
			bridge_run();
			bridge_clean();
			break;
		case 9:
			cout << "start the composite design pattern show" << endl;
			composite_setup();
			composite_run();
			composite_clean();
			break;

		default:
			cout << "the input is incorrect, please choose again"<< endl;
			goto setup;
			break;
		}
	}while(index != 0);
}

void clean()
{

}
