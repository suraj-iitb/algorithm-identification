#include <stdio.h>

int main(){
  int n,i,j,flag,cnt=0,tmp;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  flag=1;
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){ 
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
        flag=1;
        cnt++;
      }
    }
  }
  for(i=0;i<n;i++){
     printf("%d",a[i]);
     if(i==n-1) printf("\n");
     else printf(" ");
  }
  printf("%d\n",cnt);

  return 0;
}
