#include "../include.h"

void adapter_setup();
void adapter_run();
void adapter_clean();

using namespace std;
// demo code for adapter design pattern

// 原来已经有的接口和实现
class shape{
public:
	virtual void draw() = 0;
	virtual ~shape(){}
};

class line : public shape{
public:
	void draw(){ cout << "[draw line ... ]" << endl;}
};

class square : public shape{
public:
	void draw(){ cout << "[draw square ...]" << endl;}
};


// 现在发现有一个新的已经实现的画圆的实现 （相当于adaptee）
class circle_help{
public:
	void display(){ cout << "[draw circle ...]"<< endl;}
};


// 需要通过adapter来将新的实现加入已有的方法中去
class circle : public shape{
public:
	circle(){circleHelp = new circle_help();}
	~circle(){delete circleHelp; circleHelp = NULL;}
	void draw();
private:
	circle_help* circleHelp;

};

// 使用者 taret

class target {
public:
	target();
	~target();
	void draw_line();
	void draw_square();
	void draw_circle();
private:
	shape* pline;
	shape* psquare;
	shape* pcircle;
};
