#pragma once

#include <vector>
#include "General_Header.h"


class Snake {
	private:
		COORD pos; // Position
		int len; // Length
		int vel; // Velocity
		char direction;
		vector<COORD>  tail;
		
	public:
		// Snake contructor 
		Snake(COORD pos, int vel);

		// Create Empty Direction Method
		void change_dir(char dir);

		// Create Empty Moving snake Method
		void move_snake();

		// Create Get Method
		COORD get_pos();
		// Create Boolean for Food Positioning
		bool eaten(COORD food_pos);

		void grow();

		bool collided();

		vector<COORD> get_tail();
};		
