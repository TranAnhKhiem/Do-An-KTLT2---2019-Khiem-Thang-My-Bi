#include "Date.h"

void Date::outputFile()
{
	ofstream fFile;
	fFile.open("Book_Data.txt", ios::app);
	fFile << '#' << Date::nNgay << '/' << Date::nThang << '/' << Date::nNam << '#';
	fFile.close();
}

void Date::set_NgyThgNam(int nNgay, int nThang, int nNam)
{
	this->nNgay = nNgay;
	this->nThang = nThang;
	this->nNam = nNam;
}

int Date::get_nNgay()
{
	return nNgay;
}

int Date::get_nThang()
{
	return nThang;
}

int Date::get_nNam()
{
	return nNam;
}

void Date::set_nNgay(int nNgay)
{
	this->nNgay = nNgay;
}

void Date::set_nThang(int nThang)
{
	this->nThang = nThang;
}

void Date::set_nNam(int nNam)
{
	this->nNam = nNam;
}

void Date::output()
{
	cout << nNgay << "/" << nThang << "/" << nNam;
}