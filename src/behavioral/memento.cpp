/*
 * 备忘录模式定义： 在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态，
 * 这样以后就可以将该对象恢复到原来保存的状态。
 */

#include "memento.h"
using namespace std;

void memento_setup()
{
	cout << endl;
	cout << "welcome to the demo for memento design pattern ..."<< endl;
	cout << endl;
}
void memento_run()
{
	// first create the game
	cout << "first create the game object"<< endl;
	game* g = new game();
	cout << "set the first record data = 100" << endl;
	g->saveMemento(100);
	cout << "set the second record data = 200" << endl;
	g->saveMemento(200);
	cout << "set the third record data = 300" << endl;
	g->saveMemento(300);

	cout << "get the first record data = "<< g->loadMemento(0)<<endl;
	cout << "get the second record data = "<< g->loadMemento(1)<<endl;
	cout << "get the third record data = "<< g->loadMemento(2)<<endl;

	delete g;
	g = NULL;

}
void memento_clean()
{

}

// demo codes for memento design pattern

gameMemento::gameMemento(int d){

	cout << "crate new game memento, data = "<< d << endl;
	cout << endl;
	data = d;
}

int gameMemento::get(){
	return data;
}

//

mementoManager::mementoManager(){
	this->_array = new vector<gameMemento*>;
}

mementoManager::~mementoManager(){
	for(vector<gameMemento*>::iterator it=_array->begin(); it != _array->end(); )
	{
		gameMemento* p = *it;
		_array->erase(it);
		delete p;
		p = NULL;
	}

	delete _array;
	_array = NULL;
}

void mementoManager::addMemento(int d){

	// first create a new memnto
	gameMemento* m = new gameMemento(d);
	// then insert the new memento to the array
	this->_array->push_back(m);
}


int mementoManager::loadMemento(int index){
	if((int)this->_array->size() > index){
		gameMemento* m = this->_array->at(index);
		return m->get();
	}
	else
	{
		return -200;
	}
}

//
game::game(){
	this->_manager = new mementoManager();
}

game::~game(){
	delete this->_manager;
	this->_manager = NULL;
}

void game::saveMemento(int data){
	this->_manager->addMemento(data);
}


int game::loadMemento(int index){
	return this->_manager->loadMemento(index);
}
