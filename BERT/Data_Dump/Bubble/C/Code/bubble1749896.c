#include<stdio.h>
#define N 100
#define swap(x,y) {x+=y;y=x-y;x-=y;}
int main(){
  int A[N],i=0,j ,a,flag,b=0,o;

  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }


  flag=1;
  while(flag){
    flag=0;
    for(j=a-1;j>=1;j--){
      if(A[j] < A[j-1]){
	swap(A[j] , A[j-1]);

	flag=1;
	b++;
      }
    }

  }
  
  for(i=0;i<a;i++){
    printf("%d",A[i]);
    if(i != a-1){
      printf(" ");
    }
  }
  printf("\n%d\n",b);

  return 0;
}
