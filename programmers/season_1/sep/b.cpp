#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<vector<bool>> visited(n, vector<bool>(n));
    int total = n * (n+1) / 2;
    vector<int> answer(total);
    int count = 1;
    int dir = 0;
    int r = 0 ;
    int c = 0 ;
    while(count <= total){
        if(dir == 0){
            while(r < n && visited[r][c] == false){
                visited[r][c] = true;
                answer[(r+1) * r / 2 + c] = count;
                ++r;
                ++count;
            }
            --r;
            ++c;
        }
        else if(dir == 1){
            while(c < n && visited[r][c] == false){
                visited[r][c] = true;
                answer[(r+1) * r / 2 + c] = count;
                ++c;
                ++count;                
            }
            c -= 2;
            --r;
        }
        else{
            while(r >= 0 && c >= 0 && visited[r][c] == false){
                visited[r][c] = true;
                answer[(r+1) * r / 2 + c] = count;
                --r;
                --c;
                ++count;                
            }
            r += 2;
            ++c;
        }
        dir += 1;
        dir %= 3;
    }
    return answer;
}