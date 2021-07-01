
#include "Snake.h"
#include "Food.h"
#include "General_Header.h"


// Create object for snake
Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);

// Create object for food
Food food;

int score;


void draw() {
    // Calling method as an object
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
   
    vector<COORD> snake_tail = snake.get_tail();

    cout << "\t\tSCORE : " << score << "\n\n";

    for (int i = 0; i < HEIGHT; i++) {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++) {
            if (i == 0 || i == HEIGHT - 1) {
                cout << '#';
            }

            else if (i == snake_pos.Y && j == snake_pos.X) {

                cout << "O"; // snake head
             
            }

            else if (i == food_pos.Y && j == food_pos.X) {
                cout << '*';
            }

            else {
                bool tail = false;
                for (int k = 0; k < snake_tail.size() - 1; k++) {
                    if (i == snake_tail[k].Y && j == snake_tail[k].X) {
                        cout << 'o';
                        tail = true;
                        break;
                    }
                }
                if (!tail) {
                    cout << " ";
                }
            }

        }
        cout << "#\n";
    }
}
        


int main() {
    srand(time(NULL));
    bool game_over = false;
    score = 0;
    while (!game_over) {



        draw();


        // Moving key for snake
        if (_kbhit()) {
            switch (_getch()) {
            case UP:
                snake.change_dir('u');
                break;
            case LEFT:
                snake.change_dir('l');
                break;
            case DOWN:
                snake.change_dir('d');
                break;
            case RIGHT:
                snake.change_dir('r');
                break;
            }
        }
        

        //if collide, game over
        if (snake.collided()) game_over = true;

        // Condition for: if snake eat then increase its body
        if (snake.eaten(food.get_pos())) {
            food.gen_food();
            snake.grow();
            score = score + 1;
        }

        // Snake movement
        snake.move_snake();


        // Refresh FPS 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }
    cout << "Game Over\n";
}

