#include <stdio.h>
int main(){
  int n,j,i,count=0,alg=0,res[100],flag=1;
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
  scanf("%d",&res[i]);
  }
  while(flag!=0){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(res[j]<res[j-1]){
	alg = res[j];
	res[j] = res[j-1];
	res[j-1] = alg;
	flag = 1;
	count++;
      }
     
    }
  }
  for(i=0;i<n;i++){
    printf("%d",res[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
    return 0;
  }
