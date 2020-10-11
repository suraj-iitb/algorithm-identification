#include <stdio.h>
#define N 101

int main(){
  int i,j,n,A[N],flag,temp,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);


  //bubblesort 
  flag = 1; // 逆の隣接要素が存在する
  while (flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if (A[j] < A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;  
	  flag = 1;
	  c=c+1;
	  
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}




