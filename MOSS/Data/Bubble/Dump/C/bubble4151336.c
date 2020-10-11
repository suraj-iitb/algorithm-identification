#include<stdio.h>
#define D 100

int bubble(int A[],int N){
  int a = 0,flag =1,es;
  for(int i=0;flag>0;i++){
    flag = 0;
    for(int j = N-1;j>i;j--){
      if(A[j]<A[j-1]){
	es=A[j];
	A[j]= A[j-1];
	A[j-1] = es;
	flag = 1;
	a++;
      }
    }
  }
  return a;
}

int main(){
  int A[D],N,a,i;
  scanf("%d",&N);
  for(i = 0;i<N;i++)
    scanf("%d",&A[i]);

  a = bubble(A,N);

  for(i = 0;i<N;i++){
    if(i>0)
      printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");
  printf("%d\n",a);

  return 0;
}

  

