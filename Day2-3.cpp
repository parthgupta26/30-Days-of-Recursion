#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = -1;

int lastIndex(vector<int> arr, int idx, int d){
    if(idx == arr.size()) {
        return ans;
    }
    if(arr[idx] == d) {
        ans = idx;
    }
    return lastIndex(arr, idx + 1, d);
}

int main(){
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> d;
    cout << lastIndex(arr, 0, d);
    return 0;
}