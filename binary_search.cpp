#include <bits/stdc++.h>

using namespace std;


// index를 반환한다.
// 자기 자신보다 같거나 큰 값의 index 를 반환한다.
// arr는 sorted 된 상태이고, target은 arr 범위 안의 숫자라고 가정한다.
int binary_search(vector<int>& arr, int target){
    int lo = 0;
    int hi = arr.size() - 1;
    while(lo < hi){
        int mid = (lo+hi) / 2;
        if(arr[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}


int main(){
    vector<int> arr = {1,3,5,7,9,9,13};
    cout << arr[binary_search(arr, 10)] << endl;
    return 0;
}