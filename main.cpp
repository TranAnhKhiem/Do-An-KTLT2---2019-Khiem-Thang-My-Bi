#include "Admin.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include "Sach.h"
#include <list>
#include <conio.h>
#include <windows.h>
list<Sach> BookList;
list<BanDoc*> UserList;
list<Admin> AdminList;
list<PhieuMuon> ListPM;
//Book
void inputBookList(list <Sach> &L);
void outputBookList(list<Sach> L);
void addBook(list<Sach> &L);
void deleteBook(list<Sach> &L, string sKey);
void findBook(list<Sach> L, string sKey);
int countBookInLi(list<Sach> L);
bool checkBookCode(list<Sach> L, string sKey);
bool checkBookStatus(list<Sach> L, string sKey);
void thongKeSach1UserMuon(list<Sach> L1, list<BanDoc*> L2, list<PhieuMuon> L3);
//User
void inputUserList(list <BanDoc*> &L);
void outputUserList(list <BanDoc*> L);
void findUser(list <BanDoc*> L, string sKey);
void addUser(list <BanDoc*> &L);
bool checkUserCode(list<BanDoc*> L, string userKey);
//Admin
void inputAdminList(list <Admin> &L);
void outputAdminList(list <Admin> L);
bool checkAdmin(list<Admin> L, string sUser, string sPass);
//Hàm ẩn password
//Phieu Muon
void inputDSPhieuMuon(list <PhieuMuon> &L);
void outputPM(list<PhieuMuon> L);
void taoPM(list <PhieuMuon> &L1, list<BanDoc*> L3, list<Sach> &L2);
void traSach(list <PhieuMuon> &L1, list<Sach> &L2);

