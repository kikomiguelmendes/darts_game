#ifndef CRIQUET_H
#define CRIQUET_H

#include "game.h"

void game_intro_criquet();
void game_round_criquet(bool player1Turn, int player1_score[], int player2_score[]);
void update_score_criquet(int player_score[], string dart_throw);
void print_score_table(string player1, string player2, int player1_score[], int player2_score[]);
void invalid_dart_throw_criquet(int player_score[]);
int dart_throw_translator_criquet(string dart_throw, int& multiplier, int player_score[]);
void process_dart_throw_criquet(int player_score[]);
bool game_over(int player_score[]);
bool verify_game_over(int player1_score[], int player2_score[]);

#endif