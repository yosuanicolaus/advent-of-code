#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

char get_unique_char(string comp1, string comp2, string comp3) {
    set<char> sc1(begin(comp1), end(comp1));
    set<char> sc2(begin(comp2), end(comp2));
    set<char> sc3(begin(comp3), end(comp3));

    for (char ch : sc1) {
        if (sc2.contains(ch) && sc3.contains(ch)) {
            return ch;
        }
    }
    throw invalid_argument("nothing unique from all 3 strings");
}

int solve(string comp1, string comp2, string comp3) {
    char unique_char = get_unique_char(comp1, comp2, comp3);
    if ((int)unique_char >= 97) {
        // lowercase char - 1-26
        return (int)unique_char - 96;
    } else {
        // uppercase char - 27-52
        return (int)unique_char - 38;
    }
}

int main() {
    ifstream file;
    file.open("./input.txt");
    string line;
    int points = 0;
    int i = 0;
    string lines[3];

    while (getline(file, line)) {
        lines[i] = line;
        i++;
        if (i == 3) {
            points += solve(lines[0], lines[1], lines[2]);
            i = 0;
        }
    }

    cout << points << endl;
    return 0;
}
