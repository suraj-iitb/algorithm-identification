#include<stdio.h>
int main(){
  int i,j,n,temp;
  int a[100];
  int count=0;
  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	count+=1;
      }
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
