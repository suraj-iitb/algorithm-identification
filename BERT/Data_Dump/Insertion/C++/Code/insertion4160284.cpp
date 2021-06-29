#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const int MAX = 100;

int main(){
    int n;
    int A[MAX];
    cin >> n;
    rep(i, n) cin >> A[i];
    
    int i, j;
    int v;

    for(i = 0; i < n; i++){
        v = A[i];
        j = i-1;

        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        rep(i,n){
            if(i > 0) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }

    return 0;
}
