#include "bits/stdc++.h"
using namespace std;
int main(){
    int N,i,j,v;
    cin >> N;
    vector<int> A(N);
    for(i=0;i<N;i++) cin >> A.at(i);
    for(i=1;i<N;i++){
        for(j=0;j<N;j++){
            if(j) cout << " ";
            cout << A.at(j);
        }
        cout << endl;
        v = A.at(i);
        j = i-1;
        while(j>=0&& A.at(j)>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = v;
    }
    for(i=0;i<N;i++){
        if(i) cout << " ";
        cout << A.at(i) ;
    }
    cout << endl;
    return 0;
}
