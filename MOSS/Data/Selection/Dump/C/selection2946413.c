#include<stdio.h>

int main(){
  int f,l,buf,count,i,j,k,minj,a[100];

  count = 0;

  scanf("%d",&l);
  for(j = 0; j < l; j++)
    scanf("%d",&a[j]);
  for(i = 0; i < l; i++){
    minj = i;
    f = 1;
      for(j = i; j < l; j++){
	if(a[j] < a[minj]){
	  minj = j;
	  if(f == 1){
	    count++;
	    f = 0;
	  }
	}
      }
      buf = a[i];
      a[i] = a[minj];
      a[minj] = buf;
  }
  
  for(i = 0; i < l - 1; i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[l - 1],count);
  
  return 0;
}

