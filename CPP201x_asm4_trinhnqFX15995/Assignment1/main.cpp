#include <iostream>
#include "CommonInfo.h"
#include "Car.h"
#include <fstream>
#include <vector>
#include <vector>
#include <list>
#include <exception>
#include "BST.h" // cây nhị phân
#include "Node.h" // node của nó

using namespace std;
void swapObject(CommonInfo& obj1, CommonInfo& obj2); // hàm hoán đổi vị trí 2 đối tượng common info(dùng để sắp xếp lại file language)
void layGiaTriTuFile(string tenFile); // hàm loadfile

BST* bTree = new BST; // tạo một cây nhị phân 
list <Car> listCar3; // dùng để lưu file
vector<CommonInfo> timezoneList;// list để lưu timezone, đối tượng là commoninfo(number/name)
vector<CommonInfo> languageListCpy; // list language để sau này để lấy dữ liệu switch vị trí với languagelist
vector<CommonInfo> languageList; // list để lưu language, đối tượng là commoninfo(number/name)
void NhapThongTinCaiDat(); // lựa chọn nhập thông tin cài đặt
void XuatThongTinCaiDat(); // lựa chọn xuất thông tin cài đặt 
// các hàm xuất thông tin cài đặt 
void XuatThongTinCaiDat_Sound(); 
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTatCaTinCaiDat();
// các hàm nhập thông tin cài đặt 
void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void saveFile(); // hàm save thông tin vào file setting
void downloadTimeZone();
void downloadLanguage();
bool checkFile(string path); // hàm check xem file có tồn tại hay không 
void menu(); 

