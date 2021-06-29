#include<stdio.h>
#include<stdlib.h>
 
int main(){
  int *a;
  int i,j,n,v,l;
 
  scanf("%d",&n);
 
  a=(int *)malloc(n*sizeof(int));
 
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
   
  for(j=0;j<n;j++){
    if(j!=n-1)
      printf("%d ",a[j]);
     
    else if(j==n-1)
      printf("%d",a[j]);
     
  }
   
  printf("\n");
 
  for(i=1;i<n;i++){
    v=a[i];
    j=i-1;
 
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
 
    a[j+1]=v;
 
    for(l=0;l<n;l++){
      if(l!=n-1)
    printf("%d ",a[l]);
       
      else if(l==n-1)
    printf("%d",a[l]);
       
    }
 
    printf("\n");
  }
 
  free(a);
 
  return 0;
}
