#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        double originalSum = 0;
        for (double num : arr) originalSum += num;
        double target = originalSum / 2;
        double currentSum = originalSum;

        priority_queue<double> pq(arr.begin(), arr.end());
        int steps = 0;

        while (currentSum > target) {
            double largest = pq.top();
            pq.pop();
            double halved = largest / 2.0;
            currentSum -= (largest - halved);  // reduction from sum
            pq.push(halved);
            steps++;
        }

        return steps;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.minOperations(arr);

    cout << "Minimum operations: " << result << endl;
    return 0;
}