#include<stdio.h>
int main(){
  
  int i,j,k,v,N;
  int a[1000];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d\n",a[i]);
    }
    else{
      printf("%d ",a[i]);
    }
  }
  for(i=1;i<N;i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
    for(k=0;k<N;k++){    
      if(k==N-1){
	printf("%d\n",a[k]);
      }
      else{
	printf("%d ",a[k]);
      }
    }
  }
  return 0;
}

