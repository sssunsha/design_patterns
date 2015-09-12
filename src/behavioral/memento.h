#include "../include.h"
#include <vector>
void memento_setup();
void memento_run();
void memento_clean();
using namespace std;
// demo codes for memento design pattern

// the memento
class gameMemento{
public:
	gameMemento(int d);
	int get();
private:
	int data;
};


// the caretaker
class mementoManager{
public:
	mementoManager();
	~mementoManager();
	void addMemento(int d);
	int loadMemento(int index);
private:
	vector<gameMemento*>* _array;
};

// the originator
class game{
public:
	~game();
	game();
	void saveMemento(int data);
	int loadMemento(int index);
private:
	mementoManager* _manager;
};
