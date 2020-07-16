#include <bits/stdc++.h>

using namespace std;

// 정렬되지 않은 배열에서 k번쨰 수를 구하는 문제 O(N) 안에
// quick select 이지만, 피벗이 잘못 선택되는 경우 O(N^2) 로 실행된다
// 이를 방지하기 위해서는 median of medians 를 알 필요가 있는데..

int partition(vector<int>& arr, int l, int r){
    int pos = l;
    int x = arr[r];
    for(int i = l ; i < r ; ++i){
        if(arr[i] < x){
            swap(arr[i], arr[pos]);
            ++pos;
        }
    }
    swap(arr[r], arr[pos]);
    return pos;
}

int kthsmallest(vector<int>& arr, int l, int r, int k){
    int pos = partition(arr, l, r);
    if(pos == k-1) return arr[pos];
    if(pos > k-1) return kthsmallest(arr, l, pos-1, k);
    return kthsmallest(arr, pos+1, r, k);
}


int main(){
    vector<int> arr = {4,3,2,1,0};
    cout << kthsmallest(arr, 0, 4, 2) << endl;
}




int partition(vector<int>& arr, int l, int r){
    int x = arr[r];
    int pos = l;
    for(int i = l ; i < r; ++i){
        if(arr[i] < x){
            swap(arr[i], arr[pos]);
            ++pos;
        }
    }
    swap(arr[r], arr[pos]);
    return pos;
}

int kthsmallest(vector<int>& arr, int l, int r, int k){
    int pos = partition(arr, l, r);
    if(pos == k-1) return arr[pos];
    else if(pos > k-1) return kthsmallest(arr, l, pos-1, k);
    return kthsmallest(arr, pos+1, r, k);
}

int partition(vector<int>& arr, int l, int r){
    int pos = l;
    int x = arr[r];
    for(int i = l ; i < r; ++i){
        if(arr[i] < x){
            swap(arr[pos], arr[i]);
            pos += 1;
        }
    }
    swap(arr[pos], arr[r]);
    return pos;
}

int kth(vector<int>& arr, int k, int l, int r){
    int pos = partition(arr, l, r);
    if(pos == k-1){
        return arr[pos];
    }
    if(pos > k-1){
        return kth(arr, k, l, pos-1);
    }
    return kth(arr, k, pos+1, r);
}