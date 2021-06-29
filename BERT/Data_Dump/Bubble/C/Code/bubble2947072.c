#include<stdio.h>

int main(){
  int i=0,n,j,a[100],count=0,temp;
  int flag=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        temp = a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        flag=1;
        count++;
      }
    }
    i++;
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

