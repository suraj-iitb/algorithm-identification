#include <stdio.h>
#define N 100
int main(){
  int n,a[N],v,i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  } for(i=0;i<n;i++){
      if(i)printf(" ");
      printf("%d",a[i]);
    }
  printf("\n");
  for(i=1;i<=n-1;i++){
    v = a[i];
    j = i - 1;
    while(j>=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
      a[j+1] = v;
    for(k=0;k<n;k++){
      if(k)printf(" ");
      printf("%d",a[k]);
    }
    printf("\n");
}
    return 0;
}

