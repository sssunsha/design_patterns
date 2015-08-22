#include "../include.h"
void builder_setup();
void builder_run();
void builder_clean();

using namespace std;
// demo codes for the builder design pattern

/*
 * 这里我用配置电脑为例子，电脑的架构和组成部分基本一样，但可以配置出笔记本电脑，和台式机。
 */

class Builder{
public:
	virtual void install_cpu() = 0;
	virtual void install_disk() = 0;
	virtual void install_memory() = 0;
	virtual void install_audio() = 0;
	virtual void install_video() = 0;
	virtual void install_others() = 0;
	virtual ~Builder(){}
};

class laptopBuilder : public Builder{
public:
	void install_cpu() { cout << "install laptop cpu" << endl;}
	void install_disk()  { cout << "install laptop disk" << endl;}
	void install_memory() { cout << "install laptop memory" << endl;}
	void install_audio() { cout << "install laptop audio module" << endl;}
	void install_video() { cout << "install laptop video module" << endl;}
	void install_others() { cout << "install laptop others" << endl;}
};

class desktopBuilder : public Builder{
public:
	void install_cpu() { cout << "install desktop cpu" << endl;}
	void install_disk()  { cout << "install desktop disk" << endl;}
	void install_memory() { cout << "install desktop memory" << endl;}
	void install_audio() { cout << "install desktop audio module" << endl;}
	void install_video() { cout << "install desktop video module" << endl;}
	void install_others() { cout << "install desktop others" << endl;}
};

// Direct part, which use to own the builder and build the product it wants
class Direct {
public:
	void set_builder(Builder*);
	 void start_builder();
	 void free_builder();
private:
	 Builder* builder;
};
