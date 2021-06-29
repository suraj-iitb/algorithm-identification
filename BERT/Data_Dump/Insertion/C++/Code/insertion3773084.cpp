#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int N,v,j;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    
    cout << A[0];
    for(int i=1;i<N;i++){
        cout << " " << A[i] ;
    }
    cout << endl;
    
    for(int i=1; i<N; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
        cout << A[0];
        for(int i=1;i<N;i++){
            cout << " " << A[i] ;
        }
        cout << endl;
    }
}

