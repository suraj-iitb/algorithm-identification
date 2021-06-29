#include<stdio.h>
int main(){
  int i,j,n,minj,temp,c=0,f;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    f=0;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
	f=1;
      }
    }
    if(f==1){
    temp=a[i];
    a[i]=a[minj];
    a[minj]=temp;
    c++;
    }
  }
    for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",c);
  return 0;
}

