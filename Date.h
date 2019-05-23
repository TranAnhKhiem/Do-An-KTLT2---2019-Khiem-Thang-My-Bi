#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

class Date
{
private:
	int nNgay;
	int nThang;
	int nNam;
public:
	Date(int nNgay = 0, int nThang = 0, int nNam = 0)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	int get_nNgay();
	int get_nThang();
	int get_nNam();
	void outputFile();
	void set_nNgay(int nNgay);
	void set_nThang(int nThang);
	void set_nNam(int nNam);
	void set_NgyThgNam(int nNgay, int nThang, int nNam);
	void output();
	~Date() {};
};

