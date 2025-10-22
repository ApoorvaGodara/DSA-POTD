#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;

        int idx = 0;
        for (auto &i : arr) {
            minH.push(i);
            if (minH.size() > k) {
                arr[idx++] = minH.top();
                minH.pop();
            }
        }
        while (!minH.empty()) {
            arr[idx++] = minH.top();
            minH.pop();
        }
    }
};

int main() {
    Solution sol;

    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.nearlySorted(arr, k);

    cout << "Sorted array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}