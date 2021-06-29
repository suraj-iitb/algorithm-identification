#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a[n],i,b=1,c,count=0;
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  while(b){
    b=0;
    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
	c=a[i];
	a[i]=a[i-1];
	a[i-1]=c;
	b=1;
	count++;
      }
    }
  }

  printf("%d" ,a[0]);
  for(i=1;i<n;i++){
    printf(" %d"  ,a[i]);
  }
  
  printf("\n%d\n",count);

  return 0;
}

