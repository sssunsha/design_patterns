#include "../include.h"
#include <string>

using namespace std;

void state_setup();
void state_run();
void state_clean();


// demo codes for state design pattern

// 这里我们以图书馆借书作为泛滥，图书馆的书有几种状态，没有被借出(ready), 申请中(requested), 借阅中 (reading), 归还中 （return）

class state;

class book{
public:
	book(state* s);
	~book();
	void changeState(state* s);
	void request();
private:
	state* _state;
};


class state{
public:
	virtual void handle(book* b) = 0;
	virtual string getState() = 0;
	virtual ~state(){};
};

class state_ready : public state{
public:
	string getState();
	void handle(book* b);
};

class state_requested : public state{
public:
	string getState();
	void handle(book* b);
};

class state_reading : public state{
public:
	string getState();
	void handle(book* b);
};

class state_return : public state{
public:
	string getState();
	void handle(book* b);
};
