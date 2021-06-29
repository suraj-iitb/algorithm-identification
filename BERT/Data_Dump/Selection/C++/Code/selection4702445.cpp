#include <bits/stdc++.h>
using namespace std;

int selection(vector<int> &A,int N){
    int sw=0;
    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A.at(j)<A.at(minj)) minj=j;
        }
        swap(A.at(i),A.at(minj));
        if(i!=minj) sw++;
    }
    return sw;
}

int main(void){
    int N;
    cin >> N;
    
vector<int> A(100);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    
    int sw=selection(A,N);
    
    for(int i=0;i<N-1;i++){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
    
    cout << sw << endl;
    return 0;
}
