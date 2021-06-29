#include <stdio.h>

int main(){

  int n,i,j,num[100],cnt=0,tmp,min;
  int minj;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&num[i]);

  for(i=0;i<n;i++){
      minj =i;
    for(j=i;j<n;j++){
       
      if(num[minj] > num[j]){
	minj = j;
      }
    }
    if(minj != i){
	tmp =num[i];
      num[i]=num[minj];
      num[minj]= tmp;
      cnt++;
    }
  }
  
    
  for(i=0;i<n;i++){
    printf("%d",num[i]);
    if(i != n-1)printf(" ");
      }
  printf("\n%d\n",cnt);
  
  return 0;
}

