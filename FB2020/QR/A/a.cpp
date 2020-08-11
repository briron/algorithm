// Problem A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string readLine(ifstream& filein){
    string line;
    getline(filein, line);
    cout << line << endl;
    return line;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("C:\\Users\\youop_84q7ud7\\playground\\algorithm\\FB2020\\QR\\a.in");
    ofstream fileout("C:\\Users\\youop_84q7ud7\\playground\\algorithm\\FB2020\\QR\\a.out");
    int t = stoi(readLine(filein));
    for(int i = 0 ; i < t; ++i){
        int N = stoi(readLine(filein));
        vector<bool> in(N);
        vector<bool> out(N);
        string ins = readLine(filein);
        string outs = readLine(filein);
        for(int i = 0 ; i < N ; ++i){
            if(ins[i] == 'Y'){
                in[i] = true;
            }
            if(outs[i] == 'Y'){
                out[i] = true;
            }
        }

        vector<vector<bool>> ret(N, vector<bool>(N));
        for(int i = 0 ; i < N ; ++i){
            ret[i][i] = true;
            for(int j = i+1; j < N ; ++j){
                if(out[j-1] && in[j]){
                    ret[i][j] = true;
                }
                else{
                    break;
                }
            }
            for(int j = i-1; j >= 0 ; --j){
                if(out[j+1] && in[j]){
                    ret[i][j] = true;
                }
                else{
                    break;
                }
            }
        }

        fileout << "Case #" << i+1 << ':' << endl; 
        for(int i = 0 ; i < N ; ++i){
            for(int j = 0 ; j < N ; ++j){
                if(ret[i][j]){
                    fileout << "Y";
                }
                else{
                    fileout << "N";
                }
            }
            fileout << endl;
        }

    }

    filein.close();
    fileout.close();

    return 0;
}