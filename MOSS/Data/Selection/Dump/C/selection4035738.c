#include <stdio.h>

int main(){
  int n,i,j,minj,put,con = 0;
  int a[100];
  
  scanf("%d",&n);
  for(i = 0; i < n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i = 0;i < n-1;i++){
    minj = i;
    for(j = i;j < n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
     put = a[i];
    a[i] = a[minj];
    a[minj] = put;
    if(i != minj) con++;
  }

  for(i = 0;i < n;i++){
    if(i != 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",con);

  return 0;
}

