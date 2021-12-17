#pragma once
#include "Entity.h"
class Obstacle : public Entity
{
private:
	int type;
public:
	Obstacle();
	Obstacle(int px, int py, int pw, int ph);
	~Obstacle();

	void new_type(int new_data);
	int return_type();

	void Move(Graphics^ g);
	void Draw_from_image(Graphics^ g, Bitmap^ bmp);
};


