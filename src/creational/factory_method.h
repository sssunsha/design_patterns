#include <iostream>

void factory_method_setup();
void factory_method_clean();
void factory_method_run();


// demo codes for factory method


// Car is the product needed to created
class Car2{
public:
	virtual void drive() = 0;
	virtual ~Car2(){};
};

class benz2 : public Car2{
public:
	void drive();
};

class bmw2 : public Car2{
public:
	void drive();
};

class audi2 : public Car2{
public:
	void drive();
};


// Driver is the factory will create the product
class Driver2{
public:
	virtual Car2* drive() = 0;
	virtual ~Driver2(){};
};

class benzDriver2 : public Driver2{
public:
	Car2* drive();
};

class bmwDriver2 : public Driver2{
public:
	Car2* drive();
};

class audiDriver2 : public Driver2{
public:
	Car2* drive();
};

class customer2{
public:
	static void getcar();
};
