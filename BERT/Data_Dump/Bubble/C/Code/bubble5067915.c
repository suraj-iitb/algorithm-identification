#include <stdio.h>

int main(){
  int n,A[100],i,j,a,count=0;

  //*ｎを読み込む*//
  scanf("%d",&n);
  if(n<1||n>100){
    //*ｎが制約外ならerror表示*//
    printf("error\n");
  }
  //*数列の読み込み*//
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    //*A[i]が制約外ならerror表示*//
    if(A[i]<0||A[i]>100){
      printf("error\n");
    }
  }

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        a=A[j];
        A[j]=A[j-1];
        A[j-1]=a;
        count++;
        }
    }
  }

  //*数列の表示*//
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  //*入替回数の表示*//
  printf("%d",count);
  printf("\n");

  return 0;
}
