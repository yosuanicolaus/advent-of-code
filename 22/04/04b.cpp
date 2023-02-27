#include <any>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool can_contain_other(int s1, int e1, int s2, int e2) {
    if (s2 <= e1)
        return true;
    else
        return false;
}

int main() {
    ifstream file;
    file.open("./input.txt");
    string line;
    int sum = 0;

    while (getline(file, line)) {
        int dash1 = line.find('-');
        int comma = line.find(',');
        int dash2 = line.find('-', comma);

        int start1 = stoi(line.substr(0, dash1));
        int end1 = stoi(line.substr(dash1 + 1, comma - (dash1 + 1)));
        int start2 = stoi(line.substr(comma + 1, dash2 - (comma + 1)));
        int end2 = stoi(line.substr(dash2 + 1, line.length() - (dash2 + 1)));

        if (start2 < start1) {
            swap(start1, start2);
            swap(end1, end2);
        }

        if (can_contain_other(start1, end1, start2, end2))
            sum++;
    }

    cout << sum << endl;
}
