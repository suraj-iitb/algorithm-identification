#include<stdio.h>
int main(){
  int a[100],n,flag,avoid,i,cnt=0;
    scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%d",&a[i]);
  }
  
  flag=1;

  while(flag){
    flag=0;
    for(i=n-1; i > 0; i--){
      if(a[i] < a[i-1]){
	avoid=a[i];
	a[i]=a[i-1];
	a[i-1]=avoid;
	flag=1;
	cnt++;
      }
    }
  }
  for(i=0; i < n; i++){
    printf("%d",a[i]);
    if(i != n-1){
      printf(" ");
    }
    else printf("\n");
  }
  printf("%d\n",cnt);

  return 0;
}

