#include <stdio.h>
#include <stdlib.h>
#define N 500000
#define A 1000000000


int res=0;

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int main(){
  int i,n,S[N];

  scanf("%d",&n); 
  if(n>N){
    printf("error\n");
    exit(1);
  }

  for(i=0 ; i<n ; i++){
    scanf("%d",&S[i]);
  }

  mergesort(S,0,n);

  for(i=0 ; i<n-1 ;i++){
    printf("%d " ,S[i]);
  }
  printf("%d",S[n-1]);
  printf("\n%d\n",res);

  return 0;
}

void mergesort(int *S,int left,int right){
    int mid;
    if(left+1 < right){
      mid = (left+right)/2;
      mergesort(S,left,mid);
      mergesort(S,mid,right);
      merge(S,left,mid,right);
    }
}

void merge(int *S,int left,int mid,int right){
  int n1=mid-left,n2=right-mid,i,j,k;
 int L[n1+1],R[n2+1];
  
  for(i=0 ; i<n1 ; i++){
    L[i]=S[left + i];
  }
  
  for(i=0 ; i<n2 ; i++){
    R[i]=S[mid + i];
  }
  
  L[n1]=A;
  R[n2]=A;
  i=0;
  j=0;
  
  for(k=left ; k<right ; k++){
    res++;
    if(L[i]<=R[j]){
      S[k]=L[i];
      i++;
    }
    else{
      S[k]=R[j];
      j++;
    }
    
  }
}
