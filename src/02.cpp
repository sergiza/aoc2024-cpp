#include <bits/stdc++.h>
using namespace std;

bool is_increasing(vector<int> report) {
    int current = report[0];
    int next = report[1];

    if (current < next)
        return true;
    if (current > next)
        return false;
    vector<int> nextPair(report.begin() + 1, report.end());
    return is_increasing(nextPair);
}

int is_safe(vector<int> report, int dampener){
    bool increasing = is_increasing(report);
    int max_diff = 3;
    int report_size = static_cast<int>(report.size());

    for (int i = 0; i < (report_size - 1); i++) {
        int current = report[i];
        int next = report[i+1];

        if (increasing) {
            if ((current < next) && (next - current <= max_diff))
                continue;
            else {
                if (dampener > 0) {
                    vector<int> report_minus_current = report;
                    vector<int> report_minus_next = report;
                    report_minus_current.erase(report_minus_current.begin() + i);
                    report_minus_next.erase(report_minus_next.begin() + i + 1);

                    if (is_safe(report_minus_current, dampener-1))          // Try without current level
                        return 1;
                    else return (is_safe(report_minus_next, dampener-1));   // Try without next level
                }
            }
        }
        if (!increasing) {
            if ((current > next) && (current - next <= max_diff))
                continue;
            else {
                if (dampener > 0) {
                    vector<int> report_minus_current = report;
                    vector<int> report_minus_next = report;
                    report_minus_current.erase(report_minus_current.begin() + i);
                    report_minus_next.erase(report_minus_next.begin() + i + 1);

                    if (is_safe(report_minus_current, dampener-1))          // Try without current level
                        return 1;
                    else return (is_safe(report_minus_next, dampener-1));   // Try without next level
                }
            }
        }
        if (dampener <= 0) {
            return 0;
            break;
        }
    }
    return 1;
}

void e(vector<string> lines, int tolerance) {
    vector<int> safe(lines.size());

    int lines_size = static_cast<int>(lines.size());
    for (int i = 0; i < lines_size; i++) {
        vector<int> report;
        istringstream iss(lines[i]);
        int temp;
        while (iss >> temp)
            report.push_back(temp);

        safe[i] = is_safe(report, tolerance);
    }
    cout << accumulate(safe.begin(), safe.end(), 0) << " reports are SAFE\n" << endl;
}

int main() {
    ifstream file("../input/02");
    string line;
    vector<string> lines;
    while (getline(file, line))
        lines.push_back(line);
    file.close();

    int tolerance = 1;
    e(lines, tolerance);
}
