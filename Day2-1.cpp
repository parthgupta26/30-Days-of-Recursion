#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxe = INT_MIN;

void maxElementInArray(vector<int> arr, int idx){
    if(idx == arr.size()) {
        return;
    }
    maxe = max(maxe, arr[idx]);
    maxElementInArray(arr, idx + 1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    maxElementInArray(arr, 0);
    cout << maxe;
    return 0;
}