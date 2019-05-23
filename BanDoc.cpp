#include "BanDoc.h"

void BanDoc::outputTT()
{
	cout << endl;
	cout << "Ma ban doc: " << this->sMaBD << endl;
	cout << "Ho ten ban doc: " << this->sHoTen << endl;
	cout << "Khoa ban doc: " << this->sKhoa << endl;
	cout << "Ngay dang ki: ";
	xNgayThamGia.output();
}
string BanDoc::get_sMaBD()
{
	return sMaBD;
}