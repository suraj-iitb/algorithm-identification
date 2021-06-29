#include <stdio.h>
int main(){
  int n, a[100], i, j, count=0, minj, b;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n-1; i++){
    minj=i;
    for(j=i; j<n; j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      count++;
    }
    b=a[i];
    a[i]=a[minj];
    a[minj] = b;
    
  }

  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], count);
  
  return 0;
}

