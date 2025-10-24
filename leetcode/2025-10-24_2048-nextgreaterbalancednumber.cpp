#include <bits/stdc++.h>
using namespace std;

bool isBalanced(int num) {
    string s = to_string(num);
    vector<int> freq(10, 0);

    for (char c : s) {
        if (c == '0') return false;    // zero can't be valid
        freq[c - '0']++;
    }

    for (char c : s) {
        int d = c - '0';
        if (freq[d] != d) return false;
    }
    return true;
}

int nextBeautifulNumber(int n) {
    int x = n + 1;
    while (true) {
        if (isBalanced(x)) return x;
        x++;
    }
}

int main() {
    int n;
    cin >> n;
    cout << nextBeautifulNumber(n) << endl;
}
