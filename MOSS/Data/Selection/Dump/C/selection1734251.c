#include<stdio.h>
#define A 100
int main(){
  int n,a[A],i,count=0,change,min,j,jud = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  for(i = 0;i < n;i++){
    min = i;
    change = a[i];
    for(j = i;j < n;j++){
      if(a[j] < a[min]){
	min =j;
	
      }
    }
    if(change != a[min]){
    change = a[i];
    a[i] = a[min];
    a[min] = change;
    count++;
    }
  }

  for(i = 0;i < n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[n-1],count);

  return 0;

}
