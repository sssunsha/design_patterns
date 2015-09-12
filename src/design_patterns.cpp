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
#include "./structal/proxy.h"
#include "./structal/decorator.h"
#include "./structal/facade.h"
#include "./structal/flyweight.h"

#include "./behavioral/template_method.h"
#include "./behavioral/interpreter.h"
#include "./behavioral/command.h"
#include "./behavioral/memento.h"
#include "./behavioral/observer.h"
#include "./behavioral/state.h"
#include "./behavioral/strategy.h"
#include "./behavioral/cr.h"
#include "./behavioral/mediator.h"
#include "./behavioral/visitor.h"



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
		cout << " ------------------------------------------------------------ " << endl;
		cout << "adapter (适配器模式) ----------------------------------------- 7" << endl;
		cout << "bridge (桥梁模式) -------------------------------------------- 8" << endl;
		cout << "composite (组合模式) ----------------------------------------- 9" << endl;
		cout << "proxy (代理模式) -------------------------------------------- 10" << endl;
		cout << "decorator (装饰模式，包装器模式，wrapper) ------------------- 11" << endl;
		cout << "facade (门面模式) ------------------------------------------- 12" << endl;
		cout << "flyweight (享元模式) -----------------------------------------13" << endl;
		cout << " ------------------------------------------------------------ " << endl;
		cout << "template method (模版方法模式) ------------------------------ 14" << endl;
		cout << "interpreter (解释器模式) ------------------------------------ 15" << endl;
		cout << "command (命令模式) ------------------------------------------ 16" << endl;
		cout << "memento (备忘录模式) ---------------------------------------- 17" << endl;
		cout << "observer (观察者模式) --------------------------------------- 18" << endl;
		cout << "state (状态模式) -------------------------------------------- 19" << endl;
		cout << "strategy (策略模式) ----------------------------------------- 20" << endl;
		cout << "Chain of Responsibility (责任链模式) ------------------------ 21" << endl;
		cout << "Mediator (中介者模式) --------------------------------------- 22" << endl;
		cout << "Visitor (访问者模式) ---------------------------------------- 23" << endl;
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
		case 10:
			cout << "start the proxy design pattern show" << endl;
			proxy_setup();
			proxy_run();
			proxy_clean();
			break;
		case 11:
			cout << "start the decorator(wrapper) design pattern show" << endl;
			decorator_setup();
			decorator_run();
			decorator_clean();
			break;
		case 12:
			cout << "start the facade design pattern show" << endl;
			facade_setup();
			facade_run();
			facade_clean();
			break;
		case 13:
			cout << "start the flyweight design pattern show" << endl;
			flyweight_setup();
			flyweight_run();
			flyweight_clean();
			break;
		case 14:
			cout << "start the template method design pattern show" << endl;
			template_method_setup();
			template_method_run();
			template_method_clean();
			break;
		case 15:
			cout << "start the interpreter design pattern show" << endl;
			interpreter_setup();
			interpreter_run();
			interpreter_clean();
			break;
		case 16:
			cout << "start the command design pattern show" << endl;
			command_setup();
			command_run();
			command_clean();
			break;
		case 17:
			cout << "start the memento design pattern show" << endl;
			memento_setup();
			memento_run();
			memento_clean();
			break;
		case 18:
			cout << "start the observer design pattern show" << endl;
			observer_setup();
			observer_run();
			observer_clean();
			break;
		case 19:
			cout << "start the state design pattern show" << endl;
			state_setup();
			state_run();
			state_clean();
			break;
		case 20:
			cout << "start the strategy design pattern show" << endl;
			strategy_setup();
			strategy_run();
			strategy_clean();
			break;
		case 21:
			cout << "start the chain of Responsibility design pattern show" << endl;
			cr_setup();
			cr_run();
			cr_clean();
			break;
		case 22:
			cout << "start the mediator design pattern show" << endl;
			mediator_setup();
			mediator_run();
			mediator_clean();
			break;
		case 23:
			cout << "start the visitor design pattern show" << endl;
			visitor_setup();
			visitor_run();
			visitor_clean();
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
