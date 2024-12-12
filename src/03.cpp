#include <bits/stdc++.h>
using namespace std;

void e1(string input) {
    cout << input << endl;
}

void e2(string input) {
    cout << input << endl;
}

int main() {
    ifstream file("../input/03sample");
    string input((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    e1(input);
    // e2(lines);
}
