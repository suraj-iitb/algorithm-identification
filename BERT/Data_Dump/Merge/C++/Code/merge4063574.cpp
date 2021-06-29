#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define INF 1200000000
int L[250010],R[250010];
int cnt=0;

void merge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++)L[i]=A[left+i];
    for(int i=0;i<n2;i++)R[i]=A[mid+i];
    L[n1]=INF;R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
            cnt++;
        }
        else{
            A[k]=R[j];
            j++;
            cnt++;
        }
    }
}
    

void mergesort(int A[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        merge(A,left,mid,right);
    }
}


int main(){
    int n,S[500100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>S[i];
    mergesort(S,0,n);
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<S[i];
    }
    
    cout<<endl<<cnt<<endl;
    
}



