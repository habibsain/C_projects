#ifndef __BOWLING__
#define __BOWLING__


//Trying to use memory allocating wrapper function

//start the game
void bowling_game_init();

//roll the ball 
//with remaining pins number yet to fall
void bowling_game_roll(int pins);

//calculate score
int bowling_game_score();

#endif