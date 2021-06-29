#include <stdio.h>

int main(){

  int n,i,j,a=0;
  int b[100],minj,x;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(b[j]<b[minj]){
	minj=j;
      }
    }

    if(b[i]>b[minj]){
      a++;
    }
    x = b[minj];
    b[minj] = b[i];
    b[i] = x;
  }
  
    for(i=0;i<n-1;i++){
      printf("%d ",b[i]);
    }
    printf("%d\n",b[n-1]);
    printf("%d\n",a);

    return 0;
  }
  

