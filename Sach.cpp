#include "Sach.h"

string Sach::get_sMaSach()
{
	return sMaSach;
}

int Sach::get_nTinhTrang()
{
	return nTinhTrang;
}

string Sach::get_sTuaDe()
{
	return sTuaDe;
}

string Sach::get_sTacGia()
{
	return sTacGia;
}

string Sach::get_sNhaXB()
{
	return sNhaXB;
}

float Sach::get_fTriGia()
{
	return fTriGia;
}

int Sach::get_nNamXB()
{
	return nNamXB;
}

int Sach::get_nSoTrang()
{
	return nSoTrang;
}

int Sach::get_nNgay()
{
	return this->xNgayNhapKho.get_nNgay();
}

int Sach::get_nThang()
{
	return this->xNgayNhapKho.get_nThang();
}
int Sach::get_nNam()
{
	return this->xNgayNhapKho.get_nNam();
}

void Sach::outputFileSach()
{
	ofstream fFile;
	fFile.open("Book_Data.txt", ios::app);
	fFile << endl << this->sMaSach << '#' << this->sTuaDe << '#' << this->sTacGia << '#' << this->sNhaXB << '#'
		<< this->fTriGia << '#' << this->nNamXB << '#' << this->nSoTrang << '#' << this->xNgayNhapKho.get_nNgay()
		<< '/' << this->xNgayNhapKho.get_nThang() << '/' << this->xNgayNhapKho.get_nNam() << '#' << this->nTinhTrang;
	fFile.close();
}

void Sach::outputSach()
{
	cout << setw(5) << this->sMaSach << setw(15) << this->sTuaDe
		<< setw(15) << this->sTacGia << setw(15) << this->sNhaXB << setw(15) <<
		this->fTriGia << setw(15) << this->nNamXB << setw(15) << this->nSoTrang << setw(7);
	xNgayNhapKho.output();
	cout << setw(12) << this->nTinhTrang << endl;
}


void Sach::set_nTinhTrang(int nTinhTrang)
{
	this->nTinhTrang = nTinhTrang;
}