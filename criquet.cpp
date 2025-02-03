#include "criquet.h"

void game_intro_criquet() {
    cout << endl;
    cout << "This is a darts game called Criquet" << endl;
    cout << "The game is played with 2 players" << endl;
    cout << "Each round both players throw 3 darts" << endl;
    cout << "The player who scores 3 times on each number from 20 to 15 and bull wins" << endl;
    cout << endl;
    cout << "Enter the name of player 1: ";
    cin >> player1;
    cout << "Enter the name of player 2: ";
    cin >> player2;
    cout << endl;
}

void update_score_criquet(int player_score[], string dart_throw) {
    int multiplier = 1;
    int dart_throw_int = dart_throw_translator_criquet(dart_throw, multiplier, player_score);
    
    if (dart_throw_int <= 20 && dart_throw_int >= 15) {
        player_score[20 - dart_throw_int] += multiplier;
    } else if (dart_throw_int == 25) {
        if (multiplier == 3) {
            invalid_dart_throw_criquet(player_score);
        } else {
            player_score[6] += multiplier;
        }
    } else if (dart_throw_int == 0) {
        return;
    } else {
        invalid_dart_throw_criquet(player_score);
    }
}

void invalid_dart_throw_criquet(int player_score[]) {
    cout << "Invalid dart throw" << endl;
    process_dart_throw_criquet(player_score);
}

bool game_over(int player_score[]) {
    int counter = 0;
    for (int i = 0; i < 7; ++i) {
        if (player_score[i] == 3) {
            counter++;
        }
    }
    return counter == 7;
}

bool verify_game_over(int player1_score[], int player2_score[]) {
    return game_over(player1_score) || game_over(player2_score);
}

void process_dart_throw_criquet (int player_score[]) {
    string dart_throw = get_dart_throw();
    update_score_criquet(player_score, dart_throw);
}

void print_score_table(string player1, string player2, int player1_score[], int player2_score[]) {
    string scores[7] = {"20", "19", "18", "17", "16", "15", "bull"};

    cout << setw(20) << "Score Table" << endl;
    cout << endl;
    cout << setw(10) << player1 << setw(20) << player2 << endl;

    for (int i = 0; i < 7; ++i) {
        cout << setw(10) << dictionary(player1_score[i]) << setw(10) << scores[i] << setw(10) << dictionary(player2_score[i]) << endl;
    }
    cout << endl;
}

int dart_throw_translator_criquet(string dart_throw, int& multiplier, int player_score[]) {
    int dart_throw_int;
    if (dart_throw.size() <= 2) {
        dart_throw_int = stoi(dart_throw);
    }
    else if (dart_throw.size() == 3) {
        int letter = toupper(dart_throw[0]);
        if (letter == 'D') {
            dart_throw_int = number_converter(dart_throw);
            multiplier = 2;
        } else if (letter == 'T') {
            dart_throw_int = number_converter(dart_throw);
            multiplier = 3;
        } else {
            invalid_dart_throw_criquet(player_score);
        }
    } else {
        invalid_dart_throw_criquet(player_score);
    }
    return dart_throw_int;
    
}

void game_round_criquet(bool player1Turn, int player1_score[], int player2_score[]) {
    while (true) {
        cout << "Enter the 3 darts throws: ";
        for (int i = 0; i < 3; i++) {
            if (player1Turn) {
                process_dart_throw_criquet(player1_score);
            } else {
                process_dart_throw_criquet(player2_score);
            }
            if (verify_game_over(player1_score, player2_score)) {
                print_score_table(player1, player2, player1_score, player2_score);
                cout << "Game over" << endl;
                exit(0);
            }
        }
        print_score_table(player1, player2, player1_score, player2_score);
        if (player1Turn) {
            cout << player2 << " turn!" << endl;
        } else {
            cout << player1 << " turn!" << endl;
        }
        player1Turn = !player1Turn;
    }   
}