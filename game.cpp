#include "game.h"
#include "criquet.h"
#include "average.h"

string player1, player2;

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

string get_dart_throw() {
    string dart_throw;
    cin >> dart_throw;
    if (dart_throw == "exit") {
        exit(0);
    } else {
        return dart_throw;
    }
}

int number_converter(string& dart_throw) {
    int number;
    if (isdigit(dart_throw[1]) && isdigit(dart_throw[2])) {
        number = (dart_throw[1] - '0') * 10 + (dart_throw[2] - '0');
    }
    return number;
}

string dictionary(int number) {
    switch (number) {
        case 0: return " ";
        case 1: return "/";
        case 2: return "X";
        default: return "(X)";
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
            game_intro_criquet();
            bool player1Turn = coin_toss();

            int player1_score[7] = {0};
            int player2_score[7] = {0};

            print_score_table(player1, player2, player1_score, player2_score);
            game_round_criquet(player1Turn, player1_score, player2_score);
        } else if (choice == 'A') {
            game_intro_average();
            game_round_average();
        } else {
            cout << "Invalid input" << endl;
        }
    }
}