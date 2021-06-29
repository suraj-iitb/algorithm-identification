#include<stdio.h>
#define N 100

void bubbleSort(void);

int main(){

  bubbleSort();

  return 0;
}
void bubbleSort(void){
  int a[N];
  int n,i,j,flag,x,kazu=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	x=a[j];
	a[j]=a[j-1];
	a[j-1]=x;
	flag=1;
	kazu++;
      }
    }
    i++;
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",kazu);
}

