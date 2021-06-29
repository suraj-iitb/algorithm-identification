#include<stdio.h>

int main(){
  int i,n,a[100],j,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %d",&a[i]);
  }
    for(j = 0;j<n;j++){
      printf("%d",a[j]);
      if(j + 1 != n) printf(" ");
      else printf("\n");
    }
  for(i=1;i<n;i++){
    for(j=i ; a[j]<a[j-1] && j!=0;j--) {
      tmp=a[j-1];
      a[j-1] = a[j]; 
      a[j] = tmp;
    }
    for(j = 0;j<n;j++){
      printf("%d",a[j]);
      if(j + 1 != n) printf(" ");
      else printf("\n");
    }
  }
return 0;
}

