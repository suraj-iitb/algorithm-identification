#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,n,a[100],cnt=0,minj,k,avoid;
  scanf("%d",&n);
  for(i=0; i < n; i++){
    scanf("%d",&a[i]);
  }
  for(j=0; j < n; j++){
    minj=j;
    for(k=j; k < n; k++){
    if(a[k] <  a[minj])minj=k;
    }
    if(a[j] > a[minj]){
      avoid=a[j];
      a[j]=a[minj];
      a[minj]=avoid;
      cnt++;
    }
  }
  for(i=0; i < n; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
  

