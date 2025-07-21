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

    //Total 20 tries over 10 frames
    for (int i = 0; i < 20; i++)
    {
        //zero ball fell on the roll
        bowling_game_roll(0);
    }
    //test name string for ease in debugging
    assert(bowling_game_score() == 0 && "test_gutter_game()");
}

//Test the scenario where 1 ball falls at every try
static void test_all_ones()
{
    bowling_game_init();
    for (int i = 0; i < 20; i++)
    {
        bowling_game_roll(1);
    }

    assert(bowling_game_score() == 20 && "test_all_ones()");
}

int main() 
{
    test_gutter_game();
    test_all_ones();
    return 0;
}