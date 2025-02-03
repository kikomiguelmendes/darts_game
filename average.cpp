#include "average.h"

void game_intro_average() {
    cout << endl;
    cout << "This game will measure dart average" << endl;
    cout << "Every 3 throws it will count the average" << endl;
    cout << endl;
}

int dart_throw_translator_average(string dart_throw) {
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
            invalid_dart_throw_average(); 
        }
    } else {
        dart_throw_int = stoi(dart_throw);
    }
    return dart_throw_int * multiplier;
}

void invalid_dart_throw_average() {
    cout << "Invalid dart throw" << endl;
    get_dart_throw();
}

void game_round_average() {
    string dart_throw;
    int round_sum = 0;
    int round_count = 0;
    double overall_average = 0.0; 

    while (true) {
        int total_round = 0; 
        cout << "Enter the 3 darts throws: ";
        for (int i = 0; i < 3; i++) {
            dart_throw = get_dart_throw();
            total_round += dart_throw_translator_average(dart_throw);
        }
        
        cout << "Sum 3 darts: " << total_round << endl;

        round_sum += total_round;
        round_count++;

        overall_average = static_cast<double>(round_sum) / round_count;
        cout << "Overall Average: " << overall_average << endl;
        cout << "Round number  " << round_count << endl;
        cout << endl;
    }
}