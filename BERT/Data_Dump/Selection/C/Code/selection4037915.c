#include <stdio.h>

int main()
{
  int n,i,in,j,result=0,minj;

  /*nに要素数を入力*/
  scanf("%d",&n);
  /*配列作成,A[n]値入力*/
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    /*変換、変換回数カウント*/   
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      in=A[i];
      A[i]=A[minj];
      A[minj]=in;
      result++;
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

