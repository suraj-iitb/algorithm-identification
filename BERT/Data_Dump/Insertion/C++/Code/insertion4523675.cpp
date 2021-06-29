#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctype.h>
#include<string>
#include<cmath>
using namespace std;

void insertionSort(vector<int> &A,int N){
    for(int j=0;j<N;j++){
        if(j!=0)cout<<" ";
        cout<<A[j];
    }
    cout<<endl;
    for(int i=1;i<N;++i){
        int v=A[i];
        int j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        for(int j=0;j<N;j++){
            if(j!=0)cout<<" ";
            cout<<A[j];
        }
        cout<<endl;
    }
}

int N;
vector<int> A;

int main(){
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    insertionSort(A,N);
    return 0;
}

