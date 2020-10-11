#include <stdio.h>

int main(){
  int n,i,j,c=0,f[100],minj,x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&f[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(f[j]<f[minj]){
	minj=j;
      }
    }
     if(f[i]>f[minj]){
        c++;
      }
	x=f[minj];
	f[minj]=f[i];
	f[i]=x;
  }
  for(i=0;i<n-1;i++){
    printf("%d ",f[i]);
  }
  printf("%d\n",f[n-1]);
  printf("%d\n",c);
  return 0;
}

