//bowling_game.c

#include "bowling_game.h"

#define MAX_ROLLS 21

int rolls[MAX_ROLLS];//stores each try pin number
int current_roll;//flag 

void bowling_game_init()
{
	for (int i = 0; i < MAX_ROLLS; i++)
		rolls[i] = 0;
	
	current_roll = 0;
}

void bowling_game_roll(int pins)
{
	rolls[current_roll] = pins;
	current_roll++; 
}

int bowling_game_score()
{
	int score = 0;
	int i = 0;
	
	//sum over all
	for (int frame = 0; frame < 10; frame++)
	{
		int frame_total = rolls[i] + rolls[i+1];
		score += frame_total;

		if (frame_total == 10 && (i + 2) < 20)
		{
			score += rolls[i + 2];
		}
		i += 2;
		
	}

	return score;
}
