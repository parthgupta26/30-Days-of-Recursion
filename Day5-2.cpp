#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void printTargetSumSubsets(vector<int> arr, int idx, string subset, int sumOfSubset, int target) {
    if(idx == arr.size()) {
        if(sumOfSubset == target) {
            cout << subset << endl;
        }
        return;
    }
    if(sumOfSubset > target) {
        return;
    }
    printTargetSumSubsets(arr, idx + 1, subset + to_string(arr[idx]) + ", ", sumOfSubset + arr[idx], target);
    printTargetSumSubsets(arr, idx + 1, subset, sumOfSubset, target);
}

int main(){
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;
    printTargetSumSubsets(arr, 0, "", 0, target);
    return 0;
}