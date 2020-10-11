#include<stdio.h>
#define MAX 2000001 
int main(){
  int i,n,*a,*b,c[10000],max=0;

  scanf("%d",&n);

  a=malloc(sizeof(int)*n+1);
  b=malloc(sizeof(int)*n+1);

  
  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i+1]);
    if(max<a[i+1])max=a[i+1];
  }

  for(i=0;i<=max+1;i++){
    c[i]=0;
  }

  for(i=0;i<=n-1;i++){
    c[a[i+1]]++;
  }

  for(i=1;i<=max+1;i++){
    c[i]=c[i]+c[i-1];
  }

  for(i=n;i>=0;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");

  return 0;
}
  
  

