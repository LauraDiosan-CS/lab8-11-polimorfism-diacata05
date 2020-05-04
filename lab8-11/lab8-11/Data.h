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
	unsigned int zi;
	unsigned int luna;
	unsigned int an;
public:
	Data();
	Data(unsigned int z, unsigned int l, unsigned int a);
	Data(const Data& d);
	~Data();
	unsigned int getZi();
	unsigned int getLuna();
	unsigned int getAn();
	void setZi(unsigned int z);
	void setLuna(unsigned int l);
	void setAn(unsigned int a);

	Data& operator=(const Data& d);
	bool operator==(const Data& d);
	friend ostream& operator<<(ostream& os, const Data& d);
	friend istream& operator>>(istream& is, Data& d);

	char* toString();

};

#endif;