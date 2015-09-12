/*
 * 组合(Composite)模式的其它翻译名称也很多,比如合成模式、树模式等等。在《设计模式》一书中给出的定义是:
	将对象以树形结构组织起来,以达成“部分-整体”的层次结构,使得客户端对单个对象和组合对象的使用具有一致性。
 *
 */

/*
 * 1) 抽象构件角色(Component):它为组合中的对象声明接口,也可以为共有接口实现缺省行为。
   2) 树叶构件角色(Leaf):在组合中表示叶节点对象——没有子节点,实现抽象构件角色声明的接口。
   3) 树枝构件角色(Composite):在组合中表示分支节点对象——有子节点,实现抽象构件角色声明的接口;存储子部件。
 *
 */

/*
 * 	五、优缺点
	从上面的举例中可以看到,组合模式有以下优点:
	1) 使客户端调用简单,客户端可以一致的使用组合结构或其中单个对象,用户就不必关心自己处理的是单个对象还是整个组合结构,这就简化了客户端代码。
	2) 更容易在组合体内加入对象部件. 客户端不必因为加入了新的对象部件而更改代码。这一点符合开闭原则的要求,对系统的二次开发和功能扩展很有利!
		当然组合模式也少不了缺点:组合模式不容易限制组合中的构件。
	六、总结
	组合模式是一个应用非常广泛的设计模式,在前面已经介绍过的解释器模式、享元模式中都是用到了组合模式。它本身比较简单但是很有内涵,
	掌握了它对你的开发设计有很大的帮助。
 *
 */
#include "composite.h"
using namespace std;


void composite_setup()
{
	cout << endl;
	cout << "welcome to the demo for composite design pattern" << endl;
	cout << endl;
}
void composite_run()
{
	cout << "create the 2 view group and 4 view" << endl;
	cout << endl;
	string str1 = "view1";
	string str2 = "view2";
	string str3 = "view3";
	string str4 = "view4";
	string str5 = "view5";

	view* v1 = new view(str1);
	view* v2 = new view(str2);
	view* v3 = new view(str3);
	view* v4 = new view(str4);
	view* v5 = new view(str5);

	viewGroup* g1 = new viewGroup();
	viewGroup* g2 = new viewGroup();

	cout << "insert view 1, view 2 and view3 to the group 1"<< endl;
	g1->addChild(v1);
	g1->addChild(v2);
	g1->addChild(v3);

	cout << "insert view 4 to the group 2"<< endl;
	g2->addChild(v4);

	cout << "insert view 5, view group 1 and view group 2 to the window" << endl;

	window* w = new viewGroup();
	w->addChild(v5);
	w->addChild(g1);
	w->addChild(g2);

	cout << endl;
	cout << "draw now ..." << endl;
	w->draw();

	cout << endl;
	cout << "now remove the view 3 from the view group of window system ..." << endl;
	w->removeChild(v3);
	cout << "draw again ...." << endl;
	cout << endl;
	w->draw();

	cout << "now remove the whole group 1, that means besides view group 1, both view 1 and view 2 will be delete too" << endl;
	w->removeChild(g1);
	cout << "draw again ..." << endl;
	cout << endl;
	w->draw();
	delete w;
	w = NULL;
}
void composite_clean()
{

}

// demo codes for composite design pattern

// composite
viewGroup::viewGroup(){
	this->group = new vector<window*>;
}

viewGroup::~viewGroup(){
	int i = 0;
	for(; i < (int)group->size(); i++)
	{
		delete group->at(i);
		group->at(i) = NULL;
	}

	delete group;
	group = NULL;
}

void viewGroup::addChild(window* v){
	// here need to think about how to check is the group or the view
	this->group->push_back(v);
}


void viewGroup::removeChild(window* v){

	// here need to think about how to check is the group or the view
	for(vector<window*>::iterator it=group->begin(); it != group->end(); )
	{
		window* w = (window*)*it;
		if(w == v)
		{
			// remove this window
			it = group->erase(it);
			delete w;
			w = NULL;

		}
		else
		{
			// check the view count first
			if(w->viewCount() > 0)
			{
				w->removeChild(v);
			}
			it++;
		}
	}
}

int viewGroup::viewCount(){
	return group->size();
}

void viewGroup::draw(){
	int i = 0;
	for(; i < (int)group->size(); i++)
	{
		group->at(i)->draw();
	}
}

// leaf
void view::draw(){
	cout << _name <<" is drawing" << endl;
}


 view::view(string name){
	_name = name;
}

 void view::addChild(window* v){
	 // do nothing for the view, this function is only useful for viewGroup
 }

 void view::removeChild(window* v){
	 // do nothing for the view, this function is only useful for viewGroup
 }

 int view::viewCount(){
	 // for view the view count is 0
	 return 0;
 }

