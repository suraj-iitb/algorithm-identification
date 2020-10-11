#include <stdio.h> 

int main()
{
  int n,i,in,j,result=0;

  /*nに要素数を入力*/
  scanf("%d",&n);
  /*配列作成,A[n]値入力*/
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
 
 /*バブルソート*/
  for(i=1;i<n;i++){
    for(j=n-1;j>=i;j--){
      /*変換、変換回数カウント*/
      if(A[j]<A[j-1]){
       in=A[j];
       A[j]=A[j-1];
       A[j-1]=in;
       result++;
      }
    }
  }
  /*出力*/
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",A[i]);
    else
      printf("%d ",A[i]);
  }
  printf("%d\n",result);

 return 0;
}
