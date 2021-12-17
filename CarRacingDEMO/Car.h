#pragma once
#include "Entity.h"
class Car : public Entity
{
private:
	int lifes;
public:
	Car();
	Car(int px, int py, int pw, int ph);
	~Car();

	void new_lifes(int new_data);
	int return_lifes();
};



