#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctype.h>
#include<string>
#include<cmath>
using namespace std;

void bubblesort(vector<int> A,int N){
    bool flag=1;
    int counter=0;
    while(flag){
        flag=0;
        for(int i=N-1;i>0;--i){
            if(A[i]<A[i-1]){
                int buf=A[i];
                A[i]=A[i-1];
                A[i-1]=buf;
                counter++;
                flag=1;
            }
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
    bubblesort(A,N);
    return 0;
}

