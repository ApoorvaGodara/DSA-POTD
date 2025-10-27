#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) {
    int prevDevices = 0, totalBeams = 0;

    for (string& row : bank) {
        int currDevices = count(row.begin(), row.end(), '1');
        if (currDevices > 0) {
            totalBeams += prevDevices * currDevices;
            prevDevices = currDevices;
        }
    }
    return totalBeams;
}

int main() {
    vector<string> bank1 = {"011001","000000","010100","001000"};
    vector<string> bank2 = {"000","111","000"};

    cout << numberOfBeams(bank1) << endl; // Output: 8
    cout << numberOfBeams(bank2) << endl; // Output: 0

    return 0;
}
