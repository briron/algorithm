// Problem B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    unordered_map<int, int> m;
    unordered_set<int> two;
    unordered_set<int> four;
    unordered_set<int> six;
    unordered_set<int> eight;
    for(int i = 0 ; i < N ; ++i){
        int a;
        cin >> a;
        m[a] += 1;
        if(m[a] == 2){
            two.insert(a);
        }
        else if(m[a] == 4){
            four.insert(a);
        }
        else if(m[a] == 6){
            six.insert(a);
        }
        else if(m[a] == 8){
            eight.insert(a);
        }
    }
    int Q;
    cin >> Q;
    for(int i = 0 ; i < Q; ++i){
        char c;
        int a;
        cin >> c >> a;
        if(c == '+'){
            m[a] += 1;
            if(m[a] == 2){
                two.insert(a);
            }
            else if(m[a] == 4){
                four.insert(a);
            }
            else if(m[a] == 6){
                six.insert(a);
            }
            else if(m[a] == 8){
                eight.insert(a);
            }
        }
        else{
            m[a] -= 1;
            if(m[a] == 1){
                two.erase(a);
            }
            else if(m[a] == 3){
                four.erase(a);
            }
            else if(m[a] == 5){
                six.erase(a);
            }
            else if(m[a] == 7){
                eight.erase(a);
            }
        }

        if(eight.size() > 0){
            cout << "YES" << endl;
        }
        else if(six.size() > 0 && two.size() > 1){
            cout << "YES" << endl;
        }
        else if(four.size() > 1){
            cout << "YES" << endl;
        }
        else if(four.size() > 0 && two.size() > 2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}