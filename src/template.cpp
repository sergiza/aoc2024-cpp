#include <bits/stdc++.h>
using namespace std;

void e1(vector<string> lines) {
}

void e2(vector<string> lines) {
}

int main() {
    ifstream file("../input/01");
    string line;
    vector<string> lines;
    while (getline(file, line))
        lines.push_back(line);
    file.close();

    e1(lines);
    // e2(lines);
}
