// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int gcd(int a, int b) {
        if(b > a) {
            return gcd(b, a);
        }
        if(a == b || b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<string, int> lines;
        for(int i = 0 ; i < points.size() ; ++i) {
            for(int j = i+1 ; j < points.size() ; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(abs(dx), abs(dy));
                if(dx != 0 && dy != 0) {
                    int sign = (dx * dy) / (abs(dx) * abs(dy));                
                    int bias = sign * (abs(dy) / g) * points[j][0] - (abs(dx) / g) * points[j][1]; 
                    string line = to_string(sign) + " " + to_string(abs(dx/g)) + " " + to_string(abs(dy/g)) + " " + to_string(bias);
                    lines[line] += 1;
                }
                else if(dx == 0) {
                    string line = "x " + to_string(points[j][0]);
                    lines[line] += 1;
                }
                else {
                    string line = "y " + to_string(points[j][1]);
                    lines[line] += 1;
                }
            }
        }
        
        int maxCombi = 0;
        
        for(auto it = lines.begin(); it != lines.end() ; ++it) {
            maxCombi = max(maxCombi, it->second);
        }
        
        for(int i = 1 ; i <= 300; ++i) {
            if(maxCombi == i * (i-1) / 2) {
                return i;
            }
        }
        return 0;
    }
};