string hidePasswordInput();
int PhieuMuon::nTongSoPhieuM = 0;
void main()
{
	//Ham chinh mau
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

	inputBookList(BookList);
	inputAdminList(AdminList);
	inputDSPhieuMuon(ListPM);
	inputUserList(UserList);
	string sUser, sPass;
	int nKey;
	int nB;

	do
	{
		system("cls");
		SetConsoleTextAttribute(hConsoleColor, 14);
		cout << "\t\t\t\t\t**************************************\n";
		cout << "\n";
		cout << "\t\t\t\t\t*           Menu Chuc Nang           *\n";
		cout << "\n";
		cout << "\t\t\t\t\t**************************************\n";
		cout << "\t\t\t\t\t\t1. Hien thi thong tin sach\n";
		cout << "\t\t\t\t\t\t2. Tim kiem thong tin\n";
		cout << "\t\t\t\t\t\t3. Quan LY\n";
		cout << "\t\t\t\t\t\t4. Thoat Chuong trinh\n";
		cout << "\t\t\t\t\t\tChoose function: ";
		cin >> nKey;
		switch (nKey)
		{
		case 1:
			outputBookList(BookList);
			break;
		case 2:
			do {
				system("cls");
				SetConsoleTextAttribute(hConsoleColor, 12);
				cout << "\n\t****Tim Kiem****\n"
					<< "\t\t1. Tim Kiem Sach \n"
					<< "\t\t2. Tim Kiem Ban Doc \n"
					<< "\t\t3. Quay lai Chuong trinh chinh\n"
					<< "\t\tChoose service: ";
				cin >> nB;
				if (nB == 1)
				{
					string sKey = "";
					cout << "Nhap ma sach de hien thi thong tin: ";
					cin.ignore(1, '\n');
					getline(cin, sKey);
					findBook(BookList, sKey);
					system("pause");
				}
				else if (nB == 2)
				{
					string sKey = "";
					cout << "Nhap ma ban doc de hien thi thong tin: ";
					cin.ignore(1, '\n');
					getline(cin, sKey);
					findUser(UserList, sKey);
					system("pause");
				}
			} while (nB != 3);
			break;
		case 3:

			SetConsoleTextAttribute(hConsoleColor, 11);
			cout << "\t\t\t\t\t\tUsername: ";
			cin.ignore(1, '\n');
			getline(cin, sUser);
			cout << "\t\t\t\t\t\tPassword: ";
			sPass = hidePasswordInput();
			if (checkAdmin(AdminList, sUser, sPass) == false)
			{
				SetConsoleTextAttribute(hConsoleColor, 12);
				cout << "\t\t\t\t\t\tWrong User or Password \n";
			}
			else if (checkAdmin(AdminList, sUser, sPass) == true)
			{
				do {
					system("cls");
					SetConsoleTextAttribute(hConsoleColor, 12);
					cout << "\n\t****Quan LY****\n"
						<< "\t\t1. Quan ly phieu muon \n"
						<< "\t\t2. Quan ly sach \n"
						<< "\t\t3. Quan ly ban doc \n"
						<< "\t\t4. Thong ke \n"
						<< "\t\t5. Quay lai chuong trinh chinh\n"
						<< "\t\tChoose service: ";
					cin >> nB;
					if (nB == 1)
					{
						do {
							system("cls");
							SetConsoleTextAttribute(hConsoleColor, 12);
							cout << "\n\t****Phieu Muon****\n"
								<< "\t\t1. Tao Phieu Muon Moi \n"
								<< "\t\t2. Cap Nhat Tinh Trang Phieu Muon \n"
								<< "\t\t3. Quay lai Chuong trinh chinh\n"
								<< "\t\tChoose service: ";
							cin >> nB;
							if (nB == 1)
							{
								taoPM(ListPM, UserList, BookList);
								system("pause");
							}
							if (nB == 2)
							{
								cout << "Cap Nhat Tinh Trang Phieu Muon\n";
								traSach(ListPM, BookList);
								system("pause");
							}
						} while (nB != 3);
					}
					else if (nB == 2)
					{
						do {
							system("cls");
							SetConsoleTextAttribute(hConsoleColor, 12);
							cout << "\n\t****Sach****\n"
								<< "\t\t1. Them sach Moi \n"
								<< "\t\t2. Xoa sach \n"
								<< "\t\t3. Quay lai Chuong trinh chinh\n"
								<< "\t\tChoose service: ";
							cin >> nB;
							if (nB == 1)
							{
								addBook(BookList);
								system("pause");
							}
							else if (nB == 2)
							{
								string sKey = " ";
								cout << "Nhap ma sach de xoa: ";
								cin.ignore(1, '\n');
								getline(cin, sKey);
								deleteBook(BookList, sKey);
								system("pause");
							}
						} while (nB != 3);
					}
					else if (nB == 3)
					{
						do {
							system("cls");
							SetConsoleTextAttribute(hConsoleColor, 12);
							cout << "\n\t****Ban Doc****\n"
								<< "\t\t1. Them Ban Doc \n"
								<< "\t\t2. Quay lai Chuong trinh chinh\n"
								<< "\t\tChoose service: ";
							cin >> nB;
							if (nB == 1)
							{
								addUser(UserList);
								system("pause");
							}
						} while (nB != 2);
					}
					else if (nB == 4)
					{
						thongKeSach1UserMuon(BookList, UserList, ListPM);
						system("pause");
					}
				} while (nB != 5);

			}
			break;
		}
		system("pause");
	} while (nKey != 4);
}

void traSach(list <PhieuMuon> &L1, list<Sach> &L2)
{
	int nSoPM = 0;
	cout << "Nhap so Phieu Muon: ";
	cin >> nSoPM;
	list<PhieuMuon>::iterator position = L1.begin();
	list<Sach>::iterator positionBook = L2.begin();
	remove("PhieuMuon.txt");
	remove("Book_Data.txt");
	while (position != L1.end())
	{
		if (position->get_nMaPM() == nSoPM)
		{
			if (position->get_nTrangThai() == 0)
			{
				cout << "Phieu muon da duoc tra! \n";
				break;
			}
			else
			{

				position->set_TrangThai(0);
				while (positionBook != L2.end())
				{
					if (position->get_sMaS() == positionBook->get_sMaSach())
					{
						positionBook->set_nTinhTrang(0);
					}
					positionBook->outputFileSach();
					positionBook++;
				}
				cout << "Tra sach thanh cong! \n";
			}
		}
		position->outputFile();
		position++;
	}
}

