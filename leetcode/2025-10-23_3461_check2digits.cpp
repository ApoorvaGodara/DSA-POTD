#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s) {
    int n = s.size();
    if (n == 2) return s[0] == s[1];

    vector<long long> pascal(n, 0);
    pascal[0] = 1;

    // Build Pascal row (n-2) using iterative formula for C(n-2, i)
    for (int i = 1; i <= n - 2; i++) {
        // C(k, i) = C(k, i-1) * (k - (i-1)) / i
        pascal[i] = (pascal[i - 1] * (n - 1 - i)) / i;
        pascal[i] %= 10; // only mod 10 is needed
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n - 1; i++) {
        int coef = pascal[i] % 10;
        d1 = (d1 + coef * (s[i] - '0')) % 10;
        d2 = (d2 + coef * (s[i + 1] - '0')) % 10;
    }

    return d1 == d2;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (hasSameDigits(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
