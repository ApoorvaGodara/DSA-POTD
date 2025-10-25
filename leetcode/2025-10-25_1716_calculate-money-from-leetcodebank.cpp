#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticProgression(int leading, int last, int terms){
        return (leading + last) * terms / 2;
    }

    int totalMoney(int n) {
        auto [q, r] = div(n, 7);
        return arithmeticProgression(28, 28 + (q - 1) * 7, q) 
             + arithmeticProgression(q + 1, q + r, r);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    cout << "Total money saved in " << n << " days = " 
         << sol.totalMoney(n) << endl;

    return 0;
}
