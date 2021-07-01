#include "Food.h"
#include "General_Header.h"

// Calling gen_food
Food::Food() {
	gen_food();
}

// Generate random food
void Food::gen_food() {
	pos.X = rand() % (WIDTH - 3)  + 1;
	pos.Y = rand() % (HEIGHT - 3) + 1;
}

COORD Food::get_pos() {
	return pos;
}