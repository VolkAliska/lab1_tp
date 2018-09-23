/*List.h*/

#include "List.h"
#include "time.h"

List::List(){
	this->size = 0;
	this->workers = (Worker*)malloc((this->size)*sizeof(Worker));
	cout << "Object (type List) was created by default constructor" << endl;
}

List::List(int size){
	this->size = size;
	this->workers = (Worker*)malloc((this->size)*sizeof(Worker));
	cout << "Object (type List) was created by constructor with parameters" << endl;
}

List::~List(){
	this->size = 0;
	free(this->workers);
	cout << "Object (type List) was deleted" << endl;
}

int List::getSize(){
	return size;
}

void List::setSize(int size){
	this->size = size;
}


List& List::Add(Worker &wr){
	try {
		this->size++;
		this->workers = (Worker*)realloc(this->workers, sizeof(Worker)*(this->size));
		this->workers[size - 1].setYear(wr.getYear());
		//ломается
		this->workers[size - 1].setName(wr.getName());
		this->workers[size - 1].setPost(wr.getPost());
	}
	catch (exception e) {
		printf_s("Cant add Student object to list");
	}
	return *this;
}

ostream& operator<<(ostream &is, List &list){
	try {
		if (list.getSize() == 0){
			cout << "Empty list" << endl;
			return is;
		}
		for (int i = 0; i < list.getSize(); i++){
			cout << list.workers[i] << endl;
		}
	}
	catch (exception ex) {
		printf_s("List is empty");
	}
	return is;
}

void List::Sort(){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < this->size; j++){
			if (this->workers[i].getName() > this->workers[j].getName()){
				string buf = workers[i].getName();
				workers[i].setName(workers[j].getName());
				workers[j].setName(buf);
			}
		}
	}
}

void List::Find(int value){
	time_t t;
	struct tm *current;
	time(&t);
	current = localtime(&t);
	int curyear = current->tm_year + 1900;
	int fl = 0;
	for (int i = 0; i < this->size; i++){
		if (curyear - workers[i].getYear() > value){
			cout << workers[i] << endl << endl;
			fl = 1;
		}
	}
	if (fl == 0)
		cout << "no workers with such work experience";
}