void taoPM(list <PhieuMuon> &L1, list<BanDoc*> L3, list<Sach> &L2)
{
	string sMaBD = " ", sMaS = " ";
	cout << "Nhap ma ban doc can muon sach: ";
	cin.ignore(1, '\n');
	getline(cin, sMaBD);
	while (checkUserCode(L3, sMaBD) == false)
	{
		cout << "Nhap ma ban doc can muon sach: ";
		getline(cin, sMaBD);
	}
	cout << "Nhap ma sach muon muon: ";
	getline(cin, sMaS);
	while (checkBookCode(L2, sMaS) == false || checkBookStatus(L2, sMaS) == false)
	{
		cout << "Nhap ma sach muon muon: ";
		getline(cin, sMaS);
	}

	PhieuMuon xPM = PhieuMuon(sMaBD, sMaS);
	L1.push_back(xPM);
	ofstream fFile;
	fFile.open("PhieuMuon.txt", ios::app);
	fFile << endl << PhieuMuon::nTongSoPhieuM << '#' << sMaBD << '#' << sMaS << '#' << xPM.sNgayMuon() << '#' << xPM.sNgayTra() << '#' << xPM.get_nTrangThai() << '#';
	fFile.close();
	list<Sach>::iterator position = L2.begin();
	ofstream fFileBook;
	remove("Book_Data.txt");
	fFileBook.open("Book_Data.txt", ios::app);
	while (position != L2.end())
	{
		if (position->get_sMaSach() == sMaS)
		{
			position->set_nTinhTrang(PhieuMuon::nTongSoPhieuM);
		}
		position->outputFileSach();
		position++;
	}
	fFileBook.close();
	cout << "Tao phieu muon thanh cong!!!\n";
}

void thongKeSach1UserMuon(list<Sach> L1, list<BanDoc*> L2, list<PhieuMuon> L3)
{
	string sKeyMBD;
	cout << "Nhap ma BD de thong ke sach dang muon: ";
	cin.ignore(1, '\n');
	getline(cin, sKeyMBD);
	if (checkUserCode(L2, sKeyMBD) == false)
	{
		cout << "Nhap sai vui long nhap lai!\n";
		return;
	}
	string sKey;
	list<PhieuMuon>::iterator positionPM = L3.begin();
	while (positionPM != L3.end())
	{
		if (positionPM->get_sMaBD() == sKeyMBD)
		{
			sKey = positionPM->get_sMaS();
			list<Sach>::iterator positionBook = L1.begin();
			while (positionBook != L1.end())
			{
				if (positionBook->get_sMaSach() == sKey && positionBook->get_nTinhTrang() != 0)
				{
					positionBook->outputSach();
				}
				positionBook++;
			}
		}
		positionPM++;
	}
}

void findUser(list <BanDoc*> L, string sKey)
{
	list<BanDoc*>::iterator position = L.begin();
	while (position != L.end())
	{
		if ((*position)->get_sMaBD() == sKey)
		{
			cout << "*********Thong tin Ban Doc*******";
			(*position)->output();
		}
		(position)++;
	}
}

bool checkUserCode(list<BanDoc*> L, string userKey)
{
	list<BanDoc*>::iterator position = L.begin();
	while (position != L.end())
	{
		if (userKey == (*position)->get_sMaBD())
		{
			return true;
		}
		position++;
	}
	return false;
}

