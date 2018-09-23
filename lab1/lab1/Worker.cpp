/*Worker.cpp*/

#include "Worker.h"

Worker::Worker(){
	name = "";
	post = "";
	year = 0;
	cout << "Object Worker: " << name << " was created by default constructor" << endl;
}

Worker::Worker(string name, string post, double year){
	this->name = name;
	this->post = post;
	this->year = year;
	cout << "Object Worker: " << name << " was created by constructor with parameters" << endl;
}

Worker::Worker(const Worker &worker){
	this->name = worker.name;
	this->post = worker.post;
	this->year = worker.year;
	cout << "Object Worker: " << name << " was created by copy constructor" << endl;
}

Worker::~Worker(){
	cout << "Delete object Worker: " << name << endl;
	this->name = "";
	this->post = "";
	this->year = 0;
}

string Worker::getName(){
	return(name);
}

string Worker::getPost(){
	return(post);
}

double Worker::getYear(){
	return(year);
}

void Worker::setName(string name){
	this->name = name;
}

void Worker::setPost(string post){
	this->post = post;
}

void Worker::setYear(double year){
	this->year = year;
}

istream& operator>>(istream &s, Worker& worker){
	cout << "Enter name (Ex: Ivanov V.A.) " << endl;
	s.clear();
	s.sync();
	getline(s, worker.name);
	cout << "Enter post " << endl;
	s >> worker.post;
	cout << "Enter year of joining " << endl;
	double year = 0;
	s.clear();
	s.sync();
	scanf_s("%d", &year);
	worker.setYear(year);
	return s;
}

ostream& operator<<(ostream &s, const Worker& worker){
	cout << "Name: " << worker.name << endl;
	cout << "Post: " << worker.post << endl;
	cout << "Year of joining: " << worker.year << endl;
	return s;
}