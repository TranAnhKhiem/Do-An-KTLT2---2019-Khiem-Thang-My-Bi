#pragma once
#include "BanDoc.h"
class GiaoVien :
	public BanDoc
{
private:
	string sDiaChi;
	string sSoDT;
public:
	void output();
	GiaoVien(string sMaBD = " ", string sHoTen = " ", string sKhoa = " ", int nNgay = 0, int nThang = 0, int nNam = 0, string sDiaChi = " ", string sSoDT = " ") : BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSoDT = sSoDT;
	}
	~GiaoVien() {};
};
