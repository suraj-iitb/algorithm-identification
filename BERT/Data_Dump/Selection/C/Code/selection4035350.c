#include <stdio.h>
int main(){
  int i,n,minj,j,key,b,c=0;
  int a[100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    b=0;
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj = j;
	b++;
      }
    }
    
    key=a[i];
    a[i]=a[minj];
    a[minj]=key;
    if(b)c++;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d",a[n-1]);
  printf("\n%d\n",c);
  
  
  return 0;
}

