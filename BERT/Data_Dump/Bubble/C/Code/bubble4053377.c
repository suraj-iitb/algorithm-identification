#include <stdio.h>

int bub(int[],int);

int main(){
  int n,i,j=0,put,flag,con = 0;
  int a[100];
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  while(j != n-1){
  for(i = n-1;i >= j+1;i--){
    if(a[i-1] > a[i]){
      put = a[i];
      a[i] = a[i-1];
      a[i-1] = put;
      con++;
    }
  }
  j++;
  }
  for(i = 0;i < n;i++){
    if(i != 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",con);

  return 0;
}

