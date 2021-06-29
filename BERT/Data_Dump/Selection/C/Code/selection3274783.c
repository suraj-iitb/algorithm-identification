#include<stdio.h>
#define N 100
int main(){
  int n,A[N],foo,minA,mini,sum=0,i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n-1;i++){
    minA=A[i];
    mini=i;
    for(j=i+1;j<n;j++){
      if(minA>A[j]){
	minA=A[j];
	mini=j;
      }
    }
    if(i!=mini){
    A[mini]=A[i];
    A[i]=minA;
    sum++;
    }
  }
  for(i=0;i<n;i++){
    if(i!=0)
      printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",sum);
  return 0;
}
