#include "Car.h"

using namespace std;
Car::Car():Setting() { // khởi tạo đối tượng
	display = new Display();
	sound = new Sound();
	general = new General();
}
Car::~Car() {
	if (display != nullptr) {
		display = nullptr;
	}
	if (sound != nullptr) {
		sound = nullptr;
	}
	if (general != nullptr) {
		general = nullptr;
	}
}

Display* Car::getDisplay() { 
	if (display == nullptr) {
		display = new Display();
	}
	return display;
}
Sound* Car::getSound() {
	if (sound == nullptr) {
		sound = new Sound();
	}
	return sound;
}
General* Car::getGeneral() {
	if (general == nullptr) {
		general = new General();
	}
	return general;
}

void Car::updateCar(Car* newCar) {

	this->setCarName(this->getCarName());
	this->setPersonalKey(this->getPersonalKey());
	this->setEmail(this->getEmail());
	this->setODO(this->getODO());
	this->setServiceRemind(this->getServiceRemind());
	// bắt đầu gán display
	this->getDisplay()->set_light_level(newCar->getDisplay()->get_light_level());
	this->getDisplay()->set_screen_light_level(newCar->getDisplay()->get_screen_light_level());
	this->getDisplay()->set_taplo_light_level(newCar->getDisplay()->get_taplo_light_level());
	// sound
	this->getSound()->set_call_level(newCar->getSound()->get_call_level());
	this->getSound()->set_media_level(newCar->getSound()->get_media_level());
	this->getSound()->set_navi_level(newCar->getSound()->get_navi_level());
	this->getSound()->set_notification_level(newCar->getSound()->get_notification_level());

	// bắt đầu gán general
	this->getGeneral()->set_language(newCar->getGeneral()->get_language());
	this->getGeneral()->set_timeZone(newCar->getGeneral()->get_timeZone());
		

}
