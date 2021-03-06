/*List.h*/

#ifndef LIST
#define LIST

#include <iostream>
#include "Worker.h"

using namespace std;

class List{
private:
	Worker **workers;
	int size;
public:
	List();
	~List();
	int getSize();
	
	void print();
	void add(Worker *wr);
	List& sort();
	List& find(int value, List *finded);
};

#endif //LIST