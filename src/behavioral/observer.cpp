#include "observer.h"

void observer_setup()
{
	cout << endl;
	cout << "welcome to the demo for observer design pattern" << endl;
	cout << endl;
}
void observer_run()
{
	cout << " first create 3 observer (observer a, observer b, and observer c)" << endl;
	observer* a = new observer_a();
	observer* b = new observer_b();
	observer* c = new observer_c();
	cout << "then create a subject ..." << endl;
	subject* s = new subject_a();
	cout << "add the three observer to the subject a ..." << endl;
	s->addListener(a);
	s->addListener(b);
	s->addListener(c);
	cout << "start to notify the observer ..." << endl;
	cout << endl;
	s->notify();
	cout << endl;
	cout << "now remove the observer a from the subject ..." << endl;
	s->removeListener(a);
	cout << "notify again" << endl;
	cout << endl;
	s->notify();
	delete s;
	s = NULL;

}
void observer_clean()
{

}

// demo codes for observer design pattern


// observer

// subject

// concrete observer
void observer_a::update(){
	cout << "observer a is been notified ..." << endl;
}

void observer_b::update(){
	cout << "observer b is been notified ..." << endl;
}

void observer_c::update(){
	cout << "observer c is been notified ..." << endl;
}

// concrete subject
subject_a::subject_a(){
	this->observer_list = new vector<observer*>;
}

subject_a::~subject_a(){
	for(vector<observer*>::iterator it=observer_list->begin(); it != observer_list->end(); )
	{
		observer* o = *it;
		observer_list->erase(it);
		delete o;
		o = NULL;
	}

	delete this->observer_list;
	this->observer_list = NULL;
}


void subject_a::notify(){
	for(vector<observer*>::iterator it=observer_list->begin(); it != observer_list->end(); it++)
	{
		observer* o = *it;
		o->update();
	}

}

void subject_a::addListener(observer* o){
	this->observer_list->push_back(o);
}


void subject_a::removeListener(observer* o){
	for(vector<observer*>::iterator it=observer_list->begin(); it != observer_list->end(); )
	{
		observer* s = *it;
		if( s == o)
		{
			observer_list->erase(it);
			delete s;
			s = NULL;

		}
		else
		{
			it++;
		}
	}

}


