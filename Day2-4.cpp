#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr) {
    for(int ele : arr) {
        cout << ele << endl;
    }
}

void allIndex(vector<int> arr, int idx, int d, vector<int> &ans){
    if(idx == arr.size()) {
        return;
    }
    if(arr[idx] == d) {
        ans.push_back(idx);
    }
    allIndex(arr, idx + 1, d, ans);
}

int main(){
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> d;
    vector<int> ans;
    allIndex(arr, 0, d, ans);
    display(ans);
    return 0;
}