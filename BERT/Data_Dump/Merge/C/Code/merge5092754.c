#include <stdio.h>
#define N 500000
#define MAX 1000000000

void Merge(int *,int,int,int);
void Mergesort(int *,int,int);

int ss=0;
int main(){
  int i,j,n,ls[N];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&ls[i]);
  Mergesort(ls,0,n);
  for(i=0;i<n-1;i++)printf("%d ",ls[i]);
  printf("%d\n%d\n",ls[i],ss);
  return 0;
}

void Merge(int ls[],int left,int midl,int right){
  int n1 = midl - left,n2 = right - midl;
  int L[n1],R[n2],i,j=0,k=0;
  for(i=0;i<n1;i++)L[i]=ls[left+i];
  for(i=0;i<n2;i++)R[i]=ls[midl+i];
  L[n1] = MAX;
  R[n2] = MAX;
  for(i=left;i<right;i++){
    if(L[j]<=R[k]){
      ls[i]=L[j];
      j++;
      ss++;
    }
    else{
      ls[i]=R[k];
      k++;
      ss++;
    }
  }
}
void Mergesort(int ls[],int left,int right){
  int midl;
  if(left+1<right){
    midl=(left+right)/2;
    Mergesort(ls, left, midl);
    Mergesort(ls, midl, right);
    Merge(ls,left,midl,right);
  }
}
