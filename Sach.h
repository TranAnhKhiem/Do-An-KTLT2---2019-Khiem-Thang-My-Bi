#pragma once
#include "Date.h"
#include <fstream>
class Date;

class Sach
{
private:
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNhaXB;
	float fTriGia;
	int nNamXB;
	int nSoTrang;
	Date xNgayNhapKho;
	int nTinhTrang;
public:
	friend Date;
	string get_sMaSach();
	string get_sTuaDe();
	string get_sTacGia();
	string get_sNhaXB();
	float get_fTriGia();
	int get_nNamXB();
	int get_nSoTrang();
	int get_nTinhTrang();
	void outputSach();
	void outputFileSach();
	int get_nNgay();
	int get_nThang();
	int get_nNam();
	void set_nTinhTrang(int nTinhTrang);
	Sach(string sMaSach = " ", string sTuaDe = " ", string sTacGia = " ", string sNhaXB = " ", float fTriGia = 0.0, int nNamXB = 0, int nSoTrang = 0,/*Date xNgayNhapKho = 0*/ int nNgay = 0, int nThang = 0, int nNam = 0, int nTinhTrang = 0) :xNgayNhapKho(nNgay, nThang, nNam)
	{
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNhaXB = sNhaXB;
		this->fTriGia = fTriGia;
		this->nNamXB = nNamXB;
		this->nSoTrang = nSoTrang;
		this->nTinhTrang = nTinhTrang;
		//this->xNgayNhapKho = xNgayNhapKho;
	}
	~Sach() {};
};
