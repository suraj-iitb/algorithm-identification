#include<stdio.h>
#include<stdlib.h>
void Count(int *,int *,int);
int n,b[2000000];
int main(){
  int i,*a,big=0,*c;
  scanf("%d",&n);
  a=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(big<a[i])big=a[i];
  }
  c=malloc(sizeof(int)*big);
  Count(a,c,big);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",b[i]);
    else printf("%d ",b[i]);
  }
  free(a);
  free(c);
  return 0;
}

void Count(int *A,int *C,int k){
  int i,j;
  for( i = 0 ;i< k;i++){
       C[i] = 0;
  }

  for( j = 0 ;j<n;j++){
     C[A[j]]++;
  }
  for( i = 1 ;i<= k;i++){
     C[i] = C[i] + C[i-1];
  }
  for( j = n-1 ;j>= 0;j--){
     b[C[A[j]]-1] = A[j];
     C[A[j]]--;
  }
}

