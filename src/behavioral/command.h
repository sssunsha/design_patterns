#include "../include.h"

void command_setup();
void command_clean();
void command_run();

// demo codes for command design pattern

/*

 1) 命令角色(Command):声明执行操作的接口。有 java 接口或者抽象类来实现。
 2) 具体命令角色(Concrete Command):将一个接收者对象绑定于一个动作;调用接收者相应的操作,以实现命令角色声明的执行操作的接口。
 3) 客户角色(Client):创建一个具体命令对象(并可以设定它的接收者)。
 4) 请求者角色(Invoker):调用命令对象执行这个请求。
 5) 接收者角色(Receiver):知道如何实施与执行一个请求相关的操作。任何类都可能作为一个接收者。

这里用电视遥控器来演示 电视和遥控器上都有开，关，和 换台按钮，这里每个按钮就是一个命令，电视本身是接收者，而遥控器按钮就是请求者

 */
// receiver
class TV {
public:
	void tv_turn_on();
	void tv_turn_off();
	void tv_change_channel();
};


//command
class command{
public:
	virtual void execute() = 0;
	virtual ~command(){}
};

// concrete command
class turn_on_command : public command{
public:
	void execute();
	turn_on_command(TV* tv);
private:
	TV* _tv;
};

class turn_off_command : public command{
public:
	void execute();
	turn_off_command(TV* tv);
private:
	TV* _tv;

};

class change_channel_command: public command{
public:
	void execute();
	change_channel_command(TV* tv);
private:
	TV* _tv;

};

// invoker
class control{
public:
	control();
	~control();
	void turn_on_tv();
	void turn_off_tv();
	void change_channel_tv();
private:
	turn_on_command* turn_on;
	turn_off_command* turn_off;
	change_channel_command* change;
	TV* _tv;
};

