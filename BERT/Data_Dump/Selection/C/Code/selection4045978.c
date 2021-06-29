#include<stdio.h>
int main(){
  int N,a[100],i,j,t,k;
  int c=0,min;

  scanf("%d\n",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  //scaned----------
  
  for(i=0;i<N-1;i++){
    t=0;
    min=i;
    for(j=i;j<=N-1;j++){
      if(a[j]<a[min]){
	min=j;
	t=1; 
      }
    }
    if(t==1)c++;
    k=a[i];
    a[i]=a[min];
    a[min]=k;

  }
        
  for(i=0;i<N;i++){
    printf("%d",a[i]);
    if(i<N-1)printf(" ");
  }
  printf("\n%d\n",c);

  return 0;
}

