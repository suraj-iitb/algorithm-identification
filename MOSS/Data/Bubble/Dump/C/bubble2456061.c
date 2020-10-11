#include <stdio.h>

#define N 101

int main(){

  int A[N];
  int n,i,j,flag=1,tmp,cout=0;

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

 
   while(flag){
      flag=0;
      for(j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cout++;
      }
    }
  }
  
   for(i=0;i<n;i++){
     printf("%d",A[i]);
     if(i==n-1){ printf("\n");
     }else printf(" ");
     }

   printf("%d\n",cout);
   
   return 0;
  }
