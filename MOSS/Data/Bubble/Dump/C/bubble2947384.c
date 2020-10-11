#include<stdio.h>
#define N 100
int bubbleSort(int [],int);
int main(){
  int n=0,i,x[N],cnt=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  cnt=bubbleSort(x,n);

  printf("%d\n",cnt);
  
  return 0;
}

int bubbleSort(int a[],int b){
  int i,j,tmp;
  int on=1;
  int count=0;
  
  for(i=0;on;i++){
    on=0;
    for(j=b-1;j>0;j--){
      if(a[j]<a[j-1]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	on=1;
	count++;
      }
    }
  }
  printf("%d",a[0]);
  for(i=1;i<b;i++){
    printf(" %d",a[i]);
  }
  printf("\n");
  
  return count;
}

  
  
  

