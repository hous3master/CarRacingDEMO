#include "Obstacle.h"
Obstacle::Obstacle() {}
Obstacle::Obstacle(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 1, 6, 0, 0) {
	dx = 0;
	dy = 40;
}
Obstacle::~Obstacle() {}
void Obstacle::new_type(int new_data) { type = new_data; }
int Obstacle::return_type() { return type; }
void Obstacle::Move(Graphics^ g) {
	if (y + dy + h > g->VisibleClipBounds.Height) {
		dy = 0;
		flag = true;
	}
	y += dy;
}
void Obstacle::Draw_from_image(Graphics^ g, Bitmap^ bmp) {
	current_column = type;
	//Giving the entity the same width and height as the image shown
	w = bmp->Width / sprite_columns;
	h = bmp->Height / sprite_rows;
	Rectangle portion = Rectangle(current_column * w, current_row * h, w, h);
	//Printing
	g->DrawImage(bmp, x, y, portion, GraphicsUnit::Pixel);
}
