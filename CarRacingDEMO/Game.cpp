#include "Game.h"
Game::Game() {
	objCar = new Car(365, 500, 1, 1);
	timer = time(0);
	difficulty = 1.5;
}
Game::~Game() {}
void Game::Insert_Obstacles() {
	System::Random^ rnd = gcnew System::Random();
	if (difftime(time(0), timer) > difficulty) {
		timer = time(0);
		if (difficulty >= 0.2) {
			difficulty -= 0.1;
		}
		arrObstacle.push_back(new Obstacle(rnd->Next(0, 700), 5, 1, 1));
		arrObstacle.at(arrObstacle.size() - 1)->new_type(rnd->Next(0, 6));
	}
	for (int i = 0; i < arrObstacle.size(); i++) {
		if (arrObstacle.at(i)->return_flag()) {
			arrObstacle.erase(arrObstacle.begin() + i);
		}
	}
	delete rnd;
}
void Game::Draw_Car(Graphics^ g, Bitmap^ bmp) {
	objCar->Draw_from_image(g, bmp);
	objCar->Move(g);
}
void Game::Draw_Obstacle(Graphics^ g, Bitmap^ bmp) {
	for (int i = 0; i < arrObstacle.size(); i++) {
		arrObstacle.at(i)->Draw_from_image(g, bmp);
		arrObstacle.at(i)->Move(g);
	}
}
void Game::Colision() {
	for (int i = 0; i < arrObstacle.size(); i++) {
		if (objCar->return_rectangle().IntersectsWith(arrObstacle.at(i)->return_rectangle())) {
			objCar->new_lifes(objCar->return_lifes() - 1);
			arrObstacle.erase(arrObstacle.begin() + i);
		}
	}
}
bool Game::End_Game() {
	if (objCar->return_lifes() <= 0)
		return true;
	return false;
}
void Game::new_orientation(direction new_data) {
	objCar->new_orientation(new_data);
}
System::String^ Game::return_text_lifes() {
	System::String^ phrase = "Lifes = ";
	System::String^ lifes_text = (objCar->return_lifes()).ToString();
	phrase += lifes_text;
	return phrase;
}