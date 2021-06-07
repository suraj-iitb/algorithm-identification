#include <stdio.h>

int a[10500],n;

int linearSearch(int key){
  int i;
  
  a[n]=key;
  
  for(i=0; i<n; i++)
    if(key==a[i])
      return 1;

  return 0;
}

int main(){
  int count=0,i,q,b;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&b);
    if(linearSearch(b)==1)
      count++;
  }

  printf("%d\n",count);

  return 0;
}

  
  
      

  

