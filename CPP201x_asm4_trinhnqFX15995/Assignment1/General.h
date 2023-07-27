#ifndef GENERAL_H_
#define GENERAL_H_

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class General {
private:
	string timeZone; // timezone đọc từ file lên
	string language;// language đọc từ file lên
public:
	General();
	~General();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
	void printTT();// hàm hiện ra các giá trị timezone
	void printTL();// hàm hiện ra các giá trị language
};


#endif 
