#include<stdio.h>
int main(){
  int n,i,j,key,k;
  int a[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(j=0;j<n;j++){
    key=a[j];
    i=j-1;
    while(i>=0&&a[i]>key){
      a[i+1]=a[i];
      i=i-1;
      a[i+1]=key;
    }
    printf("%d",a[0]);
    for(k=1;k<n;k++){
      printf(" %d",a[k]);
    }
    printf("\n");
  }
  return 0;
}

