// Problem B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string readLine(ifstream& filein){
    string line;
    getline(filein, line);
    return line;
}
vector<ll> readWord(ifstream& filein, char delimiter){
    string line = readLine(filein);
    istringstream ss(line);
    string word;
    vector<ll> ret;
    while(getline(ss, word, delimiter)){
        ret.push_back(stol(word));
    };
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream filein("..\\FB2017\\1R\\B\\b.in");
    ofstream fileout("..\\FB2017\\1R\\B\\b.out");
    int T = stoi(readLine(filein));
    for(int t = 1 ; t <= T; ++t){
        vector<ll> nr = readWord(filein, ' ' );
        ll N = nr[0];
        ll R = nr[1];
        vector<vector<ll>> point(N, vector<ll>(2));
        set<ll> xline;
        set<ll> yline;
        for(int i = 0 ; i < N ; ++i){
            point[i] = readWord(filein, ' ' );
            xline.insert(point[i][0]);
            yline.insert(point[i][1]);
        }
        vector<pair<ll,ll>> visited(N);
        ll first_when = 1;
        ll second_when = 1;
        ll ret = 0;
        for(auto it = xline.begin(); it != xline.end(); ++it){
            for(auto jt = yline.begin(); jt != yline.end(); ++jt){
                ll X = *it;
                ll Y = *jt;
                for(int i = 0 ; i < point.size(); ++i){
                    if(point[i][0] <= X  && point[i][0] >= X-R && point[i][1] <= Y && point[i][1] >= Y-R ){
                        visited[i].first = first_when;
                    }
                }
                for(auto itt = xline.begin(); itt != xline.end(); ++itt){
                    for(auto jtt = yline.begin(); jtt != yline.end(); ++jtt){
                        ll XX = *itt;
                        ll YY = *jtt;
                        for(int i = 0 ; i < point.size(); ++i){
                            if(point[i][0] <= XX  && point[i][0] >= XX-R && point[i][1] <= YY && point[i][1] >= YY-R ){
                                visited[i].second = second_when;
                            }
                        }
                        ll tmp = 0;
                        for(int i = 0 ; i < point.size(); ++i){
                            if(visited[i].first == first_when || visited[i].second == second_when){
                                tmp += 1;
                            }
                        }
                        ret = max(ret, tmp);
                        ++second_when;
                    }
                }
                ++first_when;
            }
        }


        fileout << "Case #" << t << ": "; 
        fileout << ret;
        fileout << endl;
    }

    filein.close();
    fileout.close();

    return 0;
}