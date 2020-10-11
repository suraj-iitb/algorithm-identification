#include <stdio.h>
#define N 100
int main(void){
  int n,i,j,c=0,s,f[N],flag=1,t,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&f[i]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(f[j]<f[j-1]){
	s=f[j-1];
	f[j-1]=f[j];
	f[j]=s;
	c++;
	flag=1;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",f[i]);
  }
  printf("%d\n",f[n-1]);
  printf("%d\n",c);
  return 0;
}

