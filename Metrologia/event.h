#pragma once
#include <string>

using namespace std;

class event {
public:
	int id;
	string name;
	string date;
	string location;
	event(int id, string name, string date, string location);
	event();
};

