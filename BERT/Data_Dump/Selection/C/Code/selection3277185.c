#include<stdio.h>

int main()
{
  int N,A[100];
  int i,j,minj,cnt=0;
  int a;//交換する際に使う

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){ //比較
	minj = j;
      }
    }
    if(i!=minj){//iとminjが一致したら含めない。
      a =  A[i];
      A[i] = A[minj];
      A[minj] = a;
      cnt++;
    }    
  }
  
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

