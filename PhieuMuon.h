#pragma once
#include "BanDoc.h"
#include "Sach.h"
#include <ctime>
class BanDoc;
class Sach;
class Date;

class PhieuMuon
{
private:
	BanDoc xBD;
	Sach xSach;
	Date xNgayM;
	Date xNgayT;
	int nMaPM;
	int nTrangThai;
public:
	static int nTongSoPhieuM;
	friend BanDoc;
	friend Sach;
	friend Date;
	BanDoc get_BanDoc();
	Sach get_Sach();
	Date get_nNgayM();
	Date get_nNgayT();
	string get_sMaBD();
	string get_sMaS();
	string sNgayMuon();
	string sNgayTra();
	int get_nMaPM();
	int get_nTrangThai();
	void set_Sach(Sach xSach);
	void set_BanDoc(BanDoc xBD);
	void set_TrangThai(int nTrangThai);
	void outputPM();
	void outputFile();
	PhieuMuon(int nMaPM = 0, string sMaBD = " ", string sMaSach = " ", int nNgayM = 0, int nThangM = 0, int nNamM = 0, int nNgayT = 0, int nThangT = 0, int nNamT = 0, int nTrangThai = 0) : xBD(sMaBD), xSach(sMaSach), xNgayM(nNgayM, nThangM, nNamM), xNgayT(nNgayT, nThangT, nNamT)
	{
		this->nTongSoPhieuM++;
		this->nMaPM = nTongSoPhieuM;
		this->nTrangThai = nTrangThai;
	}
	PhieuMuon(string sMaBD = " ", string sMaSach = " ") : xBD(sMaBD), xSach(sMaSach)
	{
		time_t rawtime = time(0);
		struct tm timeinfo;
		localtime_s(&timeinfo, &rawtime);
		xNgayM.set_nNgay(timeinfo.tm_mday);
		xNgayM.set_nNgay(timeinfo.tm_mon + 1);
		xNgayM.set_nNgay(timeinfo.tm_year + 1900);

		xNgayT.set_nNgay(timeinfo.tm_mday + 7);
		xNgayT.set_nNgay(timeinfo.tm_mon + 1);
		xNgayT.set_nNgay(timeinfo.tm_year + 1900);
		this->nTongSoPhieuM++;
		this->nMaPM = nTongSoPhieuM;
		this->nTrangThai = 1;
	}
	~PhieuMuon() {};
};
