#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctype.h>
#include<string>
#include<cmath>
using namespace std;

void selectionSort(vector<int> A,int N){
    int counter=0;
    for(int i=0;i<N;++i){
        int minj=i;
        for(int j=i;j<N;++j){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            int buf=A[i];
            A[i]=A[minj];
            A[minj]=buf;
            counter++;
        }
    }
    for(int i=0;i<N;++i){
        if(i!=0)cout<<" ";
        cout<<A[i];
    }
    cout<<endl<<counter<<endl;
}

int N;
vector<int> A;

int main(){
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    selectionSort(A,N);
    return 0;
}

