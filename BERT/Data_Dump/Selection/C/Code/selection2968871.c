#include<stdio.h>
#include<stdlib.h>

int SelectionSort(int *,int );
void OutputData(int *,int);

int main(){

  int *a;
  int i,n,c;

  scanf("%d",&n);

  a=(int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  c=SelectionSort(a,n);
  OutputData(a,n);
  printf("%d\n",c);

  return 0;
}

int SelectionSort(int *a,int n){

  int i,j,min,tmp,c=0;

  for(i=0;i<n-1;i++){
    min=i;
    
    for(j=i+1;j<n;j++){
      if(a[j]<a[min]){
	min=j;
      }
    }
    if(a[i]>a[min]){
      tmp=a[i];
      a[i]=a[min];
      a[min]=tmp;
      c++;
    }
  }
  return c;
}

void OutputData(int *a,int n){

  int i;

  for(i=0;i<n;i++){
    if(i!=n-1){
      printf("%d ",a[i]);
    }
    else{
      printf("%d",a[i]);
    }
  }
  printf("\n");
}
	 
  

