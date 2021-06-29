#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAX 500000
#define INF 2000000000;
typedef long long ll;
int cnt;
vector<int> L(MAX/2+2),R(MAX/2+2);

void merge(int A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }
        else A[k]=R[j++];

    }
}
void mergeSort(int A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}
int main(void){
    int A[MAX],n,i;
    cnt=0;

cin>>n;
rep(i,n) cin>>A[i];
mergeSort(A,n,0,n);
rep(i,n){
    if(i!=0) cout<<" ";
    cout<<A[i];
}
cout<<endl;
cout<<cnt<<endl;


} 
