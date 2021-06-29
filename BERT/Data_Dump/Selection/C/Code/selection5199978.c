#include <stdio.h>

int main(){
  int i,j,tmp,cnt=0,n,minj,a[100];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    tmp=a[i];
    a[i]=a[minj];
    a[minj]=tmp;
    if(i!=minj)cnt++;
  }

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
  


