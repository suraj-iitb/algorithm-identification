#include <stdio.h>
#define N 100

int main(){
  int i,j,n,m,a[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  for(i=1;i<n;i++){
    m = a[i];
    j = i-1;
    while(j>=0 && a[j]>m){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = m;
    for(j=0;j<n;j++){
      if(j>0)printf(" ");
      printf("%d",a[j]);
    }
    printf("\n");
  }
  return 0;
}
	  
    

