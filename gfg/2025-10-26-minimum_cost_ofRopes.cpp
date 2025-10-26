#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<int>& arr) {
    if (arr.size() <= 1) return 0;
    
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());
    long long totalCost = 0;
    
    while (minHeap.size() > 1) {
        long long first = minHeap.top(); minHeap.pop();
        long long second = minHeap.top(); minHeap.pop();
        
        long long cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }
    return totalCost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << "Minimum Cost to connect ropes: " << minCost(arr) << endl;
    return 0;
}
