/*List.h*/

#ifndef LIST
#define LIST
#include <iostream>
#include "Worker.h"

using namespace std;

class List{
private:
	Worker *workers;
	int size;
public:
	List();
	List(int size);
	~List();
	int getSize();
	void setSize(int size);

	friend istream& operator>>(istream &s, List &list);
	//friend ostream& operator<<(ostream &s, const List &list);

	void Sort();
	void Find(int value);
};

#endif //LIST