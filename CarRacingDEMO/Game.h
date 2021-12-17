#pragma once
#include "Car.h"
#include "Obstacle.h"
class Game
{
private:
	Car* objCar;
	vector <Obstacle*> arrObstacle;
	float difficulty;
	time_t timer;
public:
	Game();
	~Game();

	void Insert_Obstacles();
	void Draw_Car(Graphics^ g, Bitmap^ bmp);
	void Draw_Obstacle(Graphics^ g, Bitmap^ bmp);
	void Colision();
	bool End_Game();

	void new_orientation(direction new_data);
	System::String^ return_text_lifes();
};



