#include<stdio.h>
int main(){
  int N,i,T=100,m,count=0,flag=1;
  scanf("%d",&N);
  int a[N];
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
}
  while(flag){
    flag=0;
  for(i=0;i<N-1;i++){
    if(a[i]>a[i+1]){
      m=a[i];
      a[i]=a[i+1];
      a[i+1]=m;
      count++;
      flag=1;
    }
  }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",a[i]);
    
}
  printf("%d",a[N-1]);
   printf("\n");
    printf("%d\n",count);
}
    
    

