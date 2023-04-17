#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


/* Sets the boundary; also declares variables for
 the x and y axis of the fruit and declares the flag
 flag is used for movement.
*/
int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Generates the fruit.
void setup() {
	gameover = 0;

	// Stores the height and the width
	x = height / 2;
	y = width / 2;
	// Using rand() % 20 so it generates within boundary
	label1:
	fruitx = rand() % 20;
		if (fruitx == 0)
			goto label1;
	label2:
		fruity = rand() % 20;
		if (fruity == 0)
			goto label2;
	score = 0;
}

//Draws the boundary; I definitely copied this as I am stupid.
void draw() {
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx
					&& j == fruity)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}

	// Show the score when game is over
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit.");
}

//Takes user input and sets for up for logic
void input() {
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

// How the game is actually working
void logic() {
	// Movement
	_sleep(50);
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}
	// If the game is over
	if (x < 0 || x > height
		|| y < 0 || y > width) {
		gameover = 1;
	}

	// Updates score if you eat the fruit
	if (x == fruitx && y == fruity) {
	label3:
		fruitx = rand() % 20;
		if (fruitx == 0)
			goto label3;

	// After eating fruit make new fruit.
	label4:
		fruity = rand() % 20;
		if (fruity == 0)
			goto label4;
		score += 10;
	}
}

void main() {

	//Generate Fruit
	setup();

	//While game is running (gameplay loop).
	while (!gameover) {
		draw();
		input();
		logic();
	}
}
