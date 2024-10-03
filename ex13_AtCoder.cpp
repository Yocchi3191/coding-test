#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // 全員の点数を取得
    vector<int> points(N);
    for(int i=0; i<N; i++){
        cin >> points.at(i);
    }

    // 平均値を取得
    int average;
    for(int i=0; i<N; i++){
        average += points.at(i);
    }
    average = average / N;

    // 各点数との偏差を計算
    for(int i=0; i<N; i++){
        int d = points.at(i) - average;
        if(d < 0){
            d = d * -1;
        }
        cout << d << endl;
    }

}
