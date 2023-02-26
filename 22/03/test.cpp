#include <fstream>
#include <iostream>
#include <set>
#include <stdexcept>
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

void test() {
    cout << (int)'a' - 96 << " ";
    cout << (int)'z' - 96 << " ";
    cout << (int)'A' - 38 << " ";
    cout << (int)'Z' - 38 << endl;
}

int main() { test(); }
