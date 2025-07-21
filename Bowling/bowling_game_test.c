//bowling_gamme_test.c

#include "bowling_game.h"

#include <assert.h>
#include <stdbool.h>


//Test the scenario where every try is a gutter ball
//Gutter ball: Ball that doesn't hit any pins
static void test_gutter_game()
{
    //start the game
    bowling_game_init();

    //loop over all 20 tries that forms 10 frames
    //roll the ball in each try
    for (int i = 0; i < 20; i++)
    {
        bowling_game_roll(0);
    }
    //
    assert(bowling_game_score() == 0 && "test_gutter_game()");
}

int main() 
{
    test_gutter_game();
    return 0;
}