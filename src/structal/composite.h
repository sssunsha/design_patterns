#include "../include.h"

void composite_setup();
void composite_run();
void composite_clean();

//demo codes for composite design pattern

// here the Menu is the root of the tree, and it as the component part
class Menu {
public:
	virtual void add_child( Menu* m);
	virtual void remove_child( Menu* m);
	virtual void cook();
	virtual ~Menu(){}
};

class subMenu : public Menu{

};

class food : public subMenu{

};
