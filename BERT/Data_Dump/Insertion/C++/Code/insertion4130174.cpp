#include <bits/stdc++.h>
using namespace std;

void trace(vector<int> X){
    for(int i=0;i<X.size();i++){
        cout << X.at(i);
        if(i<X.size()-1) cout << " ";
    }
    cout << endl;
}

void Insertion(vector<int> X){
    for(int i=1;i<X.size();i++){
        int v=X.at(i);
        int j=i-1;
        while(j>=0 && X.at(j)>v){
            X.at(j+1)=X.at(j);
            j--;
        }
        X.at(j+1)=v;
        trace(X);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    trace(A);
    Insertion(A);
}

