#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo {
private:
	string number;// dữ liệu trước dấu / (của languages và timezones)
	string name;// dữ liệu sau dấu / (của languages và timezones)

public:// các hàm set và get
	string getNumber() {
		return number;
	}

	string getName() {
		return name;
	}

	void setNumber(string data) {
		number = data;
	}

	void setName(string data) {
		name = data;
	}

	void printData(int i) { // in ra cho phép người dùng xem để chọn 
		cout << " Owner name: " << name << endl << "Number: " << number << endl;
	}
};

#endif // COMMON_H_

