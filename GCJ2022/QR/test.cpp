#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

template<class T>
double Mean(std::vector<T> array)
{
    double sum = 0.0;

    for (int i = 0; i < array.size(); i++)
        sum += array[i];

    return sum / array.size();
}

// 표준 편차 계산 함수
template<class T>
double StandardDeviation(std::vector<T> array)
{
    double meanValue = Mean<T>(array);

    // 배열 요소가 1개밖에 없을 때는
    // NaN(숫자가 아님)이라는 의미로
    // sqrt(-1.0) 을 반환
    int size = array.size();
    if (size < 2)
    {
        return sqrt(-1.0);
    }

    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        double diff = array[i] - meanValue;
        sum += diff * diff;
    }

    return sqrt(sum / (size - 1));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 256;

    mt19937 gen(19911);
    uniform_int_distribution<int> dis(0, 1);

    vector<vector<int>> arr(256, vector<int>(256));
    for(int i = 0 ; i < 256 ; ++i) {
        for(int j = 0 ; j < 256 ; ++j) {
            arr[i][j] = rand() % 2;
//             if(arr[i][j] == 0) {
//                 cout << ' ';
//             }
//             else {
//                 cout << 0;
//             }
// //            cout << arr[i][j];
        }
        // cout << endl;
    }

    vector<int> dist;
    for(int i = 1 ; i < 255 ; ++i) {
        for(int j = 1 ; j < 255 ; ++j) {
            int count = 0;
            if(arr[i-1][j-1] == 1) {
                count += 1; 
            }
            if(arr[i+1][j-1] == 1) {
                count += 1; 
            }
            if(arr[i-1][j+1] == 1) {
                count += 1; 
            }
            if(arr[i+1][j+1] == 1) {
                count += 1; 
            }
            dist.push_back(count);
        }
    }

    cout << StandardDeviation(dist) << endl;

    dist.clear();
    for(int i = 0 ; i < 256 ; ++i) {
        for(int j = 0 ; j < 256 ; ++j) {
            arr[i][j] = dis(gen);
//             if(arr[i][j] == 0) {
//                 cout << ' ';
//             }
//             else {
//                 cout << 0;
//             }
// //            cout << arr[i][j];
        }
    }

    for(int i = 1 ; i < 255 ; ++i) {
        for(int j = 1 ; j < 255 ; ++j) {
            int count = 0;
            if(arr[i-1][j-1] == 1) {
                count += 1; 
            }
            if(arr[i+1][j-1] == 1) {
                count += 1; 
            }
            if(arr[i-1][j+1] == 1) {
                count += 1; 
            }
            if(arr[i+1][j+1] == 1) {
                count += 1; 
            }
            dist.push_back(count);
        }
    }
    cout << StandardDeviation(dist) << endl;

    return 0;

}