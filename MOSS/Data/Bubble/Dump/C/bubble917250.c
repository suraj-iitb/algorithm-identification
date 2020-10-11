#include <stdio.h>
#define N 100

int main(void){
  
  int i,j,n,a[N],ch=0,sw;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	sw=a[j];
	a[j]=a[j-1];
	a[j-1]=sw;
	ch++;
      }
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