void addUser(list <BanDoc*> &L)
{
	int nLoaiBD;
	string sMaBD;
	string sHoTen;
	string sKhoa;
	int nNgay;
	int nThang;
	int nNam;
	Date xNgayThamGia;
	//Giao Vien
	string sDiaChi;
	string sSoDT;
	//Sinh Vien
	int nKhoaHoc;
	cout << "********Chon Phuong Thuc Them*********" << endl;
	cout << "1. Giao Vien\n";
	cout << "2. Sinh Vien \n";
	cout << "-1. Thoat \n";
	do {
		cout << "Chon: ";
		cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			cout << "Nhap ma giao vien: ";
			cin.ignore(1, '\n');
			getline(cin, sMaBD);
			cout << "Nhap Ho Ten: ";
			cin.ignore(1, '\n');
			getline(cin, sHoTen);
			cout << "Nhap Khoa: ";
			cin.ignore(1, '\n');
			getline(cin, sKhoa);
			cout << "Nhap ngay thang nam lam the: ";
			cout << "Ngay: ";
			cin >> nNgay;
			cout << "Thang: ";
			cin >> nThang;
			cout << "Nam: ";
			cin >> nNam;
			cout << "Nhap dia chi: ";
			cin.ignore(1, '\n');
			getline(cin, sDiaChi);
			cout << "Nhap so Dien Thoai: ";
			cin.ignore(1, '\n');
			getline(cin, sSoDT);
			GiaoVien * xGV = new GiaoVien(sMaBD, sHoTen, sHoTen, nNgay, nThang, nNam, sDiaChi, sSoDT);
			L.push_back(xGV);
			ofstream fFile;
			fFile.open("User_Data.txt", ios::app);
			fFile << endl << nLoaiBD << '#' << sMaBD << '#' << sHoTen << '#' << sHoTen << '#' << nNgay << '/' << nThang << '/' << nNam << '#' << sDiaChi << '#' << sSoDT;
			fFile.close();
		}
		else {
			if (nLoaiBD == 2)
			{
				do {
					cout << "Nhap ma sinh vien: ";
					cin.ignore(1, '\n');
					getline(cin, sMaBD);
					if (checkUserCode(L, sMaBD) == true)
						cout << "Da co ma ban doc nay hay nhap lai ma ban doc khac\n";
				} while (checkUserCode(L, sMaBD) == true);

				cout << "Nhap Ho Ten: ";
				cin.ignore(1, '\n');
				getline(cin, sHoTen);
				cout << "Nhap Khoa: ";
				cin.ignore(1, '\n');
				getline(cin, sKhoa);
				cout << "Nhap ngay thang nam lam the: ";
				cout << "Ngay: ";
				cin >> nNgay;
				cout << "Thang: ";
				cin >> nThang;
				cout << "Nam: ";
				cin >> nNam;
				cout << "Nien Khoa: ";
				cin >> nKhoaHoc;
				SinhVien * xSV = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
				L.push_back(xSV);
				ofstream fFile;
				fFile.open("User_Data.txt", ios::app);
				fFile << endl << nLoaiBD << '#' << sMaBD << '#' << sHoTen << '#' << sHoTen << '#' << nNgay << '/' << nThang << '/' << nNam << '#' << nKhoaHoc;
				fFile.close();
			}
		}
	} while (nLoaiBD != -1);
}

bool checkAdmin(list<Admin> L, string sUser, string sPass)
{
	list<Admin>::iterator position = L.begin();
	while (position != L.end())
	{
		if (position->get_sUsername() == sUser && position->get_sPassword() == sPass)
		{
			return true;
		}
		position++;
	}
	return false;
}

void outputPM(list<PhieuMuon> L)
{
	list<PhieuMuon>::iterator position = L.begin();
	while (position != L.end())
	{
		position->outputPM();
		position++;
	}
}

void inputDSPhieuMuon(list <PhieuMuon> &L)
{
	ifstream file;
	file.open("PhieuMuon.txt");
	file.is_open();
	//Khai bao bien:
	int nNgayM = 0, nThangM = 0, nNamM = 0, nNgayT = 0, nThangT = 0, nNamT = 0, nTrangThai = 0;
	int nTongSoPhieuM;
	string sMaPM = "";
	string sMaBD = "", sMaSach = "";
	string line;
	while (getline(file, line))
	{
		file >> nTongSoPhieuM;
		file.ignore(1, '#');
		getline(file, sMaBD, '#');
		getline(file, sMaSach, '#');
		file >> nNgayM;
		file.ignore(1, '/');
		file >> nThangM;
		file.ignore(1, '/');
		file >> nNamM;
		file.ignore(1, '#');
		file >> nNgayT;
		file.ignore(1, '/');
		file >> nThangT;
		file.ignore(1, '/');
		file >> nNamT;
		file.ignore(1, '#');
		file >> nTrangThai;
		file.ignore(1, '\n');
		PhieuMuon PM = PhieuMuon(nTongSoPhieuM, sMaBD, sMaSach, nNgayM, nThangM, nNamM, nNgayT, nThangT, nNamT, nTrangThai);
		L.push_back(PM);
	}
	file.close();
}

void outputAdminList(list <Admin> L)
{
	list<Admin>::iterator position = L.begin();
	while (position != L.end())
	{
		position->output();
		position++;
	}
}

