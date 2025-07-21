//bowling_game.c

#include "bowling_game.h"

#define MAX_ROLLS 21

static int rolls[MAX_ROLLS];//stores each try pin number
static int current_roll;//flag 

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

static bool is_spare(int frame_index)
{
	return rolls[frame_index] + rolls[frame_index+1] == 10;
}

int bowling_game_score()
{
	int score = 0;
	int frame_index = 0;
	
	//sum over all
	for (int frame = 0; frame < 10; frame++)
	{
		int frame_total = rolls[frame_index] + rolls[frame_index+1];
		score += frame_total;

		if ( is_spare(frame_index) && (frame_index + 2) < 20)
		{
			score += rolls[frame_index + 2];
		}
		frame_index += 2;
		
	}

	return score;
}
