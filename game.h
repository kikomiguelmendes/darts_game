#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

extern string player1, player2, game_selected;

void game_choice();
bool coin_toss();
string invalid_dart_throw ();
string get_dart_throw();

#endif