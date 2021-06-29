#include <stdio.h>
#define N 2000000
#define I 10000
int a[N+1],b[N+1],c[N+1];
main(){
  
  int n,i,j,k;
 
  scanf("%d",&n);
 
  
  for(i=0; i<n; i++){
    scanf("%d",&a[i+1]);
    if(a[i]<a[i+1])
      k=a[i];
  }
  
  for(i=0; i<n; i++)
    c[i]=0;
  
  
  for(i=0; i<n; i++)
    c[a[i+1]]++;
 
  
  for(i=0; i<N; i++)
    c[i+1]=c[i+1]+c[i];
  
  
  for(i=n; i>0; i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
  
  
  for(i=0; i<n-1; i++)
    printf("%d ",b[i+1]);
  printf("%d\n",b[n]);
  

  return 0;
}
