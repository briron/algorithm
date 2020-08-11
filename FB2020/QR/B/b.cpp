// Problem B

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
    ifstream filein("..\\FB2020\\QR\\B\\b.in");
    ofstream fileout("..\\FB2020\\QR\\B\\b.out");
    int t = stoi(readLine(filein));
    for(int i = 0 ; i < t; ++i){
        int N = stoi(readLine(filein));
        string stones = readLine(filein);
        int a = 0;
        for(int i = 0 ; i < stones.size(); ++i){
            if(stones[i] == 'A'){
                ++a;
            }
        }
        fileout << "Case #" << i+1 << ": "; 
        if(a * 2 + 1 == stones.size() || a * 2 - 1 == stones.size()){
            fileout << "Y";
        }
        else{
            fileout << "N";
        }
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}