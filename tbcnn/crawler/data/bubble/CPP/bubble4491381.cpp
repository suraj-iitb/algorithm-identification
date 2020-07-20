#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
    int t;
    t=a;    a=b;    b=t;
}

void bubblesort(int N,int A[]){
    int co[1000]={0},cnt=0;
    for(int j=0;;j++){
        for(int i=N-1;i>j;i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                co[j]++;
            }
        }
        cnt+= co[j];
        if(co[j]==0)    break;
    }
    for(int i=0;i<N;i++){
        cout<<A[i];
        if(i!=N-1)  cout<<' ';
    }
    cout<<'\n';
    cout<<cnt<<endl;
}

int main(){

    int N=0,A[100]={0};
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    bubblesort(N,A);
}
