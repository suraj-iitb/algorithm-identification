#include <stdio.h>
#include <stdlib.h>
int main(){
  int n,c[10001];
  unsigned short *a,*b;
  int i,k=0;
  scanf("%d",&n);
  a = malloc(sizeof(short)*n+1);
  b = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(k<a[i]) k=a[i];
  }

  for(i=0;i<=k;i++)
    c[i]=0;
  
  for(i=0;i<n;i++)
    c[a[i]]++;

  for(i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];

  for(i=n-1;i>=0;i--){
    b[c[a[i]]]=a[i];
      c[a[i]]--;
  }
  
  for(i=1;i<n;i++)
    printf("%d ",b[i]);
  printf("%d\n",b[n]);
return 0;

}

