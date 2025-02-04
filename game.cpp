#include "game.h"
#include "criquet.h"
#include "average.h"

string player1, player2, game_selected;

bool coin_toss() {
    cout << "Coin toss to see who starts" << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    int result = dis(gen);
    if (result == 0) {
        cout << player1 << " starts" << endl;
        return true;
    } else {
        cout << player2 << " starts" << endl;
        return false;
    }
}

string invalid_dart_throw () {
    cout << "Invalid dart throw" << endl;
    cout << "Enter a valid dart throw: ";
    return get_dart_throw();
}

// This is a work in progress
 
/*int dart_throw_translator_average(string dart_throw) {
    int dart_throw_int;
    int multiplier = 1;
    if (isalpha(dart_throw[0])) {
        char letter = toupper(dart_throw[0]);
        string number_part = dart_throw.substr(1); 
        dart_throw_int = stoi(number_part); 

        if (letter == 'D') {
            multiplier = 2;  
        } else if (letter == 'T') {
            multiplier = 3;
        } else {
            string new_dart_throw = invalid_dart_throw(); 
            if (game_selected == "Average") {
                dart_throw_translator_average(new_dart_throw);
            } else {
                update_score_criquet(new_dart_throw);
            }
        }
    } else {
        dart_throw_int = stoi(dart_throw);
    }
    return dart_throw_int * multiplier;
}*/

string get_dart_throw() {
    string dart_throw;
    cin >> dart_throw;
    if (dart_throw == "exit") {
        exit(0);
    } else {
        return dart_throw;
    }
}

void game_choice() {
    char choice;
    bool incorrect_input = true;

    while (incorrect_input) {
        cout << "Enter 'C' for Criquet or 'A' for Average: ";
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'C') {
            game_selected = "Criquet";
            game_intro_criquet();
            bool player1Turn = coin_toss();

            int player1_score[7] = {0};
            int player2_score[7] = {0};

            print_score_table(player1, player2, player1_score, player2_score);
            game_round_criquet(player1Turn, player1_score, player2_score);
        } else if (choice == 'A') {
            game_selected = "Average";
            game_intro_average();
            game_round_average();
        } else {
            cout << "Invalid input" << endl;
        }
    }
}