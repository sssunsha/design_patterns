#include "../include.h"

void simple_factory_setup();
void simple_factory_run();
void simple_factory_clean();



/*
 *  demo codes for simple factory
 */

class Car1{
public:
	virtual void drive() = 0;
	virtual ~Car1(){};
};

class benz1 : public Car1{
public:
	void drive();
};

class bmw1 : public Car1{
public:
	void drive();
};

class audi1: public Car1{
public:
	void drive();
};


class driver1{
public:
	static Car1* drive(const char* Car1_name);
};


class customer1{
public:
	static void getcar();
};
