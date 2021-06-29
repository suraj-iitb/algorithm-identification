#include<stdio.h>

void print(int a[],int n){
  int i,j;
  for(i=0;i<n;i++){
    if(i > 0){
      
      printf(" ");

    }
    printf("%d",a[i]);
    
  }
  printf("\n");
}


void insertionSort(int a[],int n){
  int i,e,j;
  
  for(i=1;i<n;i++){
    
    e=a[i];
    j=i-1;//j is 0;  

    while(j>=0&&a[j]>e){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=e;
    
   print(a,n); 
  }
 
}


int main(){

  int n,i;
  int a[100];

  scanf("%d",&n);
  
  if(n>=0&&n<=100){
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
    }

  }
  
  print(a,n);
  
  insertionSort(a,n);

  return 0;
  
}

