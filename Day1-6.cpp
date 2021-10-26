#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr, int idx){
    if(idx == arr.size()) {
        return;
    }
    cout << arr[idx] << endl;
    display(arr, idx + 1);
}

void displayReverse(vector<int> arr, int idx){
    if(idx == arr.size()) {
        return;
    }
    displayReverse(arr, idx + 1);
    cout << arr[idx] << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    display(arr, 0);
    cout << endl;
    displayReverse(arr, 0);
    return 0;
}