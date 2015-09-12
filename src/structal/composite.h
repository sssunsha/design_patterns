#include "../include.h"
#include <vector>
#include <string>
using namespace std;

void composite_setup();
void composite_run();
void composite_clean();

//demo codes for composite design pattern

// here the window is the root of the tree, and it as the component part
class window{
public:
	virtual void draw() = 0;
	virtual void addChild(window* v) = 0;
	virtual void removeChild(window* v) =0;
	virtual int viewCount() = 0;
	virtual ~window(){}
};


// here the view group is the composite
class viewGroup : public window{
public:
	void draw();
	void addChild(window* v);
	void removeChild(window* v);
	int viewCount();
	~viewGroup();
	viewGroup();
private:
	std::vector<window*>* group;
};


// the view is the leaf
class view : public window{
public:
	void draw();
	void addChild(window* v);
	void removeChild(window* v);
	int viewCount();
	view(string name);
private:
	string _name;
};
