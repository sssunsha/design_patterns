#include "../include.h"
void facade_setup();
void facade_run();
void facade_clean();

// demo codes for facade design pattern


// the child system has a lot of module and different APIs
class screen{
public:
	void screen_on();
	void screen_off();
};

class mainboard{
public:
	void mainboard_on();
	void mainboard_off();
};

class  fan{
public:
	void fan_on();
	void fan_off();
};

class otherDevices{
public:
	void otherDevices_on();
	void otherDevices_off();
};

// the facade to hold all the child system part and support the main APIs

class computer{
public:
	void computer_on();
	void computer_off();
	computer();
	~computer();
private:
	screen* m_screen;
	mainboard* m_mainboard;
	fan* m_fan;
	otherDevices* m_otherDevices;
};
