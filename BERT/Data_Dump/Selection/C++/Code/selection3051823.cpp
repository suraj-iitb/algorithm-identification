#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,i,j,minj;
    int count = 0;
    cin >> n;
    vector<int> A(n);
    for(i=0;i<n;i++) cin >> A.at(i);
    for(i=0;i<n;i++){
        minj = i;
        for(j=i;j<n;j++){
            if(A.at(j)<A.at(minj)) minj = j;
        }
        if(i != minj){
            swap(A.at(i),A.at(minj));
            count++;
        }
    }
    for(i=0;i<n;i++){
        if(i) cout << " ";
        cout << A.at(i);
    }
    cout << endl << count << endl;
    return 0;
}
