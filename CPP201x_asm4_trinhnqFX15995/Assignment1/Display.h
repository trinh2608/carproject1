#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>
#include <string>
using namespace std;

class Display {
private:
	int light_level; // 3 giá trị cần nhập của display
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	~Display();
	virtual void nhapThongTin();
	virtual void xuatThongTin();
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
};

#endif /* DISPLAY_H_ */