void inputAdminList(list <Admin> &L)
{
	string sUsername;
	string sPassword;
	ifstream fFile;
	fFile.open("Admin.txt");
	string line;
	while (getline(fFile, line))
	{
		getline(fFile, sUsername, '#');
		getline(fFile, sPassword, '#');
		Admin xAdmin = Admin(sUsername, sPassword);
		L.push_back(xAdmin);
	}
	fFile.close();
}

void outputUserList(list<BanDoc*> L)
{
	list<BanDoc*>::iterator position = L.begin();
	while (position != L.end())
	{
		(*position)->output();
		cout << endl;
		position++;
	}
	cout << L.size();
}

void inputUserList(list <BanDoc*> &L)
{
	int nLoaiBD;
	string sMaBD;
	string sHoTen;
	string sKhoa;
	int nNgay;
	int nThang;
	int nNam;
	Date xNgayThamGia;
	//Giao Vien
	string sDiaChi;
	string sSoDT;
	//Sinh Vien
	int nKhoaHoc;
	ifstream fFile;
	fFile.open("User_Data.txt");
	string line;
	while (getline(fFile, line))
	{
		fFile >> nLoaiBD;
		fFile.ignore(1, '#');
		getline(fFile, sMaBD, '#');
		getline(fFile, sHoTen, '#');
		getline(fFile, sKhoa, '#');
		if (nLoaiBD == 1)
		{
			fFile >> nNgay;
			fFile.ignore(1, '/');
			fFile >> nThang;
			fFile.ignore(1, '/');
			fFile >> nNam;
			fFile.ignore(1, '#');
			getline(fFile, sDiaChi, '#');
			getline(fFile, sSoDT, '#');
			GiaoVien * xGV = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDiaChi, sSoDT);
			L.push_back(xGV);
		}
		if (nLoaiBD == 2)
		{
			fFile >> nNgay;
			fFile.ignore(1, '/');
			fFile >> nThang;
			fFile.ignore(1, '/');
			fFile >> nNam;
			fFile.ignore(1, '#');
			fFile >> nKhoaHoc;
			fFile.ignore(1, '#');
			SinhVien * xSV = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			L.push_back(xSV);
		}
	}
	fFile.close();
}

void findBook(list<Sach> L, string sKey)
{
	cout << setw(5) << "Ma sach" << setw(15) << "Tua de sach" << setw(13) << "Tac gia" <<
		setw(15) << "Nha XB" << setw(15) << "Tri gia" << setw(15) << "Nam XB" << setw(15) << "So trang" <<
		setw(15) << "Ngay nhap kho" << setw(12) << "Tinh trang" << endl;
	list<Sach>::iterator position = L.begin();

	while (position != L.end())
	{
		if (position->get_sMaSach() == sKey)
		{
			position->outputSach();
		}
		position++;
	}
}

int countBookInLi(list<Sach> L)
{
	int nDem = 0;
	list<Sach>::iterator position = L.begin();
	while (position != L.end())
	{
		if (position->get_nTinhTrang() == 0)
			nDem++;
		position++;
	}
	return nDem;
}

void deleteBook(list<Sach> &L, string sKey)
{
	list<Sach>::iterator position = L.begin();

	if (checkBookStatus(L, sKey) == true)
	{
		remove("Book_Data.txt");
		while (position != L.end())
		{
			if (position->get_sMaSach() == sKey)
			{
				position = L.erase(position);
			}
			else {
				position->outputFileSach();
				position++;
			}
		}
	}
	else {
		cout << "Sach nay dang co nguoi muon khong the xoa!!!\n";
	}
}

bool checkBookStatus(list<Sach> L, string sKey)
{
	list<Sach>::iterator position = L.begin();
	while (position != L.end())
	{
		if (position->get_nTinhTrang() == 0 && position->get_sMaSach() == sKey)
		{
			return true;
		}
		position++;
	}
	return false;
}

bool checkBookCode(list<Sach> L, string sKey)
{
	list<Sach>::iterator position = L.begin();
	while (position != L.end())
	{
		if (sKey == position->get_sMaSach())
		{
			return true;
		}
		position++;
	}
	return false;
}

