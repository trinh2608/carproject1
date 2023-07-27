#include "General.h"
#include "CommonInfo.h"
#include <string>
using namespace std;
extern vector<CommonInfo> timezoneList; //dùng extern để lấy dữ liệu được từ main
extern vector<CommonInfo> languageList; //dùng extern để lấy dữ liệu được từ main

void General::printTT() { // hàm in thông tin timezonelist
	for (int n = 0; n < timezoneList.size(); ++n) {
		CommonInfo cInfo = timezoneList[n];
		cout << n + 1 << " ." << cInfo.getNumber() << ": " << cInfo.getName() << endl;
	}

}
void General::printTL() { // hàm in thông tin languague list
	for (int n = 0; n < languageList.size(); ++n) {
		CommonInfo cInfo = languageList[n];
		cout << n + 1 << ": " << cInfo.getName() << endl;
	}

}
General::General() {
	timeZone = "(GMT-12:00)";
	language = "Vietnamese";
}

General::~General() {
}

void General::nhapThongTin() {
	int timeZoneChoice, languageChoice = 0; // các biến đại diện cho các lựa chọn 
	string timeZoneS, languageS;
	int checkChar = 0;
	system("cls");
	cout << "Plese choose the timezone in the list: " << endl;
	General::printTT();// phải in ra danh sách cho người ta lựa chọn
	do {
		checkChar = 0;
		cin >> timeZoneS;
		if (timeZoneS >= "a" && timeZoneS <= "z" || timeZoneS >= "A" && timeZoneS <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
		else {
			timeZoneChoice = atoi(timeZoneS.c_str());
			if (timeZoneChoice > 32 || timeZoneChoice <= 0) {
				cout << " YOUR INPUT IS INVALID" << endl;
				cout << "INPUT YOUR CHOICE: ";
				checkChar = 1;
			}
		}
	} while (checkChar == 1);
	timeZone = timezoneList[timeZoneChoice - 1].getNumber(); // lưu lựa chọn vào trong biến timezone
	cout << endl;
	system("cls");
	cout << "Please choose the language in the list:  " << endl; // tương tự với language
	General::printTL();
	do {
		checkChar = 0;
		cin >> languageS;
		if (languageS >= "a" && languageS <= "z" || languageS >= "A" && languageS <= "Z") {
			cout << "CANT INPUTING CHARACTER" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
		else {
			languageChoice = atoi(languageS.c_str());
			if (languageChoice > 30 || languageChoice <= 0) {
				cout << " YOUR INPUT IS INVALID" << endl;
				cout << "INPUT YOUR CHOICE: ";
				checkChar = 1;
			}
		}
	} while (checkChar == 1);
	language = languageList[languageChoice - 1].getName();
	cout << endl;
}

void General::xuatThongTin() {
	cout << "Timezone: " << timeZone << endl;
	cout << "Language: " << language << endl;
}

string General::get_language() {
	return language;
}

string General::get_timeZone() {
	return timeZone;
}

void General::set_timeZone(string data) {
	timeZone = data;
}

void General::set_language(string data) {
	language = data;
}
