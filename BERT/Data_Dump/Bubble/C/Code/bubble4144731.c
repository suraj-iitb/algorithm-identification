#include<stdio.h>

void bubbleSort(int *,int);

int swap=0;

int main(){
  int i,n;
  int data[100];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&data[i]);

  bubbleSort(data,n);

  for(i=0;i<n-1;i++) printf("%d ",data[i]);
  printf("%d\n",data[i]);
  printf("%d\n",swap);

  return 0;

}

void bubbleSort(int *data,int n){
  int i,tmp,flag;

  flag=1;

  while(flag){
    flag=0;
    for(i=n-1;1<=i;i--){
      if(data[i]<data[i-1]){
	tmp=data[i];
	data[i]=data[i-1];
	data[i-1]=tmp;
	flag=1;
	swap++;
      }
    }
  }
}

