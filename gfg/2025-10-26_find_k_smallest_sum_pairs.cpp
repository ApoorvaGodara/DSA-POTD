#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& arr1, vector<int>& arr2, int k) {
    vector<vector<int>> result;
    if (arr1.empty() || arr2.empty() || k == 0) return result;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    for (int i = 0; i < arr1.size() && i < k; i++) {
        minHeap.push({arr1[i] + arr2[0], i, 0});
    }

    while (k-- > 0 && !minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();
        int sum = top[0], i = top[1], j = top[2];
        result.push_back({arr1[i], arr2[j]});

        if (j + 1 < arr2.size()) {
            minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
        }
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 7, 11};
    vector<int> arr2 = {2, 4, 6};
    int k = 3;

    vector<vector<int>> ans = kSmallestPairs(arr1, arr2, k);

    cout << "The " << k << " smallest sum pairs are:\n";
    for (auto &p : ans) {
        cout << "(" << p[0] << ", " << p[1] << ")\n";
    }

    return 0;
}
