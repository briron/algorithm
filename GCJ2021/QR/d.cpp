//  g++ -std=c++17 d.cpp -o exe && ./exe && rm -rf exe

#include <bits/stdc++.h>

using namespace std;

void ternary(vector<int>& arr, int inserted, int start, int end) {
    if(start == end) {
        arr.insert(arr.begin() + start, inserted);
        return;
    }
    
    int left = (start * 2 + end) / 3;
    int right = (start + end * 2) / 3;
    
    if(left == right) {
        if(left != 0) {
            left -= 1;
        }
        else {
            right += 1;
        }
    }
    
    cout << arr[left] << ' ' << arr[right] << ' ' << inserted << endl;
    
    int judge;
    cin >> judge;
    
    if(judge == arr[left]) {
        ternary(arr, inserted, start, left);
    }
    else if(judge == arr[right]) {
        ternary(arr, inserted, right+1, end);
    }
    else {
        ternary(arr, inserted, left+1, right);
    }
    return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, Q;
    cin >> T >> N >> Q;
    for(int t = 1 ; t <= T; ++t) {
        vector<int> arr = {1, 2};
        for(int i = 3; i <= N; ++i) {
            ternary(arr, i, 0, (int)arr.size());
        }
        for(int i = 0 ; i < arr.size(); ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        int judge;
        cin >> judge;
        if(judge == -1) {
            exit(0);
        }
    }
    return 0;
}
