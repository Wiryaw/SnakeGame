#pragma once

#include "General_Header.h"
class Food {
	private:
		COORD pos;
	public:
		Food();
		void gen_food();
		COORD get_pos();

};
