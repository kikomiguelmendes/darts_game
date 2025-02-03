#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

extern string player1, player2;

void game_choice();
bool coin_toss();
string dictionary(int number);
string get_dart_throw();
int number_converter(string& dart_throw);

#endif