// check xem có tồn tại file hay không
bool checkFile(string path) {
	ifstream isf(path);
	return isf.good();
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	downloadLanguage(); // đầu tiên download timezone và language
	downloadTimeZone();
	layGiaTriTuFile("Setting.txt");
	menu();
	return 0;
}
void menu() { // menu màn hình chính
	
	string selection = "0"; // check xem người dùng có nhập character hay không
	int selectionT; // giá trị int của selection
	int checkChar = 0;
	system("cls");

	do {
		cout << " MH-1" << endl;
		cout << "SELECT MENU " << endl;
		cout << "1. INPUT SETTING INFORMATION" << endl;
		cout << "2. PRINT SETTING INFORMATION" << endl;
		cout << "3. EXIT" << endl;
		cout << "YOUR SELECTION: ";

		checkChar = 0;
		cin >> selection;
		if (selection >= "a" && selection <= "z" || selection >= "A" && selection <= "Z" || selection.length()>1) {
			cout << "CANT INPUTING CHARACTER, MUST BE IN [1,3]" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
	} while (checkChar == 1);
	selectionT = atoi(selection.c_str());

	switch (selectionT) {
	case 1:
		NhapThongTinCaiDat();
		break;
	case 2:
		XuatThongTinCaiDat();
	case 3:
		cout << "GOOD BYE !!!" << endl;
		saveFile(); //Luu danh sach xe
		exit(0);
		break;
	default:
		break;
	}
}

void NhapThongTinCaiDat() { // khi người dùng chọn muốn nhập thông tin
	int selection = 0;// lựa chọn loại thông tin người dùng muốn nhập
	int checkChar = 0;// biến check xem có charater hay không
	string selectionS;
	system("cls");
	cout << "MH-2: INPUT INFORMATION" << endl;
	cout << "SELECT MENU " << endl;
	cout << "1. DISPLAY SETTING" << endl;
	cout << "2. SOUND SETTING" << endl;
	cout << "3. GENERAL SETTING" << endl;
	cout << "0. EXIT" << endl;
	cout << "YOUR SELECTION: ";
	do {
		checkChar = 0;
		cin >> selectionS;
		if (selectionS >= "a" && selectionS <= "z" || selectionS >= "A" && selectionS <= "Z" || selectionS.length()>1) {
			cout << "CANT INPUTING CHARACTER, MUST BE IN [0,3]" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
	} while (checkChar == 1);
	selection = atoi(selectionS.c_str());
	system("cls");
	switch (selection) {
	case 1: { // display setting
		cout << " --- You chose input Display Setting --- " << endl;
		NhapThongTinCaiDat_Display();
		break;
	}
	case 2: {// sound setting
		cout << " --- You chose input Sound Setting --- " << endl;
		NhapThongTinCaiDat_Sound();
		break;
	}
	case 3: { // general setting
		cout << " --- You chose input General Setting --- " << endl;
		NhapThongTinCaiDat_General();
		break;
	}
	case 0:
		menu();
		break;
	default: {
		break;
	}
	}
}

void NhapThongTinCaiDat_Display() {
	char continues = 'n';
	do {
		system("cls");
		cout << " INPUT DISPLAY INFORMATION, CAR NUMBER " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();// nhập thông tin cho chiếc xe
		newCar.getDisplay()->nhapThongTin();// nhập thông tin display
		//int viTri = checkCar(newCar);
		if (bTree->search(newCar.getPersonalKey()) == NULL) {// xe không tồn tại
			cout << " --- > This is new car, it will be append to list" << endl;
			bTree->insert(newCar); // insert xe vào trong cây
		}
		else { // nếu xe đã tồn tại
			cout << "-> This car already exits, data will be override " << endl;
			bTree->search(newCar.getPersonalKey())->data.updateCar(&newCar); // update xe ở trong cây // todo 
		}
		cout << "COUTINUE WITH CAR NUMBER " << bTree->index + 1 << " ? (y/n): "; // có tiếp tục xe tiêp theo không ?
		cin >> continues;
		cout << endl;
	} while (continues == 'y');

	NhapThongTinCaiDat();
}

void NhapThongTinCaiDat_General() {
	char continues = 'n';
	do {
		system("cls");
		cout << " INPUT GENERAL INFORMATION, CAR NUMBER " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();// nhập thông tin cho chiếc xe
		newCar.getGeneral()->nhapThongTin(); // nhập thông tin cài đặt general
		if (bTree->search(newCar.getPersonalKey()) == NULL) {// xe không tồn tại
			cout << " --- > This is new car, it will be append to list" << endl;
			bTree->insert(newCar);
		}
		else { // nếu xe đã tồn tại
			cout << "-> This car already exits, data will be override " << endl;
			bTree->search(newCar.getPersonalKey())->data.updateCar(&newCar);
		}
		cout << "COUTINUE WITH CAR NUMBER " << bTree->index + 1 << " ? (y/n): ";// có tiếp tục xe tiêp theo không ?
		cin >> continues;
		cout << endl;
	} while (continues == 'y');

	NhapThongTinCaiDat();
}

void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do {
		system("cls");
		cout << " INPUT SOUND INFORMATION, CAR NUMBER " << bTree->index + 1 << endl;
		Car newCar;
		newCar.nhapThongTin();
		newCar.getSound()->nhapThongTin();// nhập thông tin sound
		if (bTree->search(newCar.getPersonalKey()) == NULL) {// xe không tồn tại
			cout << " --- > This is new car, it will be append to list" << endl;
			bTree->insert(newCar);
		}
		else { // nếu xe đã tồn tại
			cout << "-> This car already exits, data will be override " << endl;
			bTree->search(newCar.getPersonalKey())->data.updateCar(&newCar);
		}
		cout << "COUTINUE WITH CAR NUMBER " << bTree->index + 1 << " ? (y/n): ";// có tiếp tục xe tiêp theo không ?
		cin >> continues;
		cout << endl;
	} while (continues == 'y');

	NhapThongTinCaiDat();
}

void XuatThongTinCaiDat() // khi người dùng chọn xuất thông tin cài đặt
{ 
	//listCar3.clear(); // clear cái list này rồi add dữ liệu vào từ đầu
	//bTree->leftNodeRight(); // add và sắp xếp dữ liệu 
	int selection = 0;
	int checkChar = 0;
	string selectionS;
	system("cls");
	cout << " MH-3" << endl;
	cout << "SELECT MENU " << endl;
	cout << "1. Print Display setting" << endl;
	cout << "2. Print Sound setting" << endl;
	cout << "3. Print General setting" << endl;
	cout << "4. Print all setting information" << endl;
	cout << "5. Back" << endl;
	cout << "YOUR SELECTION: ";
	do {
		checkChar = 0;
		cin >> selectionS;
		if (selectionS >= "a" && selectionS <= "z" || selectionS >= "A" && selectionS <= "Z" || selectionS.length() > 1) {
			cout << "CANT INPUTING CHARACTER, MUST BE IN [1,5]" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
	} while (checkChar == 1);
	selection = atoi(selectionS.c_str());
	switch (selection) {
	case 1: {
		cout << " --- You chose print Display Setting --- " << endl;
		XuatThongTinCaiDat_Display(); //
		break;
	}
	case 2: {
		cout << " --- You chose print Sound Setting --- " << endl;
		XuatThongTinCaiDat_Sound();
		break;
	}
	case 3: {
		cout << " --- You chose print General Setting --- " << endl;
		XuatThongTinCaiDat_General();
		break;
	}
	case 4: {
		cout << " --- You chose print all Setting information--- " << endl;
		XuatThongTatCaTinCaiDat();
		break;
	}
	case 5: {
		menu();
		break;
	}
	}
	system("pause");

}



const vector<string> explode(const string& s, const char& c) // hàm phân tách chuỗi cho timezones và language. Phân tách ra các dòng khi gặp kí tự c
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

void downloadTimeZone() {
	ifstream f;
	f.open("timezones.txt");
	if (f.fail()) { // check xem có mở được file không 
		cout << "CAN'T OPEN FILE" << endl;
	}
	else { // lấy dữ liệu từ file
		while (!f.eof()) {
			string line;
			getline(f, line);
			vector <string> data = explode(line, '/'); // phân chia dữ liệu bằng dấu / thành number và name
			if (data.size() >= 2) {
				CommonInfo newInf;
				newInf.setNumber(data[0]);
				newInf.setName(data[1]);
				cout << data[0] << " " << data[1] << endl;
				timezoneList.push_back(newInf);
			}
		}
	}
	f.close();

	vector<string> names;
	for (int i = 0; i < timezoneList.size(); i++) {
		names.push_back(timezoneList[i].getName());	// coppy data of timezoneList into vector names
	}
	sort(names.begin(), names.end());	// sort data aphabatically
	for (int i = 0; i < names.size(); i++) {		// acording to the order of data in vector names, I rearrange the order of data of timezoneList
		for (int j = 0; j < timezoneList.size(); j++) {
			if (names[i] == timezoneList[j].getName()) {
				swapObject(timezoneList[i], timezoneList[j]);//swapp 2 obj
			}
		}
	}
}

void downloadLanguage() { // tương tự áp dụng hàm trên vào hàm download language
	ifstream f;
	f.open("languages.txt"); // mở file
	if (f.fail()) { // nếu mở thất bại
		cout << "CAN'T OPEN FILE" << endl;
	}
	else {
		while (!f.eof()) {
			string line;
			getline(f, line);
			vector <string> data = explode(line, '/');
			if (data.size() >= 2) {
				CommonInfo newInf;
				newInf.setNumber(data[0]);
				newInf.setName(data[1]);
				cout << data[0] << " " << data[1] << endl;
				languageList.push_back(newInf);
				languageListCpy.push_back(newInf);
			}
		}
	}

	f.close();

	vector<string> names;
	for (int i = 0; i < languageList.size(); i++) {
		names.push_back(languageList[i].getName());
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < names.size(); i++) {
		for (int j = 0; j < languageList.size(); j++) {
			if (names[i] == languageList[j].getName()) {
				swapObject(languageList[i], languageList[j]);
				languageList[i].setNumber(languageListCpy[i].getNumber());
			}
		}
	}
}

void swapObject(CommonInfo& obj1, CommonInfo& obj2) {	// swap 2 CommInfo objs
	CommonInfo temp;
	temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}

void XuatThongTinCaiDat_Sound() {
	cout << setw(20) << "OWNER NAME" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
	bTree->leftNodeRight(2);
	//}
	system("pause");

	XuatThongTinCaiDat();
}

void XuatThongTinCaiDat_General() {
	cout << setw(20) << "OWNER NAME" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(30) << "TimeZone" << setw(20) << "Language" << endl;

	bTree->leftNodeRight(3);

	system("pause");

	XuatThongTinCaiDat();
}

void XuatThongTinCaiDat_Display() {
	cout << setw(20) << "OWNER NAME" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;

	bTree->leftNodeRight(1);
	system("pause");
	XuatThongTinCaiDat();
}
void layGiaTriTuFile(string tenFile) { // get dữ liệu từ file setting.txt
	if (checkFile("Setting.txt") == true) { 
		ifstream ifile("Setting.txt");
		if (ifile.fail()) { // check xem có mở được file không
			cout << "CAN'T OPEN FILE" << endl;
		}
		else {
			string name;
			string pk;
			string email;
			int odo;
			int svRemind;
			int lightLevel;
			int taploLightLevel;
			int screenLightLevel;
			string timeZone;
			string language;
			int mediaLevel;
			int callLevel;
			int naviLevel;
			int notiLevel;
			string line;
			int n;
			ifile >> n;
			for (int i = 0; i < n; i++) {
				Car newCar;
				getline(ifile, name, ';');
				getline(ifile, email, ';');
				getline(ifile, pk, ';');
				ifile >> odo >> svRemind >> lightLevel >> taploLightLevel >> screenLightLevel;
				getline(ifile, timeZone, ';');
				getline(ifile, language, ';');
				ifile >> mediaLevel >> callLevel >> naviLevel >> notiLevel;
				newCar.setCarName(name);
				newCar.setEmail(email);
				newCar.setPersonalKey(pk);
				newCar.setODO(odo);
				newCar.setServiceRemind(svRemind);
				newCar.getDisplay()->set_light_level(lightLevel);
				newCar.getDisplay()->set_screen_light_level(screenLightLevel);
				newCar.getDisplay()->set_taplo_light_level(taploLightLevel);
				newCar.getSound()->set_call_level(callLevel);
				newCar.getSound()->set_media_level(mediaLevel);
				newCar.getSound()->set_navi_level(naviLevel);
				newCar.getSound()->set_notification_level(notiLevel);
				newCar.getGeneral()->set_language(language);
				newCar.getGeneral()->set_timeZone(timeZone);
				bTree->insert(newCar); // insert từng giá trị vào cây 

			}
		}
		ifile.close();
	}
}

void XuatThongTatCaTinCaiDat() {
	string selection = "0"; // check xem người dùng có nhập character hay không
	int checkChar = 0;
	string info;
	system("cls");
	cout << "PLEASE CHOOSE PRINT INFO BASE ON: " << endl;
	cout << "1: Personal Key" << endl;
	cout << "2: Car Name" << endl;
	do {
		checkChar = 0;
		cin >> selection;
		if (selection >= "a" && selection <= "z" || selection >= "A" && selection <= "Z" || selection.length()>1) {
			cout << "MUST BE 1 OR 2" << endl;
			cout << "YOUR SELECTION: ";
			checkChar = 1;
		}
	} while (checkChar == 1);
	if (selection == "1") {
		cout << "Please enter Key: ";
		cin.ignore();
		getline(cin, info);
		cout << setw(20) << "OWNER NAME" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << setw(30) << "TimeZone" << setw(20) << "Language" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
		bTree->searchNodeByKey(info); // đưa giá trị có key trùng vời key người dùng nhập 
		system("pause");
	}

	if (selection == "2") {
		cout << "Please enter Car Name: ";
		cin.ignore();
		getline(cin, info);
		cout << setw(20) << "OWNER NAME" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << setw(30) << "TimeZone" << setw(20) << "Language" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
		bTree->searchNodeByName(info); // đưa giá trị có carName trùng vời carName người dùng nhập 
		system("pause");
	}
	XuatThongTinCaiDat();
}

void saveFile() { // lưu giá trị vào file setting .txt
	if (bTree->index== 0) { // 0 có xe nào được lưu
		cout << "there's no car in memory." << endl;
	}
	else {
		listCar3.clear(); // clear list 3 và add, sắp xếp lại
		bTree->addElementToSave();
		ofstream ofile("Setting.txt", ios_base::out | ios_base::trunc);
		try { // kiểm tra ngoại lệ 
			if (ofile.is_open()) {
				list <Car>::iterator iter = listCar3.begin();
				ofile << bTree->index; // lưu số xe cho mở file dễ hiểu 
				while (iter != listCar3.end()) { // lưu từng giá trị xe vào. 
					ofile << iter->getCarName() << ";" << iter->getEmail() << ";" << iter->getPersonalKey() << ";" << iter->getODO() << " " << iter->getServiceRemind() << " " << endl <<// dòng 1 t tin cá nhân của xe
						iter->getDisplay()->get_light_level() << " " << iter->getDisplay()->get_taplo_light_level() << " " << iter->getDisplay()->get_screen_light_level() << " " <<  // t tin display của xe
						iter->getGeneral()->get_timeZone() << ";" << iter->getGeneral()->get_language() << ";" << endl <<// dòng 3 t tin language, timezone
						iter->getSound()->get_media_level() << " " << iter->getSound()->get_call_level() << " " << iter->getSound()->get_navi_level() << " " << iter->getSound()->get_notification_level(); // dòng 4 sound
					iter++;
				}
				ofile.close();
			}
			else {
				throw exception(); // throw except
			}
		}
		catch (const exception& e) { 
			cerr << "Can't open file " << endl;
		}
	}
}
