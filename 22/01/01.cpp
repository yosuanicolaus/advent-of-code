#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream input_file;
    input_file.open("./input.txt");
    string line;
    int highest = 0;
    int point = 0;

    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            if (line == "") {
                if (highest < point)
                    highest = point;
                point = 0;
            } else
                point += stoi(line);
        }
        input_file.close();
        if (highest < point)
            highest = point;
    } else {
        cout << "unable to get file\n";
    }

    cout << highest << endl;
    return 0;
}
