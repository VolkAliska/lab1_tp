/*Worker.h*/

#ifndef WORKER
#define WORKER
#include <iostream>
#include <istream>
#include <string>
#include <ostream>

using namespace std;

class Worker{
private:
	string name;
	string post;
	int year;

public:
	Worker();
	Worker(string name, string post, int year);
	Worker(const Worker &worker);
	~Worker();

	string getName();
	string getPost();
	int getYear();
	void setName(string name);
	void setPost(string post);
	void setYear(int year);
	
	friend istream& operator>>(istream &s, Worker& worker);
	friend ostream& operator<<(ostream &s,const Worker& worker);
};

#endif //WORKER