#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll base, ll exp){
    ll ret = 1;
    while(exp > 0){
        if(exp % 2 == 0){
            base *= base;
            exp /= 2;
        }
        else{
            ret *= base;
            exp -= 1;
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << power(2, 50)<< endl;

    return 0;
}