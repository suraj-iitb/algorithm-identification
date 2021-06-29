#include<bits/stdc++.h>
using namespace std;

char card[100000],card2[100000];

void merge(int a[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1],R[n2+1];
  char LL[n1+1],RR[n1+1];
  for(int i=0;i<n1;i++){
    L[i]=a[left+i];
    LL[i]=card2[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=a[mid+i];
    RR[i]=card2[mid+i];
  }
  L[n1]=R[n2]=100000001;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k]=L[i];
      card2[k]=LL[i];
      i++;
    }else{
      a[k]=R[j];
      card2[k]=RR[j];
      j++;
    }
  }
}

void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int partition(int A[],int p,int r){
  int x=A[r];
  int i=p-1;
  for(int j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      swap(A[i],A[j]);
      swap(card[i],card[j]);
    }
  }
  swap(A[i+1],A[r]);
  swap(card[i+1],card[r]);
  return i+1;
}

void quicksort(int A[],int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int main(){
  int n;
  int A[100000],a[100000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>card[i]>>A[i];
    card2[i]=card[i];
    a[i]=A[i];
  }
  quicksort(A,0,n-1);
  mergeSort(a,0,n);
  for(int i=0;i<n;i++){
    if(card[i]!=card2[i]){
      cout<<"Not stable"<<endl;
      break;
    }
    else if(i==n-1) cout<<"Stable"<<endl;
  }
  for(int i=0;i<n;i++){
    cout<<card[i]<<" "<<A[i]<<endl;
  }
  return 0;
}

