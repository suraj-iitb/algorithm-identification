#include <stdio.h>

int main(){

  int n,a[100],i,minj,j,sub,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(a[i]>a[minj]){
      sub=a[i];
      a[i]=a[minj];
      a[minj]=sub;
      cnt++;
    }
  }
  
  
  


  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",a[i]);
    }
    else {
      printf("%d ",a[i]);
    }
  }
  if(n==1){
    printf("0\n");
  }
  else {
    printf("%d\n",cnt);
  }
  return 0;
}
