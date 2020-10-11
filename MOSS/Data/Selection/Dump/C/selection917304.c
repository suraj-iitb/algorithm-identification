#include<stdio.h>
#define N 100

int main(void){
  int n,a[N],i,j,min,ch=0,sw;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++)if(a[j]<a[min])min=j;
    if(min!=i){
      sw=a[min];
      a[min]=a[i];
      a[i]=sw;
      ch++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",ch);
  
  return 0;
  
}
