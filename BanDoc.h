#pragma once
#include "Date.h"

class Date;

class BanDoc
{
protected:
	string sMaBD;
	string sHoTen;
	string sKhoa;
	Date xNgayThamGia;
public:
	friend Date;
	virtual void output() {};
	void outputTT();
	string get_sMaBD();
	BanDoc(string sMaBD = " ", string sHoTen = " ", string sKhoa = " ", int nNgay = 0, int nThang = 0, int nNam = 0) : xNgayThamGia(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}
	~BanDoc() {};
};
