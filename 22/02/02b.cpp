#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int what_to_play[3][3] = {
    {2, 0, 1},
    {0, 1, 2},
    {1, 2, 0},
};

int calculate_score(char opp, char desired) {
    // initialize score with desired result -> 0:0, 1:3, 2:6
    int desired_score = (int)desired - 88;
    int score = desired_score * 3;
    // get what to play based on the matrix
    int opp_play = (int)opp - 65;
    int your_play = what_to_play[opp_play][desired_score];
    score += your_play + 1;
    return score;
}

int main() {
    ifstream file;
    file.open("./input.txt");
    string line;
    int total_score = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "")
                continue;
            char opp_play = line[0];
            char you_play = line[2];
            total_score += calculate_score(opp_play, you_play);
        }
        file.close();
    } else
        cout << "file not opened" << endl;

    cout << total_score << endl;
}
