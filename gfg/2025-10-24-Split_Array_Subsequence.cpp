#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& arr, int k) {
    unordered_map<int, int> freq, need;

    for (int x : arr) freq[x]++;

    for (int x : arr) {
        if (freq[x] == 0) continue;

        if (need[x] > 0) {
            // extend existing subsequence
            need[x]--;
            need[x + 1]++;
            freq[x]--;
        } 
        else {
            // start a new subsequence of length >= k
            for (int j = 0; j < k; j++) {
                if (freq[x + j] <= 0) return false;
            }
            for (int j = 0; j < k; j++) {
                freq[x + j]--;
            }
            need[x + k]++; 
        }
    }

    return true;
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 4, 5};
    int k = 2;
    cout << (canSplit(arr, k) ? "true" : "false");
}
