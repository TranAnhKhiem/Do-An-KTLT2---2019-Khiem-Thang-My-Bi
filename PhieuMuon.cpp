#include "PhieuMuon.h"

void PhieuMuon::set_Sach(Sach xSach)
{
	this->xSach = xSach;
}

BanDoc PhieuMuon::get_BanDoc()
{
	return this->xBD.get_sMaBD();
}

Sach PhieuMuon::get_Sach()
{
	return this->xSach;
}

Date PhieuMuon::get_nNgayM()
{
	return this->xNgayM;
}

Date PhieuMuon::get_nNgayT()
{
	return this->xNgayT;
}

void PhieuMuon::set_BanDoc(BanDoc xBD)
{
	this->xBD = xBD;
}

void PhieuMuon::set_TrangThai(int nTrangThai)
{
	this->nTrangThai = nTrangThai;
}

int PhieuMuon::get_nMaPM()
{
	return this->nMaPM;
}

int PhieuMuon::get_nTrangThai()
{
	return nTrangThai;
}


string PhieuMuon::get_sMaBD()
{
	return this->xBD.get_sMaBD();
}

string PhieuMuon::get_sMaS()
{
	return this->xSach.get_sMaSach();
}

void PhieuMuon::outputPM()
{
	cout << "\nTong so phieu muon: " << this->nTongSoPhieuM << endl;
	cout << "******************\n";
	cout << "Ma Phieu Muon: " << this->nMaPM << endl;
	cout << "Ma ban doc: " << xBD.get_sMaBD() << endl;
	cout << "Ma sach: " << xSach.get_sMaSach() << endl;
	cout << "Ngay muon sach: " << xNgayM.get_nNgay() << "/"
		<< xNgayM.get_nThang() << "/"
		<< xNgayM.get_nNam() << endl;
	cout << "Ngay tra sach: " << xNgayT.get_nNgay() << "/"
		<< xNgayT.get_nThang() << "/"
		<< xNgayT.get_nNam() << endl;
	cout << "Trang thai: " << this->nTrangThai << endl;
}

string PhieuMuon::sNgayMuon()
{
	string nNgay, nThang, nNam, sNgayM;
	time_t rawtime = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	nNgay = to_string(static_cast<long long>(timeinfo.tm_mday));
	nThang = to_string(static_cast<long long>(timeinfo.tm_mon + 1));
	nNam = to_string(static_cast<long long>(timeinfo.tm_year + 1900));
	return sNgayM = nNgay + '/' + nThang + '/' + nNam;
}

string PhieuMuon::sNgayTra()
{
	string nNgay, nThang, nNam, sNgayT;
	time_t rawtime = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	nNgay = to_string(static_cast<long long>(timeinfo.tm_mday + 7));
	nThang = to_string(static_cast<long long>(timeinfo.tm_mon + 1));
	nNam = to_string(static_cast<long long>(timeinfo.tm_year + 1900));
	return sNgayT = nNgay + '/' + nThang + '/' + nNam;
}

void PhieuMuon::outputFile()
{
	ofstream fFile;
	fFile.open("PhieuMuon.txt", ios::app);
	fFile << endl << this->nMaPM << '#' << this->xBD.get_sMaBD() << '#' << this->xSach.get_sMaSach() << '#' << this->sNgayMuon() << '#' << this->sNgayTra() << '#' << this->nTrangThai << '#';
	fFile.close();
}