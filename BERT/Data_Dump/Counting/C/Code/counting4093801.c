#include <stdio.h>

int main(){
  int n,i,j,c[20000],t,flag=0;
  
  scanf("%d",&n);

  for(i=0;i<10001;i++){
    c[i] = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&t);
    c[t]++;
  }

  for(i=0;i<10001;i++){
    for(j=c[i];0<j;j--){
      if(flag==1){
	printf(" ");
      }
      printf("%d",i);
      flag=1;
    }
  }
  printf("\n");

  return 0;
}

