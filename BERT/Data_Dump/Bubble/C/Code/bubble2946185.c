#include<stdio.h>

int main(){
  int l,f,i,buf,count,a[100];

  f = 1;
  count = 0;
  
  scanf("%d",&l);
  for(i = 0; i < l; i++)
    scanf("%d",&a[i]);
  
  while(f){
    f = 0;
    for(i = l - 1; i != 0; i--){
      if(a[i] < a[i - 1]){
	buf = a[i];
	a[i] = a[i - 1];
	a[i - 1] = buf;
	f = 1;
	count++;
	break;
      }
    }
  }
  for(i = 0; i < l - 1; i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[l-1],count);
  
  return 0;
}