void addBook(list<Sach> &L)
{
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNhaXB;
	float fTriGia;
	int nNamXB;
	int nSoTrang;
	Date xNgayNhapKho;
	int nTinhTrang = 0;
	int nNgay, nThang, nNam;
	do
	{
		cout << "Nhap ma sach: ";
		cin.ignore(1, '\n');
		getline(cin, sMaSach);
		if (checkBookCode(L, sMaSach) == true)
			cout << "Da co ma sach nay trong thu vien hay nhap lai ma sach khac\n";
	} while (checkBookCode(L, sMaSach) == true);
	cout << "Nhap tua de: ";
	getline(cin, sTuaDe);
	cout << "Nhap tac gia: ";
	getline(cin, sTacGia);
	cout << "Nhap nha XB: ";
	getline(cin, sNhaXB);
	cout << "Nhap tri gia: ";
	cin >> fTriGia;
	cout << "Nhap nam XB: ";
	cin >> nNamXB;
	cout << "Nhap so trang: ";
	cin >> nSoTrang;
	cout << "Nhap ngay thang nam nhap kho: ";
	cout << "Ngay: ";
	cin >> nNgay;
	cout << "Thang: ";
	cin >> nThang;
	cout << "Nam: ";
	cin >> nNam;
	Sach xSach = Sach(sMaSach, sTuaDe, sTacGia, sNhaXB, fTriGia, nNamXB, nSoTrang, nNgay, nThang, nNam, nTinhTrang);
	L.push_back(xSach);
	ofstream fFile;
	fFile.open("Book_Data.txt", ios::app);
	fFile << endl << sMaSach << '#' << sTuaDe << '#' << sTacGia << '#' << sNhaXB << '#' << fTriGia << '#' << nNamXB << '#' << nSoTrang << '#' << nNgay << '/' << nThang << '/' << nNam << '#' << nTinhTrang;
	fFile.close();
}

void outputBookList(list<Sach> L)
{
	cout << setw(5) << "Ma sach" << setw(15) << "Tua de sach" << setw(13) << "Tac gia" <<
		setw(15) << "Nha XB" << setw(15) << "Tri gia" << setw(15) << "Nam XB" << setw(15) << "So trang" <<
		setw(15) << "Ngay nhap kho" << setw(12) << "Tinh trang" << endl;
	list<Sach>::iterator position = L.begin();
	while (position != L.end())
	{
		position->outputSach();
		position++;
	}
}

void inputBookList(list <Sach> &L)
{
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNhaXB;
	float fTriGia;
	int nNamXB;
	int nSoTrang;
	int nTinhTrang;
	int nNgay, nThang, nNam;
	Date xNgayNhapKho;
	ifstream fFile;
	fFile.open("Book_Data.txt");
	string line;
	while (getline(fFile, line))
	{
		getline(fFile, sMaSach, '#');
		getline(fFile, sTuaDe, '#');
		getline(fFile, sTacGia, '#');
		getline(fFile, sNhaXB, '#');
		fFile >> fTriGia;
		fFile.ignore(1, '#');
		fFile >> nNamXB;
		fFile.ignore(1, '#');
		fFile >> nSoTrang;
		fFile.ignore(1, '#');
		fFile >> nNgay;
		fFile.ignore(1, '/');
		fFile >> nThang;
		fFile.ignore(1, '/');
		fFile >> nNam;
		fFile.ignore(1, '#');
		fFile >> nTinhTrang;
		Sach xSach = Sach(sMaSach, sTuaDe, sTacGia, sNhaXB, fTriGia, nNamXB, nSoTrang, nNgay, nThang, nNam, nTinhTrang);
		L.push_back(xSach);
	}
	fFile.close();
}

string hidePasswordInput() //Cre: stackOverflow || C plus plus
{
	string sPass;
	char c;
	do {
		c = _getch();
		switch (c) {
		case 0://special keys. like: arrows, f1-12 etc.
			_getch();//just ignore also the next character.
			break;
		case 13://enter
			cout << endl;
			break;
		case 8://backspace
			if (sPass.length() > 0) {
				sPass.erase(sPass.end() - 1); //remove last character from string
				cout << c << ' ' << c;//go back, write space over the character and back again.
			}
			break;
		default://regular ascii
			sPass += c;//add to string
			cout << '*';//print `*`
			break;
		}
	} while (c != 13);
	return sPass;
}