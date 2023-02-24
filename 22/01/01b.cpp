#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int get_lowest_index(int arr[3]) {
    if (arr[0] <= arr[1] && arr[0] <= arr[2]) {
        return 0;
    } else if (arr[1] <= arr[0] && arr[1] <= arr[2]) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    ifstream input_file;
    input_file.open("./input.txt");
    string line;
    int highest[] = {0, 0, 0};
    int point = 0;

    if (input_file.is_open()) {
        while (getline(input_file, line)) {
            if (line == "") {
                int lowest_idx = get_lowest_index(highest);
                if (highest[lowest_idx] < point)
                    highest[lowest_idx] = point;
                point = 0;
            } else
                point += stoi(line);
        }
        input_file.close();
        int lowest_idx = get_lowest_index(highest);
        if (highest[lowest_idx] < point)
            highest[lowest_idx] = point;
    } else {
        cout << "unable to get file\n";
    }

    cout << highest[0] << " " << highest[1] << " " << highest[2] << endl;
    cout << highest[0] + highest[1] + highest[2] << endl;
    return 0;
}
