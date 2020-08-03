#include <bits/stdc++.h>

using namespace std;


// 중복이 없는 set에서 A보다 작거나 같은 값을 찾는 경우, 없으면 MIN_INT를 반환
int searchLowerTarget(set<int>& s, int target){
    if(s.size() == 0) return MIN_INT;
    auto it = s.lower_bound(target);
    if(it != s.end() && *it == target) return target;
    if(it == s.begin()) return MIN_INT;
    return *prev(it);
}

int searchUpperTarget(set<int>& s, int target){
    if(s.size() == 0) return MAX_INT;
    auto it = s.lower_bound(target);
    if(it == s.end()) return MAX_INT;
    return *it;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}