#include "../include.h"
void decorator_setup();
void decorator_clean();
void decorator_run();

// demo codes for decorator (wrapper) design pattern


class door {
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual ~door(){}
};

class normalDoor : public door{
public:
	void open();
	void close();
private:
	int is_close;
};

class alarmDoorDecorator : public door{
public:
	virtual void open();
	virtual void close();
	virtual ~alarmDoorDecorator();
	alarmDoorDecorator(door* d);

	// new function added
	virtual void alarm() = 0;

private:
	door* _door;
};

class alarmDoor : public alarmDoorDecorator{
public:
	alarmDoor(door* d);
	void alarm();
};
