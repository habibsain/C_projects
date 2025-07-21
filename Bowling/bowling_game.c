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
	
	//sum over all
	for (int i = 0; i < MAX_ROLLS; i++)
	{
		score += rolls[i];
		//check for spare
		if (i%2 == 0 && (rolls[i] + rolls[i+1]) == 10 )
		{
			if (i + 2 < MAX_ROLLS)
			{
				score += rolls[i+2];
			}
		}
	}

	return score;
}
