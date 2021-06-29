#include <stdio.h>

main(){

  int i,j,mini=0,min;
  int n,A[100],tmp;
  int count=0,flag=0;

  scanf("%d",&n);
  if(n<1||100<n)return 0;

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }


  min=A[0];

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(min>A[j]){
	min=A[j];
	mini=j;
	flag=1;
      }
    }
    if(flag==1){
	tmp=A[i];
	A[i]=A[mini];
	A[mini]=tmp;
	flag=0;
	count++;
      }
    min=A[i+1];


  }
      for(i=0;i<n;i++){
	printf("%d",A[i]);
	if(i<n-1)printf(" ");
	if(i==n-1)printf("\n");
  }
      printf("%d\n",count);
      return 0;
}
