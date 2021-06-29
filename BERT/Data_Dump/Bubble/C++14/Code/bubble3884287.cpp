//
//  main.cpp
//  ALDS60
// バブルソートの練習

#include <iostream>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    int TMP;
    int count=0;
    for (int i=0; i<N-1; i++) {
        for (int j=N-1; j>0; j--) {
            int k=j-1;
            if (A.at(j)<A.at(k)) {
                    TMP=A.at(j);
                    A.at(j)=A.at(k);
                    A.at(k)=TMP;
                    count++;
                }
        }
    }

    for (int m=0; m<N-1; m++) {
        cout << A.at(m) << " ";
    }
    cout << A.at(N-1)<<endl;
    cout << count << endl;
    return 0;
}

