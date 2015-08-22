#include "../include.h"
using namespace std;

void bridge_setup();
void bridge_clean();
void bridge_run();

// demo codes for bridge design pattern

// front-end part

class os{
public:
	virtual ~os(){}
	virtual void run() = 0;
};

class Linux : public os{
public:
	void run() { cout << " Linux " << endl;}
};

class Windows : public os{
public:
	void run() { cout << " Windows " << endl;}
};


// implement (backend part)
class pc {
public:
	virtual void install(os*) = 0;
	virtual ~pc(){};
};

class hp : public pc{
public:
	void install(os* system);
};

class dell : public pc{
public:
	void install(os* system);
};

class ibm : public pc{
public:
	void install(os* system);
};
