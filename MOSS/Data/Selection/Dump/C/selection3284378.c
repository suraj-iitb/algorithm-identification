#include<stdio.h>
int main(){
  int i,j,minj,n,a[100],tmp,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      sum++;
    }
    tmp=a[i];
    a[i]=a[minj];
    a[minj]=tmp;
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i==n-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  printf("%d\n",sum);
}


