#include "../include.h"

void strategy_setup();
void strategy_run();
void strategy_clean();

// demo codes for strategy design pattern
class food;

// context

class guy{
public:
	virtual ~guy(){}
	virtual void eat() = 0;
};


class father : public guy{
public:
	void eat();
	father(food* f);
	~father();
private:
	food* _food;
};

class mother : public guy{
public:
	void eat();
	mother(food* f);
	~mother();
private:
	food* _food;
};

class daughter : public guy{
public:
	void eat();
	daughter(food* f);
	~daughter();
private:
	food* _food;
};


// strategy

class food{
public:
	virtual ~food(){}
	virtual void handle() = 0;
};


class meat : public food{
public:
	void handle();
};

class vegetable : public food{
public:
	void handle();
};
