/*Worker.cpp*/

#include "Worker.h"

Worker::Worker(){
	name = "noname";
	post = "nopost";
	year = 0;
	cout << "Object Worker: " << name << " was created by default constructor" << endl;
}

Worker::Worker(string name, string post, int year){
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

int Worker::getYear(){
	return(year);
}

void Worker::setName(string name){
	this->name = name;
}

void Worker::setPost(string post){
	this->post = post;
}

void Worker::setYear(int year){
	this->year = year;
}

istream& operator>>(istream &s, Worker& worker){
	cout << "Enter name (Ex: Ivanov V.A.) " << endl;
	getline(s, worker.name);
	cout << "Enter post " << endl;
	s >> worker.post;
	cout << "Enter year of joining " << endl;
	s >> worker.year;
	return s;
}

ostream& operator<<(ostream &s, const Worker& worker){
	cout << "Name: " << worker.name << endl;
	cout << "Post: " << worker.post << endl;
	cout << "Year of joining: " << worker.year << endl;
	return s;
}