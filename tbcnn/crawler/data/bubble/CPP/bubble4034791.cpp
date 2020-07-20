#define N 100
#include<stdio.h>


int main(){
  /*スワップ数*/
int count=0;
int A[N];
 int i,j,n,temp;
 /*入力数*/
  scanf("%d",&n);
  /*配列格納*/
  for(i=0;i<n;i++)

    scanf("%d",&A[i]);
  /*Bubble Sort*/
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j-1]>A[j]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	count++;
      }}

  }
  /*カウント数と配列出力*/
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);}
  printf("\n");
  printf("%d\n",count);
  return 0;


}



