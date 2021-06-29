#include<iostream>

using namespace std;

#define MAX 500000
#define N 2000000000

int L[MAX/2+2],R[MAX/2+2];
int tmp;

void marge(int A[],int n,int l,int mid,int r){
  int n1=mid-l;
  int n2=r-mid;

  for(int i=0;i<n1;i++) L[i]=A[l+i];
  for(int i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=R[n2]=N;
  int i=0,j=0;

  for(int k=l;k<r;k++){
    tmp++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void sort(int A[],int n,int l,int r) {
  if(l+1<r){
    int mid=(l+r)/2;
    sort(A,n,l,mid);
    sort(A,n,mid,r);
    marge(A,n,l,mid,r);
  }
}

int  main() {
int A[MAX],n,i;
tmp=0;

cin >>n;

for( i=0;i<n;i++) cin >> A[i];

sort(A,n,0,n);

for (i=0;i<n;i++) {
 if(i) cout << " ";
 cout << A[i];
}
cout << endl;

cout << tmp << endl;
  return 0;
}

