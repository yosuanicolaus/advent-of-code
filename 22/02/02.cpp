#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int match[3][3] = {
    {0, 1, -1},
    {-1, 0, 1},
    {1, -1, 0},
};

int calculate_score(char opp, char you) {
    int score = 0;
    // add based on what you play
    score += (int)you - 87;
    // check who win -> -1 lose, 0 draw, 1 win
    int opp_num = (int)opp - 65;
    int you_num = (int)you - 88;
    int result = match[opp_num][you_num];

    // add based on result
    if (result == 1) {
        score += 6;
    } else if (result == 0) {
        score += 3;
    }
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
