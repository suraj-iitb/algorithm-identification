//
//  main.cpp
//  ALDS65
//
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    int count=0;
    for (int i=0; i<N; i++) {
        int min=1000000000;
        int min_pos=0;
        for (int j=i; j<N; j++) {
            if (A.at(j)<min) {
                min=A.at(j);// 残りの中で最小の値
                min_pos=j; // 最小の値の場所
            }
        }
        if (min_pos!=i) { // 数字の場所を入れ替える
            A.at(min_pos)=A.at(i);
            A.at(i)=min;
            count++;
        }
    }
    for (int k=0; k<N; k++) {
        if(k>0){
            cout << " ";
        }
        cout << A.at(k);
    }
    cout << endl;
    cout << count << endl;
    return 0;
    /*
     6
     5 6 4 2 1 3
     */
}

