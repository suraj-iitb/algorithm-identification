#include <stdio.h>
int main(){
  int flag,n,i,a[100],key,c;

  c=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  
  flag=1;
  while(flag){
    flag = 0;
    for(i=n-1;i>=1;i--){
      if(a[i]<a[i-1]){
	key = a[i];
	a[i] = a[i-1];
	a[i-1] = key;
	c++;
	flag=1;
      }
      
    
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[n-1]);
  printf("\n%d\n",c);
  
  return 0;
}

