/*
 * GOF 给建造模式的定义为:将一个复杂对象的构建与它的表示分离,使得同样的构建
过程可以创建不同的表示。这句话说得很抽象,不好理解,其实它的意思可以理解为:将构
造复杂对象的过程和组成对象的部件解耦。就像攒电脑一样,不管什么品牌的配件,只要兼
容就可以装上;同样,一样的配件,可以有好多组装的方式。这是对降低耦合、提高可复用
性精神的一种贯彻。
当要生成的产品有复杂的内部结构——比如由多个对象组成;
而系统中对此产品的需求
将来可能要改变产品对象的内部结构的构成,比如说产品的一些属性现在由一个小对象组
成,而更改后的型号可能需要 N 个小对象组成;而且不能将产品的内部构造完全暴露给客
户程序,一是为了可用性,二是为了安全等因素。满足上面的设计环境就可以考虑使用建造
模式来搭建框架了。
 *
 */

/*
 * 来看看建造模式的组成吧。
	1) 抽象建造者角色:
	这个角色用来规范产品对象的各个组成成分的建造。一般而言,此角色独立于应用程序的业务逻辑。
	2) 具体建造者角色:
	担任这个角色的是于应用程序紧密相关的类,它们在指导者的调用下创建产品实例。这个角色在实现抽象建造者角色提供的方法的前提下,
	达到完成产品组装,提供成品的功能。
	3) 指导者角色:
	调用具体建造者角色以创建产品对象。指导者并没有产品类的具体知识,真正拥有产品类的具体知识的是具体建造者对象。
	4) 产品角色:
	建造中的复杂对象。它要包含那些定义组件的类,包括将这些组件装配成产品的接口。
 *
 */


#include "builder.h"
void builder_setup()
{
	cout << endl;
	cout << "start to show builder design pattern"<< endl;
	cout << endl;

}

void builder_run()
{
	cout << "first create the director " << endl;
	Direct* d = new Direct();
	cout << "second we want to install a laptop, so create a laptop builder " << endl;
	Builder* b = new laptopBuilder();
	cout << "set the laptop builder to the direct" << endl;
	d->set_builder(b);
	cout << "start to install a laptop"<< endl;
	d->start_builder();
	cout << endl;
	cout << "now we want to build a desktop"<< endl;
	d->free_builder();
	b = new desktopBuilder();
	d->set_builder(b);
	cout << endl;
	d->start_builder();
	d->free_builder();
	delete d;
	d = NULL;
}

void builder_clean()
{

}


// demo codes for builder design pattern
void Direct::set_builder(Builder* b)
{
	if(b)
	{
		if(builder)
		{
			delete builder;
			builder = NULL;
		}
		builder = b;
	}

}

void Direct::free_builder(){
	if(builder)
	{
		delete builder;
		builder = NULL;
	}
}

void Direct::start_builder()
{
	if(builder)
	{
		builder->install_cpu();
		builder->install_disk();
		builder->install_memory();
		builder->install_audio();
		builder->install_video();
		builder->install_others();
	}
}
