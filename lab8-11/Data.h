#pragma once
#ifndef DATA_H
#define DATA_H

using namespace std;

#include <string>
#include <iostream>
#include <ostream>
#include <istream>

class Data {
private:
	int zi;
	int luna;
	int an;
public:
	Data();
	Data(int z, int l, int a);
	Data(const Data& d);
	~Data();
	int getZi();
	int getLuna();
	int getAn();
	void setZi(int z);
	void setLuna(int l);
	void setAn(int a);

	Data& operator=(const Data& d);
	bool operator==(const Data& d);
	friend ostream& operator<<(ostream& os, const Data& d);
	friend istream& operator>>(istream& is, Data& d);

	char* toString();

};

#endif;