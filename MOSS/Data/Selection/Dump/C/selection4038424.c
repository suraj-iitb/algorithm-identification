#include <stdio.h>

int main(){
    
  int a[100],n,i,j,minj,count=0,tmp;
    
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
    
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]) {
	minj=j;
      }  
    }
    tmp = a[i];
    a[i] =a[minj];
    a[minj]=tmp;
    if(i!=minj) count++;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",count);
}

