#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ll long long
using namespace std;

#define sent 2000000000
#define MAX 500000

int cnt=0;
int L[MAX/2+2],R[MAX/2+2];

void merge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;

    rep(i,n1) L[i]=A[left+i];
    rep(i,n2) R[i]=A[mid+i];

    L[n1]=R[n2]=sent;

    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
        cnt++;
    }

}

void mergeSort(int A[],int left,int right){
    if (left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }

}

int main(){
    int n;
    int S[500000];
    cin>>n;
    rep(i,n) cin>>S[i];
    mergeSort(S,0,n);

    rep(i,n-1){
        cout<<S[i]<<" ";
    }
    cout<<S[n-1]<<endl;

    cout<<cnt<<endl;


    return 0;
}
