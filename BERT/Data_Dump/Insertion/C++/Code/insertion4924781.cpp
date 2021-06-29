#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384
#define NUM_MAX 2e18

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int A[1000] = {0};
    
    cin >> N;
    rep(i, N){
        cin >> A[i];
    }
    
    cout << A[0];
    for(int k=1; k<N; k++){
        cout << ' ' << A[k];
    }
    cout << endl;
    
    for(int i=1; i<N; i++){
        for(int j=i; j>0; j--){
            if(A[j-1]>A[j]){
                int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
            }
        }
        cout << A[0];
        for(int k=1; k<N; k++){
            cout << ' ' << A[k];
        }
        cout << endl;
    }
    return 0;
}

