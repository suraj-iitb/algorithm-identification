#include<stdio.h>

int main(){
  int i,n,a[100],count=0,minj,temp,j;
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
    temp = a[i];
    a[i]=a[minj];
    a[minj]=temp;
    if(i!=minj){
      count++;
    }
  }
    for(i=0;i<n;i++){
      if(i<n-1){
        printf("%d ",a[i]);
      }
      else{
        printf("%d\n",a[i]);
      }
    }
    printf("%d\n",count);
    return 0;
}

