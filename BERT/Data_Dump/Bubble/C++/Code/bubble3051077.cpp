#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,i,j,count;
    cin >> n;
    vector<int> A(n);
    for(i=0;i<n;i++) cin >> A.at(i);
    int flag = 1;
    count = 0;
    while(flag){
        flag = 0;
        for(j=n-1;j>0;j--){
            if(A.at(j)<A.at(j-1)){
                swap(A.at(j),A.at(j-1));
                flag = 1;
                count++;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i) cout << " " ;
        cout << A.at(i);
    }
    cout << endl << count << endl;
    return 0;
}
