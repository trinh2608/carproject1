#include "Display.h"


Display::Display() { // các giá trị khởi tạo
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display() {
}

int Display::get_light_level() {
	return light_level;
}

int Display::get_screen_light_level() {
	return screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}
void Display::set_light_level(int data) {
	light_level = data;
}

void Display::set_screen_light_level(int data) {
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	taplo_light_level = data;
}

void Display::nhapThongTin() { // nhập 3 giá trị private của display
	int kiemTra = 0;
	string lightLevelString; // các biến kiểm tra xem có nhập kí tự hay không
	string screenLightLevelString;
	string taploLightLevelString;

	cout << "Enter Light Level: ";
	do {
		kiemTra = 0;
		cin >> lightLevelString;
		if (lightLevelString >= "a" && lightLevelString <= "z" || lightLevelString >= "A" && lightLevelString <= "Z" || lightLevelString.length() > 1) {
			cout << "CANT INPUTING CHARACTER, MUST BE [1,9]" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			light_level = atoi(lightLevelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;

	cout << "Enter Screen Light Level: ";
	do {
		kiemTra = 0;
		cin >> screenLightLevelString;
		if (screenLightLevelString >= "a" && screenLightLevelString <= "z" || screenLightLevelString >= "A" && screenLightLevelString <= "Z" || screenLightLevelString.length() > 1) {
			cout << "CANT INPUTING CHARACTER, MUST BE [1,9]" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			screen_light_level = atoi(screenLightLevelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;

	cout << "Enter Taplo Light Level: ";
	do {
		kiemTra = 0;
		cin >> taploLightLevelString;
		if (taploLightLevelString >= "a" && taploLightLevelString <= "z" || taploLightLevelString >= "A" && taploLightLevelString <= "Z" || taploLightLevelString.length() > 1) {
			cout << "CANT INPUTING CHARACTER, MUST BE [1,9]" << endl;
			cout << "YOUR VALUE: ";
			kiemTra = 1;
		}
		else {
			taplo_light_level = atoi(taploLightLevelString.c_str());
		}
	} while (kiemTra == 1);
	cout << endl;
}

void Display::xuatThongTin() {
	//cout << "Email: " << this->getEmail() << endl;
	//cout << "Car Name: " << this->getCarName() << endl;
	//cout << "Key Number: " << this->getPersonalKey() << endl;
	//cout << "ODO Number: " << this->getODO() << endl;
	//cout << "Remind service: " << this->getServiceRemind() << endl;
	cout << "Light Level:" << light_level << endl;
	cout << "Screen Light Level: " << screen_light_level;
	cout << "Taplo Light Level: " << taplo_light_level;

}