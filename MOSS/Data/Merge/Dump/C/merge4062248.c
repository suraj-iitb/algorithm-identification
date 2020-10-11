#include <stdio.h>
#define N 500000
#define INFTY 10000000000

long int L[N/2+2],R[N/2+2];
int count;


void merge(int S[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L[i]=S[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=S[mid+i];
  }
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i=i+1;
    }
    else{
      S[k]=R[j];
      j=j+1;
    }
    count++;
  }
}

void mergesort(int S[],int left,int right){
    if(left+1<right){
      int mid=(left+right)/2;
      mergesort(S,left,mid);
      mergesort(S,mid,right);
      merge(S,left,mid,right);
    }
}


int main(){
  int S[N],n,i;
  count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mergesort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
 
  printf("\n%d\n",count);

  return 0;
}
   

  



