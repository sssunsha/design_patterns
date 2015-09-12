#include "../include.h"
#include <string>
using namespace std;


void cr_setup();
void cr_run();
void cr_clean();

//// demo codes for chain of Responsibility

// 这里我们以完成一个员工信息表为例子来演示，每一个具体处理者完成一部分内容。

class namecard{

public:
	~namecard();
	void set_name(string str);
	void set_job(string str);
	void set_partment(string str);
	void get_data();
private:
	string _name;
	string _job;
	string _partment;

};

class task_handler{
public:
	virtual void handle(namecard* nc) = 0;
	virtual void set_next(task_handler*) = 0;
	virtual ~task_handler(){}
};

class name_handler : public task_handler{
public:
	void handle(namecard* nc);
	void set_next(task_handler*);
private:
	task_handler* next;
};

class partment_handler : public task_handler{
public:
	void handle(namecard* nc);
	void set_next(task_handler*);
private:
	task_handler* next;
};

class job_handler : public task_handler{
public:
	void handle(namecard* nc);
	void set_next(task_handler*);
private:
	task_handler* next;
};
