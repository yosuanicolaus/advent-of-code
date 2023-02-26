#include <fstream>
#include <iostream>
#include <set>
#include <string>

using namespace std;

char get_unique_char(string comp1, string comp2) {
    set<char> sc1;
    set<char> sc2;
    for (int i = 0; i < comp1.length(); i++) {
        sc1.insert(comp1[i]);
        sc2.insert(comp2[i]);
    }
    for (char ch : sc1) {
        if (sc2.contains(ch)) {
            return ch;
        }
    }
    throw invalid_argument("nothing unique from comp1&2");
}

int solve(string comp1, string comp2) {
    char unique_char = get_unique_char(comp1, comp2);
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

    while (getline(file, line)) {
        int mid = line.length() / 2;
        string comp1 = line.substr(0, mid);
        string comp2 = line.substr(mid, mid);
        points += solve(comp1, comp2);
    }

    cout << points << endl;
    return 0;
}
