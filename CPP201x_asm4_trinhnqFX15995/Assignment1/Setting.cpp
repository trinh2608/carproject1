#include "Setting.h"
#include <string>
#include <regex> // regex để kiểm tra 

Setting::Setting()
{
	car_name = "";
	personal_key = "00000000";
	email = "abc@xyz.def";
	odo = 1;
	service_remind = 1000;
}

Setting::~Setting() {}

string Setting::getCarName() {
	return car_name;
}

string Setting::getPersonalKey() {
	return personal_key;
}

int Setting::getODO() {
	return odo;
}

int Setting::getServiceRemind() {
	return service_remind;
}

string Setting::getEmail() {
	return email;
}

void Setting::nhapThongTin() {
	int kiemTra = 0; // biến kiểm tra
	string odoString; // các biến kiểm tra xem có nhập kí tự hay không.
	string srString;
	cin.ignore();  // thêm vào để xoá bộ nhớ đệm, tránh bị trôi lệnh
	cout << "PLEASE, ENTER THE OWNER NAME: ";
	getline(cin, car_name);
	cout << endl;
	do {
		kiemTra = 0;
		cout << "ENTER THE KEY NUM: ";
		cin >> personal_key;
		cout << endl;
		for (int i = 0; i < personal_key.length(); i++) { // kiểm tra xem có nhập kí tự chữ vào không
			if (personal_key[i] >= 'a' && personal_key[i] <= 'z' || personal_key[i] >= 'A' && personal_key[i] <= 'Z') {
				kiemTra = 1;
			}
		}
		if (kiemTra != 0) { // nếu có kí tự chữ 
			cout << " PERSONAL KEY MUSTN'T HAVE CHARACTER" << endl;
		}
		if (personal_key.length() != 8) { // nếu không có chính xác 8 kí tự
			cout << " PERSONAL KEY MUST HAVE 8 NUMBER" << endl;
			kiemTra = 1;
		}

	} while (kiemTra != 0);
	cin.ignore();
	do { // nhập email
		kiemTra = 0;
		cout << "ENTER THE EMAIL: ";
		getline(cin, email);
		string pattern = "\\w+@\\w{3}\\.\\w{3}"; // pattern cho regex 
		regex regexRule(pattern);
		bool isValid = regex_match(email, regexRule); // biến kiểm tra xem email nhập vào có phù hợp không
		if (!isValid) {
			cout << " EMAIL MUST HAVE TYPE abc@xyz.def" << endl;
			kiemTra = 1;
		}
	} while (kiemTra == 1);
	cout << endl;

	cout << "ENTER THE ODO: "; // odo
	do {
		kiemTra = 0;
		cin >> odoString;
		if (odoString >= "a" && odoString <= "z" || odoString >= "A" && odoString <= "Z" || odoString.length() > 1) {
			cout << "CANT INPUT CHARACTER, MUST BE IN [1,9]" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			odo = atoi(odoString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;

	cout << "ENTER THE SERVICE_REMIND (1000Km): "; // service remind
	do {
		kiemTra = 0;
		cin >> srString;
		if (srString >= "a" && srString <= "z" || srString >= "A" && srString <= "Z" || srString.length() > 1) {
			cout << "CANT INPUTING CHARACTER, MUST BE IN [1,9] " << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			service_remind = atoi(srString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
}

void Setting::xuatThongTin() {
	cout << "Email: " << email << endl;
	cout << "Car Name: " << car_name << endl;
	cout << "Key Number: " << personal_key << endl;
	cout << "ODO Number: " << odo << endl;
	cout << "Remind service: " << service_remind << endl;

}

void Setting::setCarName(string value) {
	car_name = value;
}
void Setting::setPersonalKey(string value) {
	personal_key = value;
}
void Setting::setEmail(string value) {
	email = value;
}
void Setting::setODO(int value) {
	odo = value;
}
void Setting::setServiceRemind(int value) {
	service_remind = value;
}