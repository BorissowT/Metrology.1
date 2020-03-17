#include "event.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

event::event(int id, string name, string date, string location ) {
	
	this->id = id;
	this->name = name;
	this->location = location;
	this->date = date;
}

event::event() {

	this->id = 0;
	this->name = "title";
	this->location = "russia";
	this->date = "today";
}