#pragma once
#include <iostream>
#include <string>
using namespace std;
class Admin
{
private:
	string sUsername;
	string sPassword;
public:
	string get_sUsername();
	string get_sPassword();
	void set_sUsername(string sUsername);
	void set_sPassword(string sPassword);
	void output();
	Admin(string sUsername = " ", string sPassword = " ")
	{
		this->sUsername = sUsername;
		this->sPassword = sPassword;
	}
	~Admin() {};
};
