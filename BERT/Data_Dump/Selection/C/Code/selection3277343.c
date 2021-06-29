#include<stdio.h>
int main(){
  int i,j,n,temp,min;
  int a[100];
  int count=0;
  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=0; i<=n-1; i++){
    min=i;
    for(j=i; j<=n-1; j++){
      if(a[j]<a[min]){
	min=j;
      }
    }
      temp=a[i];
      a[i]=a[min];
      a[min]=temp;
      if(a[min]!=a[i]){
      count+=1;
      }

   
    }
  
  for(i=0; i<n; i++){
    if(i!=n-1){
      printf("%d ",a[i]);
    }
    else{
      printf("%d",a[i]);
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

