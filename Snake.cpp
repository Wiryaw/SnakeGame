
#include "Snake.h"
#include "General_Header.h"

// Calling snake class with the method Snake::Snake along with constructor
Snake::Snake(COORD head, int vel) {
	// Position's and Velocity's Pointer
	this -> pos = head;
	this -> vel = vel;

	// Length size
	len = 1;
	
	//Direction for snake
	direction = 'n'; // no movement

	tail.push_back(pos);


}

// Method from class for chaging direction
void Snake::change_dir(char dir) {
	this->direction = dir; 
}

vector<COORD> Snake::get_tail() {
	return tail;
}
// Method to move the snake by going up, down, left, right
void Snake::move_snake() {
	switch (direction) {
		case 'u':
			pos.Y -= vel;
			break;
		case 'd':
			pos.Y += vel;
			break;
		case 'l':
			pos.X -= vel;
			break;
		case 'r':
			pos.X += vel;
			break;
	}
	tail.push_back(pos);
	if (tail.size() > len) tail.erase(tail.begin());

}

// Get Method for position
COORD Snake::get_pos() {
	return pos;
}


// Get method for eaten and set condition for food positioning
bool Snake::eaten(COORD food_pos) {
	if (food_pos.X == pos.X && food_pos.Y == pos.Y) {
		return true;
	}
	else {
		return false;
	}
}

// Growing / increasing the body of snake
void Snake::grow() {
	len+= 1;
}

// if it hit the wall, collide
bool Snake::collided() {
	if (pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2) {
		return true;
	}
	for (int i = 0; i < len - 1; i++) {
		if (pos.X == tail[i].X && pos.Y == tail[i].Y) {
			return true;
		}
	}
	return false;
}