#include<stdio.h>

int count=0;

void selectionSort(int *,int);

int main(){
  int i,n,data[100];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&data[i]);

  selectionSort(data,n);

  for(i=0;i<n-1;i++) printf("%d ",data[i]);
  printf("%d\n",data[i]);
  printf("%d\n",count);

  return 0;

}

void selectionSort(int *data,int n){
  int i,j,min,tmp;
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(data[j]<data[min]) min=j;      
    }

    if(i!=min) count++;
    tmp=data[i];
    data[i]=data[min];
    data[min]=tmp;
  }

}

