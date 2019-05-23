#include "Admin.h"

void Admin::output()
{
	cout << "Username: " << this->sUsername << endl;
	cout << "Password: " << this->sPassword << endl;
}

string Admin::get_sUsername()
{
	return sUsername;
}
string Admin::get_sPassword()
{
	return sPassword;
}
void Admin::set_sUsername(string sUsername)
{
	this->sUsername = sUsername;
}
void Admin::set_sPassword(string sPassword)
{
	this->sPassword = sPassword;
}