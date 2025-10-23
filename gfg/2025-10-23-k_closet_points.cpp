#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max-Heap storing {distance, index}
    priority_queue<pair<int,int>> maxHeap;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x*x + y*y;

        maxHeap.push({dist, i});

        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }
    return result; // order doesn't matter
}

int main() {
    int k = 2;
    vector<vector<int>> points = {{1,3}, {-2,2}, {5,8}, {0,1}};
    vector<vector<int>> ans = kClosest(points, k);

    for (auto &p : ans) {
        cout << "[" << p[0] << ", " << p[1] << "] ";
    }
    return 0;
}
