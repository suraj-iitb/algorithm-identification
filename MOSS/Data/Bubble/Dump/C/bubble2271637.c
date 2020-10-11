#include<stdio.h>
#define N 100

int main(){
  
  int a[N],b,c,i,j,count=0;
  
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<b;i++){
    for(j=b-1;j>i;j--){
      if(a[j] < a[j-1]){
	c = a[j];
	a[j] = a[j-1];
	a[j-1] = c;
	count++;
      }
    }
  }
  for(i=0;i<b;i++){
    printf("%d", a[i]);
    if(b-1>i) printf(" ");
    
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  
  return 0;
}
