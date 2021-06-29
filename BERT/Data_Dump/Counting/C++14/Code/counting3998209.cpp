#include<iostream>
using namespace std;

void countingSort(int n,int A[]){
    int C[10001]={};//最大数は10000なので。
    for(int i=0;i<n;i++){
        C[A[i]]++;//カウントしていく。
    }
    for(int i=0;i<10000;i++){
        C[i+1]+=C[i];//累積和に。
    }
    int B[n];//出力用配列。
    for(int j=n-1;j>-1;j--){
        B[C[A[j]]-1]=A[j];//カウント数とインデックスが1ズレるの注意。
        C[A[j]]--;
    }
    for(int j=0;j<n;j++){
        if(j)cout<<' ';
        cout<<B[j];
    }
    cout<<endl;
}

int main(){
    int n;cin>>n;int A[n];for(int i=0;i<n;i++)cin>>A[i];
    countingSort(n,A);
    return 0;
}
