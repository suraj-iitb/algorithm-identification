#include <stdio.h>
#include <stdlib.h>
#define N 1000000000

int c=0;
void m(int A[], int left,int mid,int right){
  int i,j,k,x,y,*L,*R;
  x=mid-left;
  y=right-mid;
  L=(int *)malloc(sizeof(int)*(x+1));
  R=(int *)malloc(sizeof(int)*(y+1));
  for(i=0;i<=x-1;i++){
    L[i]=A[left+i];
  }
  for(j=0;j<=y-1;j++){
    R[j]=A[mid+j];
  }
  L[x]=N;
  R[y]=N;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      c++;
    }
    else{
      A[k]=R[j];
      j++;
      c++;
    }
  }
  free(L);
  free(R);
}
void ms(int A[],int left,int right){
  int i,mid;
  if(left+1<right){
    mid=(left+right)/2;
    ms(A,left,mid);
    ms(A,mid,right);
    m(A,left,mid,right);
  }
}
int main(){
  int A[500000];
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  ms(A,0,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

