#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstIndex(vector<int> arr, int idx, int d){
    if(idx == arr.size()) {
        return -1;
    }
    if(arr[idx] == d) {
        return idx;
    }
    else {
        return firstIndex(arr, idx + 1, d);
    }
}

int main(){
    int n, d;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> d;
    cout << firstIndex(arr, 0, d);
    return 0;
}