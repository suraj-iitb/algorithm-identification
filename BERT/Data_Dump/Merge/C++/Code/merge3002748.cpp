#include<iostream>
using namespace std;
#define Max 500000
#define SENTINEL 1000000000

int L[Max/2+2], R[Max/2+2];
int cnt;

int merge(int A[],int n,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++)
      L[i]=A[left+i];
  for(int i=0;i<n2;i++)
      R[i]=A[mid+i];
  L[n1]=R[n2]=SENTINEL;
  int j=0,i=0;
  for(int k=left;k<right;k++){
    cnt++;
     if(L[i]<=R[j]){
         A[k]=L[i++];
       }
     else{
       A[k]=R[j++];
     }
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
int main(){
    int A[Max],n,i;
    cnt=0;
    
    cin>>n;
    for(i=0;i<n;i++)
       cin>>A[i];
    mergeSort(A,n,0,n);
    
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
