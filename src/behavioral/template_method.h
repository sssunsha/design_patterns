#include "../include.h"

void template_method_setup();
void template_method_run();
void template_method_clean();


// demo codes for template method
class family{
public:
	virtual void super();
	virtual void eat() = 0;
	virtual void drink() = 0;
	virtual ~family() {}
};

class dad : public family{
public:
	void eat();
	void drink();
};

class mom : public family{
public:
	void eat();
	void drink();
};

class son : public family{
public:
	void eat();
	void drink();
};


/*
 * template method的核心思想就是把相同的不变的部分放到抽象类中，将会变的放在派生类中。
 *
 * 这里 super是相同的
 * 而具体eat和drink却是不同的
 */
