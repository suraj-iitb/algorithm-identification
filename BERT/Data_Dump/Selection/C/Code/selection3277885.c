#include<stdio.h>
#include<stdlib.h>

int  selectionSort(int *,int);
void print_dataset(int *,int);

int main(){
  int *array,n,i;
  int result;
  
  scanf("%d",&n);
  array=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  
  result=selectionSort(array,n);
  
  print_dataset(array,n);
  printf("%d\n",result);

  return 0;
}

int selectionSort(int *a,int n){
  int i,j,mini,stock,count=0;
  int flag=1;
  
  for(i=0;i<n;i++){
    mini=i;
    flag=1;
    for(j=i;j<n;j++){
      if(a[j]<a[mini]){
	mini=j;
	flag=0;
      }
    }
    
    if(flag==0){
    stock=a[i];
    a[i]=a[mini];
    a[mini]=stock;
    count++;
    }
 
  }

  return count;
}

void print_dataset(int *a,int n){
  int i;

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
}

