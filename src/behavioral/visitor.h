#include "../include.h"
#include <string>
#include <list>
using namespace std;
void visitor_setup();
void visitor_run();
void visitor_clean();

// codes for the demo of visitor design pattern
class element;

class visitor {
public:
	virtual void visit(element* e){};
	virtual ~visitor(){};
};


// element
class element{
public:
	virtual void accept(visitor* v){};
	virtual ~element(){};
};

// concrete element
class employee : public element{
public:
	employee(
			string n,
			double i,
			int v
			){
		this->_income = i;
		this->_name = n;
		this->_vacation_days = v;
	};


	void accept(visitor* v){
		v->visit(this);
	};

	string _name;
	double _income;
	int _vacation_days;
};


// concrete visitor
class income_visitor : public visitor{
public:
	void visit(element* e){
		employee* ee = (employee*)e;
		ee->_income += 1000;
		cout << endl;
		cout << "employee's new income --> " << ee->_income << endl;
	};
};

class vaction_visitor : public visitor{
public:
	void visit(element* e){
		employee* ee = (employee*)e;
		ee->_vacation_days += 3;
		cout << endl;
		cout << "employee's new vacation day --> "<< ee->_vacation_days << endl;
	};
};

class showall_visitor : public visitor{
public:
	void visit(element* e){
		employee* ee = (employee*)e;
		cout << "employee's name --> " << ee->_name << endl;
		cout << "employee's income --> " << ee->_income << endl;
		cout << "employee's vacation day --> "<< ee->_vacation_days << endl;
	};
};

// object structure
class employees {
public:

	void attach(employee* e){
		this->_list->push_back(e);
	};

	void detach(employee* e){
		this->_list->remove(e);
	};
	void accept(visitor* v){
		 for (list<employee*>::iterator it=this->_list->begin(); it != this->_list->end(); ++it)
		            (*it)->accept(v);
	};

	~employees(){
		for (list<employee*>::iterator it=this->_list->begin(); it != this->_list->end();)
		{
			employee* e = *it;
			this->_list->erase(it);
			delete e;
			e = NULL;
		}

		delete this->_list;
		this->_list = NULL;
	};

	employees(){
		this->_list = new list<employee*>;
	};
private:
	list<employee*>* _list;
};
