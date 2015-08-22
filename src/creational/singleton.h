#include "../include.h"
void singleton_setup();
void singleton_run();
void singleton_clean();


// demo codes for singleton desgin pattern
class singleton {
public:
	static singleton*  getInstance();
	void number_plus();
	int get_number();

private:
	int number;
	static singleton* self;
	singleton();
};
