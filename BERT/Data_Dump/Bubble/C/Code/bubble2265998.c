#include <stdio.h>
void bubbleSort(int *A,int N);
int cnt=0;
int main(){

  int n,a[100],i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  bubbleSort(a,n);

  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",a[i]);
    }
    else {
      printf("%d ",a[i]);
    }

  }
 
  printf("%d\n",cnt);
  return 0;
  
}


void bubbleSort(int *a,int n){
  int j,flag=1,sub;

  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	sub=a[j];
	a[j]=a[j-1];
	a[j-1]=sub;
	cnt++;
	flag=1;
      }

    }
  }
}
  
      
