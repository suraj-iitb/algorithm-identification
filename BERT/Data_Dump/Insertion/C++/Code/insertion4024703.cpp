#define N 100
#include<stdio.h>

int main()
{
  int i,j,key;
  /*数値を格納する配列*/
  int A[N];
  /*入力数字数*/
  int sum;
  /*入力数字数input*/
  scanf("%d",&sum);
  /*数字input*/
  for(i=0;i<sum;i++)
    scanf("%d",&A[i]);

  /*昇順にソートする*/
  for(i=0;i<sum;++i){
    key=A[i];
    j=i-1;
while(j>=0&&A[j]>key){
A[j+1]=A[j];
j--;
A[j+1]=key;
   
}
 /*各ステップ表示*/
 for(j=0;j<sum;j++){

   if(j>0)printf(" ");
   printf("%d",A[j]);}

printf("\n");}

return 0;
}

  

