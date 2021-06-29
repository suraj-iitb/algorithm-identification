#include<stdio.h>

int main(){

  int n,i,a[100],minj,j,r,cnt=0,flag;
  
  scanf("%d",&n);
  for(i=0; i<n; i++)scanf("%d",&a[i]);

  for(i=0; i<n-1; i++){
    flag=0;
    minj=i;
    for(j=i; j<=n-1; j++){
      if(a[j]<a[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag){
    r=a[i];
    a[i]=a[minj];
    a[minj]=r;
    cnt++;
    }
  }

  for(i=0; i<n; i++){
    if(i)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

