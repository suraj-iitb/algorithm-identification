//
//  main.cpp
//  ALDS54
//

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
        if (i>0) {
            cout << " ";
        }
        cout << A.at(i);
    }
    cout << endl;
    
    int TMP;
    for (int j=1; j<N; j++) {
        TMP=A.at(j);
        for (int k=j-1; k>=0; k--) {
            if (A.at(k)>TMP) {
                A.at(k+1)=A.at(k);
                A.at(k)=TMP;
            }
        }
        for (int m=0; m<N; m++) {
            if (m>0) {
                cout << " ";
            }
            cout << A.at(m);
        }
        cout << endl;
    }
    return 0;
    /*
     6
     5 2 4 6 1 3
     
     3
     1 2 3
     */
}

