#include "../include.h"
#include <string>
using namespace std;
void mediator_setup();
void mediator_run();
void mediator_clean();

// demo codes for mediator design pattern

// 这里我们这里以房屋中介和房东，租客来演示
// 租客和房东都是"同事"。 当然中介就是中介了

class Mediator;

class person {
public:
	virtual void set_mediator(Mediator* m) = 0;
	virtual void set_message(string str) = 0;
	virtual void get_message(string str) = 0;
	virtual ~person(){}
protected:
	Mediator* _mediator;
};

// 房东
class host : public person{
public:
	void set_mediator(Mediator* m);
	void set_message(string str);
	void get_message(string str);
};

// 	租客
class client : public person{
public:
	void set_mediator(Mediator* m);
	void set_message(string str);
	void get_message(string str);
};


// 中介
class Mediator{
public:
	virtual void set_client(person* p) =0;
	virtual void set_host(person* p) = 0;
	virtual void set_message(person* p, string str) = 0;
	virtual ~Mediator(){}
};

class houseMediator : public Mediator{
public:
	void set_client(person* p);
	void set_host(person* p);
	void set_message(person* p, string str);
	~houseMediator();
protected:
	person* _client;
	person* _host;
};















