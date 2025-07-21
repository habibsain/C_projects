//bowling_gamme_test.c

#include "bowling_game.h"

#include <assert.h>
#include <stdbool.h>

//n: number of tries
//pins: number of pins fell 
static void roll_many(int n, int pins)
{
    for (int i = 0; i < n; i++)
    {
        bowling_game_roll(pins);
    }

}


//Test the scenario where every try is a gutter ball
//Gutter ball: Ball that doesn't hit any pins
static void test_gutter_game()
{
    //start the game
    bowling_game_init();

    //Total 20 tries with no falling pins everytime
    roll_many(20, 0);

    //test name string for ease in debugging
    assert(bowling_game_score() == 0 && "test_gutter_game()");
}

//Test the scenario where 1 ball falls at every try
static void test_all_ones()
{
    //Total 20 tries with one falling pin everytime
    roll_many(20, 1);

    assert(bowling_game_score() == 20 && "test_all_ones()");
}

static void test_one_spare()
{
    bowling_game_init();
    bowling_game_roll(5);
    bowling_game_roll(5);
    //spare: 10 fell in 1st frame
    bowling_game_roll(3);
    roll_many(17,  0);

    //first frame score = 13
    //2nd frame score = 13 + 3
    //Total score = 16
    assert(bowling_game_score() == 16 && "test_one_spare()");
}

int main() 
{
    test_gutter_game();
    test_all_ones();
    test_one_spare();
    return 0;
}