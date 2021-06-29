/*Counting Sort*/
#include<iostream>
#define N 2000000
using namespace std;

int n;
int A[N];
int B[N];

void CountingSort(int A[],int B[],int n,int k){
    int C[10002];
    for(int i=0;i<=k;i++){
        C[i]=0;
    }
    for(int j=0;j<n;j++){
        C[A[j]]=C[A[j]]+1;
    }
    for(int i=1;i<=k;i++) C[i]=C[i]+C[i-1];
    //for(int i=0;i<=k;i++) cout<<C[i]<<' '; cout<<endl;
    for(int j=n-1;j>=0;j--){
        B[C[A[j]]-1]=A[j];   //注意这里的写法
        C[A[j]]=C[A[j]]-1;

        //cout<<"j= "<<j<<" || ";
        //for(int i=0;i<=k;i++) cout<<C[i]<<" ";  cout<<" || ";
        //for(int i=0;i<n;i++) cout<<B[i]<<' '; cout<<endl;

    }
}

int main(){
    int mnum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
        mnum=max(A[i],mnum);
    }
    CountingSort(A,B,n,mnum);
    for(int i=0;i<n;i++){
        if(i) cout<<' ';
        cout<<B[i];
    }
    cout<<endl;
    return 0;
}

