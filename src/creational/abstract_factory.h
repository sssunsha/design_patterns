#include "../include.h"

void abstract_factory_setup();
void abstract_factory_run();
void abstract_factory_clean();


// demo codes for abstract

// car is the product
class Car3 {
public:
	virtual void drive() = 0;
	virtual ~Car3(){};
};

class sportCar : public Car3{
public:
	virtual void drive() = 0;
	virtual ~sportCar(){};
};

class bussinessCar : public Car3{
public:
	virtual void drive() = 0;
	virtual ~bussinessCar(){};
};


class bmwSportCar : public sportCar{
public:
	void drive();
};

class audiSportCar : public sportCar{
public:
	void drive();
};

class bmwBussinessCar : public bussinessCar{
public:
	void drive();
};

class audiBussinessCar : public bussinessCar{
public:
	void drive();
};

// driver is the factory

class Driver3{
public:
	virtual Car3* driveSportCar() = 0;
	virtual Car3* driveBussinessCar() = 0;
	virtual ~Driver3(){};
};

class bmwDriver : public Driver3{
public:
	Car3* driveSportCar();
	Car3* driveBussinessCar();
};

class audiDriver : public Driver3{
public:
	Car3* driveSportCar();
	Car3* driveBussinessCar();
};

// customer part
class customer3 {
public:
	static void getcar();
};

