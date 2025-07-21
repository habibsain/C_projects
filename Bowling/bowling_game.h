//bowling_game.h

#ifndef __BOWLING__
#define __BOWLING__

#include <stdbool.h>

//start the game
void bowling_game_init();

//roll the ball 
//pins: number of pins fell
void bowling_game_roll(int pins);

//calculate score
//return: score
int bowling_game_score();

#endif