#include<stdio.h>
#include<stdlib.h>

int BubbleSort(int *,int );
void OutputData(int *,int );

int main(){

  int *a;
  int i,n,c;

  scanf("%d",&n);

  a=(int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  c=BubbleSort(a,n);
  OutputData(a,n);
  printf("%d\n",c);

  return 0;
}


int BubbleSort(int *a,int n){
  int i,j,tmp,c=0;

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j-1]>a[j]){
	tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	c++;
      }
    }
  }
  return c;
}
void OutputData(int *a, int n){
  int i;
  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%d " ,a[i]);
    }
    else{
      printf("%d",a[i]);
    }
  }
  printf("\n");
}

