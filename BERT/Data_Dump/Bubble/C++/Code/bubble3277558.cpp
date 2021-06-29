#include<stdio.h>
int main(){
  int a,i,A[100],flag,c,j,count=0;
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&A[i]);
  flag = 1;
    while (flag == 1){
      flag = 0;
      for (j=a-1;j>=1;j--){
	if (A[j] < A[j-1]){
	  c=A[j];
	A[j]=A[j-1];
	A[j-1]=c;
        flag = 1;
	count++;
	}
      }
    }

  

    for(i=0;i<a;i++){
      if(i!=a-1)printf("%d ",A[i]);
      else printf("%d",A[i]);
    }
  printf("\n%d\n",count);


}

