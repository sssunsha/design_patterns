#include "../include.h"

void proxy_setup();
void proxy_clean();
void proxy_run();


// demo codes for the proxy design pattern

typedef enum {
	ENOLOGIN = 0,
	ELOGIN = 1
} EPERMISSION;

// the interface for both real subject and proxy subject
class forum{
public:
	virtual ~forum(){}
	virtual void add_subject(EPERMISSION e) = 0;
	virtual void read_subject(EPERMISSION e) = 0;
};

// the real subject
class myForum : public forum{
public:
	void add_subject(EPERMISSION e);
	void read_subject(EPERMISSION e);
};

// the proxy subject
class forumProxy : public forum{
public:
	void add_subject(EPERMISSION e);
	void read_subject(EPERMISSION e);
	forumProxy();
	~forumProxy();
private:
	myForum* real_forum;
};
