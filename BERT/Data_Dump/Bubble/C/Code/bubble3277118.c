#include <stdio.h>

void bubbleSort(int *,int);

int main(){
  int i,n,a[100];
  scanf("%d",&n);
  if(n<1||n>100)fprintf(stderr,"ERRER\n");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
}


void bubbleSort(int *a,int n){
  int flag,count=0,x,i,j;
  flag=1;
  for(i=0;flag;i++){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
}
      
	
  

