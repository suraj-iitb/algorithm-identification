#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &A,vector<int> &B,vector<int> &C,int n){
    for(int i=0;i<n;i++){
        C.at(A.at(i))++;
    }
    for(int k=0;k<10000;k++){
        C.at(k+1)+=C.at(k);
    }
    for(int i=n-1;i>=0;i--){
        B.at(C.at(A.at(i))-1)=A.at(i);
        C.at(A.at(i))--;
    }

}

void print(vector<int> &A,int n){
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << A.at(i);
    }
    cout << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n),B(n),C(10001);
    for(int i=0;i<n;i++){
        cin >> A.at(i);
    }
    countingSort(A,B,C,n);
    print(B,n);
    return 0;
}
