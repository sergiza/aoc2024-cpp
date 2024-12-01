#include <bits/stdc++.h>
using namespace std;

void e1(vector<string> lines) {

    vector<int> left_side;
    vector<int> right_side;
    for (auto& l : lines) {
        // cout << l << endl;
        istringstream iss(l);
        int left_l, right_l;
        iss >> left_l >> right_l;

        left_side.push_back(left_l);
        right_side.push_back(right_l);
    }

    sort(left_side.begin(), left_side.end());
    sort(right_side.begin(), right_side.end());

    vector<int> distance(left_side.size());
    // transform(left_side.begin(), left_side.end(), right_side.begin(), distance.begin(), plus<int>());    // test
    transform(left_side.begin(), left_side.end(), right_side.begin(), distance.begin(), [](int a, int b){return abs(a - b);} );

    int distance_total = accumulate(distance.begin(), distance.end(), 0);
    cout << "TOTAL DISTANCE: " << distance_total << endl;

    // DEBUGPRINT
    // cout << "\nleft:" << endl;
    // for (auto& n : left_side)
    //     cout << n << ' ';
    // cout << "\nright:" << endl;
    // for (auto& n : right_side)
    //     cout << n << ' ';
    // cout << "\nDISTANCE:" << endl;
    // for (auto& n : distance)
    //     cout << n << ' ';
}

void e2(vector<string> lines) {
    vector<int> left_side;
    vector<int> right_side;
    for (auto& l : lines) {
        istringstream iss(l);
        int left_l, right_l;
        iss >> left_l >> right_l;

        left_side.push_back(left_l);
        right_side.push_back(right_l);
    }

    unordered_map<int, int> repeated;
    for (const int& n : right_side)
      repeated[n]++;

    vector<int> similarity(left_side.size());
    for (size_t i = 0; i < left_side.size(); i++)
        similarity[i] = left_side[i] * repeated[left_side[i]];

    int similarity_score = accumulate(similarity.begin(), similarity.end(), 0);
    cout << "SIMILARITY SCORE: " << similarity_score << endl;

    // DEBUGPRINT
    // cout << "\nsimilarity:" << endl;
    // for (auto& n : similarity)
    //     cout << n << ' ';
}

int main() {
    ifstream file("../input/01");
    string line;
    vector<string> lines;
    while (getline(file, line))
        lines.push_back(line);
    file.close();

    // e1(lines);
    e2(lines);
}
