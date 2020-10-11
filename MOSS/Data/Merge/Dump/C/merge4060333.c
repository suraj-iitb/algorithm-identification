#include <stdio.h>
#include <string.h>
#define INFTY 1000000000
#define MAX 500000
int l,m,r,i,j,k;
int count;
void marge(int A[],int l,int m,int r){
  int a1,a2;
  a1 = m - l;
  a2 = r - m;
  int Left[a1];
  int Right[a2];
  for(i=0;i<a1;i++){
    Left[i]=A[l+i];
  }
  for(j=0;j<a2;j++){
    Right[j]= A[m+j];
  }
  Left[a1]= INFTY;
  Right[a2] = INFTY;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    count = count +1;
    
    if(Left[i]<=Right[j]){
      A[k] = Left[i];
      i = i+1;
    }
    else {
      A[k]=Right[j];
      j=j+1;
    }
  }
}

void mergesort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
 
    mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    marge(A,left,mid,right);
  }
}

int main(){
  int n,p;
  int A[MAX];
  scanf("%d",&n);
  for(p=0;p<n;p++){
    scanf("%d",&A[p]);
  }
  mergesort(A,0,n);

  for(p=0;p<n;p++){
    if(p!=n-1){
    printf("%d",A[p]);
    printf(" ");
    }
    else if (p==n-1){
      printf("%d",A[p]);
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

  
      

