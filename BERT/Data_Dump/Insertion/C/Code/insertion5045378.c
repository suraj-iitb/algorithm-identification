#include<stdio.h>
#define N 100/*制約*/
#define A_MAX 1000
int main(){
  int n,A[N],i,j,k,v;
  scanf("%d",&n);/*入力*/
  for(i=0;i<n;i++){
    if(scanf("%d",&A[i])==EOF)break;
    if(A[i]<0||A[i]>A_MAX)break;
  } 
  for(k=0;k<n;k++){
    printf("%d",A[k]);/*出力*/
    if(k!=n-1)printf(" ");
    else break;
  }
  printf("\n");
  for(i=1;i<n;i++){/*アルゴリズム*/
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(k=0;k<n;k++){
      printf("%d",A[k]);/*出力*/
      if(k!=n-1)printf(" ");
      else break;
    }
    printf("\n");
  }
  return 0;
}

