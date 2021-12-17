#include "Car.h"
Car::Car() {}
Car::Car(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 1, 0, 0) {
	lifes = 5;
	vertical_velocity = 0;
	horizontal_velocity = 25;
	new_orientation(direction::still);
}
Car::~Car() {}
void Car::new_lifes(int new_data) { lifes = new_data; }
int Car::return_lifes() { return lifes; }