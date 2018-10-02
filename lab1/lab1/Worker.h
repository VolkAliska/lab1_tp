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
	double year;

public:
	Worker();
	Worker(string name, string post, double year);
	Worker(const Worker &worker);
	~Worker();

	string getName();
	string getPost();
	double getYear();
	void setName(string name);
	void setPost(string post);
	void setYear(double year);
	
	friend istream& operator>>(istream &s, Worker& worker);
	friend ostream& operator<<(ostream &s,const Worker& worker);
};

#endif //WORKER